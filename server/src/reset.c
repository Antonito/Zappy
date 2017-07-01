/*
** reset.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Thu Jun 29 16:29:53 2017 Antoine Baché
** Last update Thu Jun 29 16:43:37 2017 Antoine Baché
*/

#include <assert.h>
#include <string.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_cleanup.h"
#include "zappy_team_manager.h"

void	zappy_reset(t_zappy * const data)
{
  assert(data);
  LOG(LOG_INFO, "Reseting game");
  zappy_cleanup_config(&data->conf);
  zappy_cleanup_socket(&data->net);
  zappy_cleanup_multiplexer(&data->multiplex);
  zappy_cleanup_clients(&data->clients);
  zappy_cleanup_map(&data->map);
  zappy_cleanup_admin(&data->admin);
  memset(data, 0, sizeof(*data));
}
