/*
** connect_w.c for zappy in PSU_2016_zappy/server/src/state
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 30 12:07:39 2017 Antoine Baché
** Last update Sun Jul  2 14:39:29 2017 Antoine Baché
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
#include "zappy_team.h"

static void		zappy_cli_state_conn_w_fail(t_zappy_client *
						    const cli,
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

static void		zappy_cli_state_conn_egg(t_zappy_client * const cli,
						 t_zappy * const data)
{
  t_zappy_egg		*egg;
  t_zappy_graph_arg	g;

  LOG(LOG_INFO, "Connecting thanks to an egg");
  egg = zappy_get_egg_from_team(data, cli->game.team_id);
  assert(egg);
  if (egg)
    {
      cli->game.y = egg->y;
      cli->game.x = egg->x;
      --data->egg_manager.nb_eggs;
      --data->egg_manager.nb_hatched_eggs;
      g = (t_zappy_graph_arg){ NULL, egg->id, 0 };
      zappy_graph_send(&g, data, NULL, &zappy_graph_ebo);
      zappy_remove_egg(data, egg);
    }
}

static void		zappy_cli_state_conn_noegg(t_zappy_client * const cli,
						   t_zappy * const data,
						   char const * buff)
{
  t_zappy_graph_arg	g;

  ++data->map.data[cli->game.y][cli->game.x].nb_players;
  data->map.data[cli->game.y][cli->game.x].player[cli->id] = &cli->game;
  LOG(LOG_INFO, "Spawning player at %dx%d", cli->game.x, cli->game.y);
  g = (t_zappy_graph_arg){ cli, 0, 0 };
  zappy_graph_send(&g, data, buff, &zappy_graph_pnw);
  cli->authenticated = true;
  zappy_has_player(data);
}

static void		zappy_cli_state_conn_w_(t_zappy_client * const cli,
						t_zappy * const data,
						t_zappy_message *cur,
						int32_t const ret)
{
  char			buff[512];

  if (ret != -1)
    {
      cur->len = snprintf(buff, sizeof(buff) - 1, "%d\n%d %d\n", ret,
			  data->conf.world_width, data->conf.world_height);
      if (cur->len != -1)
	cur->msg = strdup(buff);
      if (cur->msg)
	{
	  if (data->conf.teams.team[cli->game.team_id].nb_players >
	      data->conf.nb_client_per_team &&
	      zappy_get_number_hatched_eggs(data, cli->game.team_id) > 0)
	    {
	      zappy_cli_state_conn_egg(cli, data);
	    }
	  zappy_cli_state_conn_noegg(cli, data, buff);
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
