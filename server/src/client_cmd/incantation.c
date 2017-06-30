/*
** incantation.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:29:34 2017 Antoine Baché
** Last update Fri Jun 30 16:36:39 2017 Antoine Baché
*/

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "cqueue.h"
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_client_game.h"
#include "zappy_client_cmd.h"
#include "zappy_elevation.h"
#include "zappy_message.h"
#include "zappy_graphic.h"

static void		zappy_client_elevation_msg(t_zappy_client * const cli,
						   t_zappy * const data)
{
  t_zappy_message	*msg;
  char			buff[4096];

  msg = zappy_alloc_message();
  if (msg)
    {
      zappy_player_level_up(&cli->game, data);
      msg->len = snprintf(buff, sizeof(buff), "Current level: %d\n",
			  cli->game.level);
      if (msg->len != -1)
	msg->msg = strdup(buff);
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	  return ;
	}
      free(msg->msg);
      zappy_free_message(msg);
    }
}

static bool		zappy_client_elevation(t_zappy_client * const cli,
					       t_zappy * const data)
{
  int32_t		max;
  int32_t		i;
  t_zappy_client_game	*cur;
  t_zappy_client	*cur_cli;
  t_zappy_graph_arg	g;

  if (!zappy_elevation_check(cli, data))
    return (false);
  zappy_elevation_end_inv(&cli->game, data);
  max = zappy_get_max_player(data);
  g = (t_zappy_graph_arg){ cli, 0, true };
  zappy_graph_send(&g, data, NULL, &zappy_graph_pie);
  i = -1;
  while (++i < max)
    if ((cur = data->map.data[cli->game.y][cli->game.x].player[i]))
      {
	cur_cli = (t_zappy_client *)((uintptr_t)cur -
				     offsetof(t_zappy_client, game));
	zappy_client_elevation_msg(cur_cli, data);
	g = (t_zappy_graph_arg){ cur_cli, 0, 0 };
	zappy_graph_send(&g, data, NULL, &zappy_graph_plv);
	g.ptr = &data->map.data[cli->game.y][cli->game.x];
	zappy_graph_send(&g, data, NULL, &zappy_graph_bct);
      }
  return (true);
}

void			zappy_client_cmd_incantation(t_zappy_client *
						     const cli,
						     t_zappy * const data,
						     char const * const arg)
{
  t_zappy_message	*msg;
  t_zappy_graph_arg	g;

  LOG(LOG_DEBUG, "Treating incantation command");
  if (!zappy_client_elevation(cli, data))
    {
      msg = zappy_alloc_message();
      if (msg)
	{
	  msg->len = sizeof("ko\n");
	  msg->msg = strdup("ko\n");
	  if (msg->msg && cqueue_push(&cli->output_queue, msg))
	    {
	      g = (t_zappy_graph_arg){ cli, 0, false };
	      zappy_graph_send(&g, data, arg, &zappy_graph_pie);
	      cli->state = CLI_RESPONSE;
	      cli->can_write = true;
	      return ;
	    }
	  free(msg->msg);
	  zappy_free_message(msg);
	}
    }
}
