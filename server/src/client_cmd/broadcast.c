/*
** broadcast.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:29:34 2017 Antoine Baché
** Last update Tue Jun 27 22:23:17 2017 Antoine Baché
*/

#include "clogger.h"
#include "zappy.h"
#include "zappy_client.h"
#include "zappy_client_cmd.h"
#include "zappy_graphic.h"

void		zappy_client_cmd_broadcast(t_zappy_client * const cli,
					   t_zappy * const data,
					   char const * const arg)
{
  LOG(LOG_DEBUG, "Treating broadcast \'%s\' command", arg);
  (void)cli, (void)data, (void)arg;
}
