/*
** pin.c for zappy in PSU_2016_zappy/server/src/graphic_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 20:01:51 2017 Antoine Baché
** Last update Wed Jun 28 00:29:17 2017 Antoine Baché
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_graphic.h"
#include "zappy_message.h"

// TODO: norme
void			zappy_graph_pin(t_zappy_client * const cli,
					t_zappy_graph_arg *g,
					t_zappy *data,
					char const * const arg)
{
  t_zappy_message	*msg;
  char			buff[4096];
  t_zappy_client	*p;

  (void)data;
  (void)arg;
  LOG(LOG_DEBUG, "Treating graphic pin command");
  if ((p = g->ptr) && (msg = zappy_alloc_message()))
    {
      msg->len =
	snprintf(buff, sizeof(buff), "pin %d %d %d %d %d %d %d %d %d %d\n",
		 p->id, p->game.x, p->game.y, p->game.inv[RES_FOOD],
		 p->game.inv[RES_LINEMATE], p->game.inv[RES_DERAUMERE],
		 p->game.inv[RES_SIBUR], p->game.inv[RES_MENDIANE],
		 p->game.inv[RES_PHIRAS], p->game.inv[RES_THYSTAME]);
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
