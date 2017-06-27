/*
** sgt.c for zappy in PSU_2016_zappy/server/src/graphic_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 20:01:51 2017 Antoine Baché
** Last update Tue Jun 27 21:25:25 2017 Antoine Baché
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

void	zappy_graph_sgt(t_zappy_client * const cli,
			t_zappy *data,
			char const * const arg)
{
  t_zappy_message	*msg;
  char			buff[4096];

  (void)data;
  (void)arg;
  LOG(LOG_DEBUG, "Treating graphic sgt command");
  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = snprintf(buff, sizeof(buff), "sgt %d\n", data->conf.freq);
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
