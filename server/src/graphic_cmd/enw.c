/*
** enw.c for zappy in PSU_2016_zappy/server/src/graphic_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 20:01:51 2017 Antoine Baché
** Last update Sat Jul  1 11:20:42 2017 Antoine Baché
*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_egg.h"
#include "zappy_graphic.h"
#include "zappy_message.h"

static void		zappy_graph_enw_fill(t_zappy_message * const msg,
					     t_zappy_graph_arg * const g)
{
  char			buff[4096];
  t_zappy_egg		*egg;

  assert(msg && g && g->ptr);
  egg = g->ptr;
  msg->len = snprintf(buff, sizeof(buff),
		      "enw %d %d %d %d\n",
		      egg->id, egg->player_id, egg->x, egg->y);
  if (msg->len != -1)
    msg->msg = strdup(buff);
}

void			zappy_graph_enw(t_zappy_client * const cli,
					t_zappy_graph_arg *g,
					t_zappy *data,
					char const * const arg)
{
  t_zappy_message	*msg;

  LOG(LOG_DEBUG, "Treating graphic enw command");
  (void)data;
  (void)arg;
  msg = zappy_alloc_message();
  if (msg)
    {
      zappy_graph_enw_fill(msg, g);
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	  return ;
	}
      zappy_free_message(msg);
    }
}
