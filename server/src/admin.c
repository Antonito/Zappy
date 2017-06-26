/*
** admin.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 19:36:44 2017 Antoine Baché
** Last update Mon Jun 26 19:41:15 2017 Antoine Baché
*/

#include <assert.h>
#include "clogger.h"
#include "zappy.h"

int32_t		zappy_start_admin(t_zappy * const data)
{
  int32_t	rc;

  assert(data);
  rc = zappy_create_socket(data->conf.port + 1, &data->admin.sock);
  if (rc)
    {
      LOG(LOG_ERROR, "Cannot create administration socket");
    }
  return (0);
}
