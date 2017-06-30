/*
** eject.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:29:34 2017 Antoine Baché
** Last update Fri Jun 30 16:36:19 2017 Antoine Baché
*/

#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "cqueue.h"
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_client_cmd.h"
#include "zappy_graphic.h"
#include "zappy_message.h"

static void			zappy_client_eject_msg(t_zappy_client *
						       const cli,
						       int32_t ori)
{
  t_zappy_message		*msg;
  char				buff[512];

  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = snprintf(buff, sizeof(buff), "eject: %d\n",
			  ((ori + 2) % 4) + 1);
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

static void			zappy_client_eject_all(t_zappy_client *
						       const cli,
						       t_zappy * const data)
{
  t_zappy_graph_arg		g;
  int32_t			i;
  t_zappy_client_game		*cur;
  t_zappy_client		*cur_cli;
  t_zappy_client_orientation	ori;

  g = (t_zappy_graph_arg){ cli, 0, 0 };
  i = 0;
  while (i < data->map.data[cli->game.y][cli->game.x].nb_players)
    {
      cur = data->map.data[cli->game.y][cli->game.x].player[i];
      if (cur && cur != &cli->game)
	{
	  cur_cli = (t_zappy_client *)(((uintptr_t)cur) -
				       offsetof(t_zappy_client, game));
	  zappy_client_eject_msg(cur_cli, cli->game.orientation);
	  ori = cur->orientation;
	  cur->orientation = cli->game.orientation;
	  zappy_client_forward(cur, cur_cli->id, &data->map);
	  cur->orientation = ori;
	  g = (t_zappy_graph_arg){ cur_cli, 0, 0 };
	  zappy_graph_send(&g, data, NULL, &zappy_graph_ppo);
	}
      ++i;
    }
}

void			zappy_client_cmd_eject(t_zappy_client * const cli,
					       t_zappy * const data,
					       char const * const arg)
{
  t_zappy_message	*msg;
  t_zappy_graph_arg	g;

  LOG(LOG_DEBUG, "Treating eject command");
  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = sizeof("ko\n") - 1;
      if (data->map.data[cli->game.y][cli->game.x].nb_players > 1)
	msg->msg = strdup("ok\n");
      else
	msg->msg = strdup("ko\n");
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  g = (t_zappy_graph_arg){ cli, 0, 0 };
	  zappy_graph_send(&g, data, arg, &zappy_graph_pex);
	  zappy_client_eject_all(cli, data);
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	  return ;
	}
      free(msg->msg);
      zappy_free_message(msg);
    }
}
