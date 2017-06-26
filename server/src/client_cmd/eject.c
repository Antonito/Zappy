/*
** eject.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:29:34 2017 Antoine Baché
** Last update Sun Jun 25 12:35:43 2017 Antoine Baché
*/

#include "clogger.h"
#include "zappy.h"
#include "zappy_client.h"
#include "zappy_client_cmd.h"

void		zappy_client_cmd_eject(t_zappy_client * const cli,
				       t_zappy * const data,
				       char const * const arg)
{
  LOG(LOG_DEBUG, "Treating eject command");
  (void)cli, (void)data, (void)arg;
}
