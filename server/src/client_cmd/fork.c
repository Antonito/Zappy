/*
** fork.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:29:34 2017 Antoine Baché
** Last update Fri Jun 30 16:36:31 2017 Antoine Baché
*/

#include <string.h>
#include <stdlib.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_client_cmd.h"
#include "zappy_graphic.h"
#include "zappy_message.h"

static void		zappy_client_post_fork(t_zappy_client * const cli,
					       t_zappy * const data)
{
  t_zappy_graph_arg	g;

  (void)cli;
  (void)data;
  (void)g;
  // TODO: add egg
  // TODO: enw
}

void			zappy_client_cmd_fork(t_zappy_client * const cli,
					      t_zappy * const data,
					      char const * const arg)
{
  t_zappy_message	*msg;

  (void)arg;
  LOG(LOG_DEBUG, "Treating fork command");
  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = sizeof("ok\n") - 1;
      msg->msg = strdup("ok\n");
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  zappy_client_post_fork(cli, data);
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	  return ;
	}
      free(msg->msg);
      zappy_free_message(msg);
    }
}
