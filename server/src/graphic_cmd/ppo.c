/*
** ppo.c for zappy in PSU_2016_zappy/server/src/graphic_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 20:01:51 2017 Antoine Baché
** Last update Fri Jun 30 16:38:35 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_graphic.h"
#include "zappy_message.h"

static void		zappy_graph_ppo_fill(t_zappy_message * const msg,
					     t_zappy_client * const p)
{
  char			buff[4096];

  assert(msg && p);
  msg->len = snprintf(buff, sizeof(buff),
		      "ppo %d %d %d %d\n", p->id,
		      p->game.x, p->game.y,
		      p->game.orientation + 1);
  if (msg->len != -1)
    msg->msg = strdup(buff);
}

void			zappy_graph_ppo(t_zappy_client * const cli,
					t_zappy_graph_arg *g,
					t_zappy *data,
					char const * const arg)
{
  t_zappy_message	*msg;

  (void)data;
  (void)arg;
  assert(cli && g);
  LOG(LOG_DEBUG, "Treating graphic ppo command");
  msg = zappy_alloc_message();
  if (msg)
    {
      zappy_graph_ppo_fill(msg, g->ptr);
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
