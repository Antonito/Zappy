/*
** sbp.c for zappy in PSU_2016_zappy/server/src/graphic_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 20:01:51 2017 Antoine Baché
** Last update Tue Jun 27 21:37:10 2017 Antoine Baché
*/

#include <string.h>
#include <stdlib.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_graphic.h"
#include "zappy_message.h"

void			zappy_graph_sbp(t_zappy_client * const cli,
					t_zappy *data,
					char const * const arg)
{
  t_zappy_message	*msg;

  (void)data;
  (void)arg;
  LOG(LOG_DEBUG, "Treating graphic sbp command");
  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = sizeof("sbp\n") - 1;
      msg->msg = strdup("sbp\n");
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	}
      free(msg->msg);
      zappy_free_message(msg);
    }
}
