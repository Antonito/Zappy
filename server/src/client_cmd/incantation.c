/*
** incantation.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:29:34 2017 Antoine Baché
** Last update Thu Jun 29 17:51:43 2017 Antoine Baché
*/

#include "clogger.h"
#include "zappy.h"
#include "zappy_client.h"
#include "zappy_client_cmd.h"

void		zappy_client_cmd_incantation(t_zappy_client * const cli,
					     t_zappy * const data,
					     char const * const arg)
{
  (void)arg;
  (void)data;
  (void)cli;
  LOG(LOG_DEBUG, "Treating incantation command");
  zappy_player_level_up(&cli->game, data);
}
