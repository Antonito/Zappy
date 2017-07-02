/*
** pnw.c for zappy in PSU_2016_zappy/server/src/graphic_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 20:01:51 2017 Antoine Baché
** Last update Sat Jul  1 11:24:33 2017 Antoine Baché
*/

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_graphic.h"
#include "zappy_message.h"

static void		zappy_graph_pnw_fill(t_zappy_message * const msg,
					     t_zappy_client * const p)
{
  char			buff[4096];

  assert(msg && p);
  msg->len = snprintf(buff, sizeof(buff),
		      "pnw %d %d %d %d %d %s\n", p->id,
		      p->game.x, p->game.y, p->game.orientation + 1,
		      p->game.level, p->game.team_name);
  if (msg->len != -1)
    {
      msg->msg = strdup(buff);
    }
}

void			zappy_graph_pnw(t_zappy_client * const cli,
					t_zappy_graph_arg *g,
					t_zappy *data,
					char const * const arg)
{
  t_zappy_message	*msg;
  t_zappy_client	*p;

  LOG(LOG_DEBUG, "Treating graphic pnw command");
  (void)data;
  (void)arg;
  p = g->ptr;
  if (p->graphical || !p->game.team_name)
    return ;
  msg = zappy_alloc_message();
  if (msg)
    {
      zappy_graph_pnw_fill(msg, p);
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	  return ;
	}
      zappy_free_message(msg);
    }
}
