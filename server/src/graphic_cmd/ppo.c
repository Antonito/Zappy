/*
** ppo.c for zappy in PSU_2016_zappy/server/src/graphic_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 20:01:51 2017 Antoine Baché
** Last update Wed Jun 28 00:35:10 2017 Antoine Baché
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_graphic.h"
#include "zappy_message.h"

// TODO: norme
void			zappy_graph_ppo(t_zappy_client * const cli,
					t_zappy_graph_arg *g,
					t_zappy *data,
					char const * const arg)
{
  t_zappy_message	*msg;
  char			buff[4096];
  t_zappy_client	*p;

  (void)data;
  (void)arg;
  LOG(LOG_DEBUG, "Treating graphic ppo command");
  p = g->ptr;
  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = snprintf(buff, sizeof(buff),
			  "ppo %d %d %d %d\n", p->id,
			  p->game.x, p->game.y,
			  p->game.orientation + 1);
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
