/*
** client_utils.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 13:30:08 2017 Antoine Baché
** Last update Sun Jun 25 13:30:45 2017 Antoine Baché
*/

#include "clogger.h"
#include "zappy.h"
#include "zappy_client.h"

void		zappy_client_print(t_zappy_client const * const cli,
				   char const * const msg)
{
  (void)cli;
  (void)msg;
  LOG(LOG_INFO, "%s #%d: %s", msg, cli->id,
      inet_ntoa(cli->net.addr.sin_addr));
}
