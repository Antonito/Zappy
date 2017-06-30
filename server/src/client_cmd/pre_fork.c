/*
** pre_fork.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 30 12:17:53 2017 Antoine Baché
** Last update Fri Jun 30 12:21:12 2017 Antoine Baché
*/

#include <assert.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_client_cmd.h"

void		zappy_client_pre_fork(t_zappy_client * const cli,
				      t_zappy * const data)
{
  assert(cli && data);
  LOG(LOG_DEBUG, "Treating pre fork");
  (void)cli, (void)data;
}
