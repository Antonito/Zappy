/*
** bct.c for zappy in PSU_2016_zappy/server/src/graphic_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 20:01:51 2017 Antoine Baché
** Last update Sat Jul  1 02:37:36 2017 Antoine Baché
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cqueue.h"
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_graphic.h"
#include "zappy_message.h"

static void		zappy_graph_bct_fill(t_zappy_message * const msg,
					     t_zappy_map_case * const c)
{
  char			buff[4096];

  assert(msg && c);
  msg->len = snprintf(buff, sizeof(buff),
		      "bct %d %d %d %d %d %d %d %d %d\n",
		      c->x, c->y, c->content[RES_FOOD],
		      c->content[RES_LINEMATE], c->content[RES_DERAUMERE],
		      c->content[RES_SIBUR], c->content[RES_MENDIANE],
		      c->content[RES_PHIRAS], c->content[RES_THYSTAME]);
  if (msg->len != -1)
    msg->msg = strdup(buff);
}

void			zappy_graph_bct(t_zappy_client * const cli,
					t_zappy_graph_arg *g,
					t_zappy *data,
					char const * const arg)
{
  t_zappy_message	*msg;

  LOG(LOG_DEBUG, "Treating graphic bct command");
  (void)data;
  (void)arg;
  msg = zappy_alloc_message();
  if (msg)
    {
      zappy_graph_bct_fill(msg, g->ptr);
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	  return ;
	}
      zappy_free_message(msg);
    }
}
