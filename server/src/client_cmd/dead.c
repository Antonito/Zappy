/*
** dead.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:50:08 2017 Antoine Baché
** Last update Wed Jun 28 15:51:45 2017 Antoine Baché
*/

#include <stdlib.h>
#include <string.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_client_cmd.h"
#include "zappy_network.h"
#include "zappy_graphic.h"

void			zappy_client_cmd_dead(t_zappy_client * const cli,
					      t_zappy * const data,
					      char const * const arg)
{
  t_zappy_graph_arg	g;

  (void)arg;
  (void)data;
  LOG(LOG_DEBUG, "Treating dead command");
  zappy_network_write(&cli->net, "dead\n", sizeof("dead\n") - 1);
  g = (t_zappy_graph_arg){ cli, 0, 0 };
  zappy_graph_send(&g, data, NULL, &zappy_graph_pdi);
  cli->state = CLI_RESPONSE;
  cli->can_write = true;
  cli->connected = false;
}
