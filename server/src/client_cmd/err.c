/*
** err.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:50:08 2017 Antoine Baché
** Last update Fri Jun 30 16:36:23 2017 Antoine Baché
*/

#include <stdlib.h>
#include <string.h>
#include "cqueue.h"
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_client_cmd.h"
#include "zappy_message.h"

void			zappy_client_cmd_err(t_zappy_client * const cli,
					     t_zappy * const data,
					     char const * const arg)
{
  t_zappy_message	*msg;

  (void)arg;
  (void)data;
  LOG(LOG_DEBUG, "Treating invalid/unkown command");
  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = sizeof("ko\n") - 1;
      msg->msg = strdup("ko\n");
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
