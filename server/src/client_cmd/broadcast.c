/*
** broadcast.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:29:34 2017 Antoine Baché
** Last update Fri Jun 30 16:36:04 2017 Antoine Baché
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cqueue.h"
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_client_cmd.h"
#include "zappy_client_list.h"
#include "zappy_graphic.h"
#include "zappy_broadcast.h"
#include "zappy_message.h"

static void		zappy_client_broadcast_msg(t_zappy_client * const cli,
						   int32_t const from,
						   char const * const arg)
{
  t_zappy_message	*msg;
  char			buff[4096];

  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = snprintf(buff, sizeof(buff), "message %d, %s\n",
			  from, arg);
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

static void		zappy_client_broadcast(t_zappy_client * const cli,
					       void * _data)
{
  t_zappy_broadcast	*bd;
  int32_t		from;

  bd = _data;
  if (cli->graphical || bd->cli == cli)
    return ;
  from = zappy_broadcast_calc(bd->cli, cli, bd->data->map.width,
			      bd->data->map.height);
  zappy_client_broadcast_msg(cli, from, bd->arg);
}

static void		zappy_client_cmd_broadcast_all(t_zappy_client * const
						       cli,
						       t_zappy * const data,
						       char const * const arg)
{
  t_zappy_broadcast	bd;

  bd = (t_zappy_broadcast){ data, cli, arg };
  _zappy_for_each_client(&data->clients, &bd, &zappy_client_broadcast);
}

void			zappy_client_cmd_broadcast(t_zappy_client * const cli,
						   t_zappy * const data,
						   char const * const arg)
{
  t_zappy_message	*msg;
  t_zappy_graph_arg	g;

  (void)arg;
  (void)data;
  LOG(LOG_DEBUG, "Treating broadcast \'%s\' command", arg);
  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = sizeof("ok\n") - 1;
      msg->msg = strdup("ok\n");
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  zappy_client_cmd_broadcast_all(cli, data, arg);
	  g = (t_zappy_graph_arg){ cli, 0, 0 };
	  zappy_graph_send(&g, data, arg, &zappy_graph_pbc);
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	  return ;
	}
      free(msg->msg);
      zappy_free_message(msg);
    }
}
