/*
** eht.c for zappy in PSU_2016_zappy/server/src/graphic_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 20:01:51 2017 Antoine Baché
** Last update Sat Jul  1 02:38:46 2017 Antoine Baché
*/

#include <stdio.h>
#include <string.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_graphic.h"
#include "zappy_message.h"

static void		zappy_graph_eht_fill(t_zappy_message * const msg,
					     int32_t const egg_id)
{
  char			buff[4096];

  msg->len = snprintf(buff, sizeof(buff), "eht %d\n", egg_id);
  if (msg->len != -1)
    {
      msg->msg = strdup(buff);
    }
}

void			zappy_graph_eht(t_zappy_client * const cli,
					t_zappy_graph_arg *g,
					t_zappy *data,
					char const * const arg)
{
  t_zappy_message	*msg;

  LOG(LOG_DEBUG, "Treating graphic eht command");
  (void)data;
  (void)arg;
  msg = zappy_alloc_message();
  if (msg)
    {
      zappy_graph_eht_fill(msg, g->res);
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	  return ;
	}
      zappy_free_message(msg);
    }
}
