/*
** bct.c for zappy in PSU_2016_zappy/server/src/graphic_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 20:01:51 2017 Antoine Baché
** Last update Tue Jun 27 20:38:48 2017 Antoine Baché
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_graphic.h"
#include "zappy_message.h"

void			zappy_graph_bct(t_zappy_client * const cli,
					t_zappy_map_case const * const c,
					t_zappy *data,
					char const * const arg)
{
  t_zappy_message	*msg;
  char			buff[4096];

  LOG(LOG_DEBUG, "Treating graphic bct command");
  (void)data;
  (void)arg;
  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = snprintf(buff, sizeof(buff),
			  "bct %d %d %d %d %d %d %d %d %d\n",
			  c->x, c->y, c->content[RES_FOOD],
			  c->content[RES_LINEMATE], c->content[RES_DERAUMERE],
			  c->content[RES_SIBUR], c->content[RES_MENDIANE],
			  c->content[RES_PHIRAS], c->content[RES_THYSTAME]);
      if (msg->len != -1)
	msg->msg = strdup(buff);
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	}
      free(msg->msg);
      zappy_free_message(msg);
    }
}
