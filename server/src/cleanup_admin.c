/*
** cleanup_admin.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 19:32:28 2017 Antoine Baché
** Last update Fri Jun 30 16:48:10 2017 Antoine Baché
*/

#include "clogger.h"
#include "zappy_cleanup.h"

void		zappy_cleanup_admin(t_zappy_admin * const admin)
{
  LOG(LOG_DEBUG, "Cleaning administration tool");
  zappy_cleanup_socket(&admin->sock);
  zappy_cleanup_socket(&admin->client);
}
