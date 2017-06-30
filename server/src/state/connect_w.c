/*
** connect_w.c for zappy in PSU_2016_zappy/server/src/state
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 30 12:07:39 2017 Antoine Baché
** Last update Fri Jun 30 21:16:13 2017 Antoine Baché
*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client_state.h"
#include "zappy_graphic.h"
#include "zappy_message.h"

static void		zappy_cli_state_conn_w_fail(t_zappy_client * const cli,
						    t_zappy_message * const
						    data,
						    t_zappy * zap)
{
  assert(cli && data && zap);
  if (cli->graphical)
    {
      zappy_graph_connect(cli, zap);
      cli->can_write = false;
      cli->authenticated = true;
      return ;
    }
  data->len = sizeof("ko\n") - 1;
  data->msg = strdup("ko\n");
  cli->connected = false;
  cli->state = CLI_AUTHENTICATING;
}

static void		zappy_cli_state_conn_w_(t_zappy_client * const cli,
						t_zappy * const data,
						t_zappy_message *cur,
						int32_t const ret)
{
  t_zappy_graph_arg	g;
  char			buff[512];

  if (ret != -1)
    {
      cur->len = snprintf(buff, sizeof(buff) - 1, "%d\n%d %d\n", ret,
			  data->conf.world_width, data->conf.world_height);
      if (cur->len != -1)
	cur->msg = strdup(buff);
      if (cur->msg)
	{
	  ++data->map.data[cli->game.y][cli->game.x].nb_players;
	  data->map.data[cli->game.y][cli->game.x].player[cli->id] = &cli->game;
	  LOG(LOG_INFO, "Spawning player at %dx%d", cli->game.x, cli->game.y);
	  g = (t_zappy_graph_arg){ cli, 0, 0 };
	  zappy_graph_send(&g, data, buff, &zappy_graph_pnw);
	  cli->authenticated = true;
	  zappy_has_player(data);
	  return ;
	}
    }
  cur->msg = NULL;
  cli->connected = false;
}

void			zappy_cli_state_conn_w(t_zappy_client * const cli,
					       t_zappy * const data)
{
  t_zappy_message	*cur;
  int32_t		ret;

  if ((cur = zappy_alloc_message()))
    {
      ret = zappy_team_manager_add_client(cli->game.team_name, cli,
					  &data->conf.teams);
      if (!cli->graphical)
	zappy_cli_state_conn_w_(cli, data, cur, ret);
      else
	zappy_cli_state_conn_w_fail(cli, cur, data);
      if (cur->msg && cqueue_push(&cli->output_queue, cur))
	{
	  cli->can_write = false;
	  return ;
	}
      zappy_free_message(cur);
      if (cli->graphical)
	return ;
    }
  cli->can_write = false;
  cli->connected = false;
  cli->state = CLI_AUTHENTICATING;
}
