/*
** take.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:29:34 2017 Antoine Baché
** Last update Fri Jun 30 16:37:13 2017 Antoine Baché
*/

#include <stdlib.h>
#include <string.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_client_cmd.h"
#include "zappy_message.h"
#include "zappy_resource.h"
#include "zappy_graphic.h"

static int32_t		zappy_client_cmd_take_check(t_zappy_client *
						    const cli,
						    t_zappy_resource
						    const res,
						    t_zappy *
						    const data,
						    t_zappy_message *
						    const msg)
{
  int32_t		x;
  int32_t		y;

  x = cli->game.x;
  y = cli->game.y;
  if (data->map.data[y][x].content[res] <= 0)
    return (1);
  --data->map.data[y][x].content[res];
  ++cli->game.inv[res];
  msg->len = sizeof("ok\n") - 1;
  msg->msg = strdup("ok\n");
  zappy_resource_spawn(res, &data->map);
  return (0);
}

static void		zappy_client_take_graph(t_zappy_client * const cli,
						t_zappy * const data,
						char const * const arg,
						t_zappy_resource res)
{
  t_zappy_graph_arg	g;

  g = (t_zappy_graph_arg){ cli, res, 0 };
  zappy_graph_send(&g, data, arg, &zappy_graph_pgt);
  zappy_graph_send(&g, data, arg, &zappy_graph_pin);
  g = (t_zappy_graph_arg){ &data->map.data[cli->game.y][cli->game.x],
			   res, 0 };
  zappy_graph_send(&g, data, arg, &zappy_graph_bct);
}

void			zappy_client_cmd_take(t_zappy_client * const cli,
					      t_zappy * const data,
					      char const * const arg)
{
  t_zappy_message	*msg;
  t_zappy_resource	res;

  LOG(LOG_DEBUG, "Treating take '%s' command", arg);
  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = sizeof("ko\n") - 1;
      res = zappy_get_resource_by_name(arg);
      if (res == RES_UNKNOWN ||
	  zappy_client_cmd_take_check(cli, res, data, msg))
	msg->msg = strdup("ko\n");
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  zappy_client_take_graph(cli, data, arg, res);
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	  return ;
	}
      free(msg->msg);
      zappy_free_message(msg);
    }
}
