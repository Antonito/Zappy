/*
** dead.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:50:08 2017 Antoine Baché
** Last update Thu Jun 29 11:36:25 2017 Antoine Baché
*/

#include <stdlib.h>
#include <string.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_client_cmd.h"
#include "zappy_network.h"

void			zappy_client_cmd_dead(t_zappy_client * const cli,
					      t_zappy * const data,
					      char const * const arg)
{
  (void)arg;
  (void)data;
  LOG(LOG_DEBUG, "Treating dead command");
  zappy_network_write(&cli->net, "dead\n", sizeof("dead\n") - 1);
  cli->state = CLI_RESPONSE;
  cli->can_write = true;
  cli->connected = false;
}
