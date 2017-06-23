/*
** server.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 16:44:36 2017 Antoine Baché
** Last update Fri Jun 23 17:34:53 2017 Antoine Baché
*/

#include <stdio.h>
#include "zappy.h"

int32_t		zappy_server(t_zappy * const data)
{
  int32_t	rc;

  while (1)
    {
      rc = zappy_multiplexer(&data->clients, &data->multiplex);
      if (rc == -1)
	{
	  perror("select");
	  return (84);
	}
      else if (rc > 0)
	{
	  zappy_io(data);
	}
      // TODO: Logic
    }
  return (0);
}
