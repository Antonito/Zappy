/*
** server.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 16:44:36 2017 Antoine Baché
** Last update Sat Jun 24 15:26:27 2017 Antoine Baché
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_logic.h"
#include "zappy_server.h"

void		zappy_server_accept(t_zappy * const data)
{
  t_sockaddr_in	sin;
  socklen_t	len;
  int32_t	ret;

  errno = EINTR;
  len = 0;
  ret = -1;
  LOG(LOG_DEBUG, "Accepting new connection...");
  while (ret == -1 && errno == EINTR)
    {
      memset(&sin, 0, sizeof(sin));
      len = sizeof(sin);
      ret = accept(data->net.sock, (t_sockaddr *)&sin, &len);
    }
  if (ret >= 0)
    {
      zappy_client_add(&data->clients, ret, &sin, len);
    }
}

int32_t		zappy_server(t_zappy * const data)
{
  int32_t	rc;

  while (1)
    {
      rc = zappy_multiplexer(data->net.sock,
			     &data->clients, &data->multiplex);
      if (rc == -1)
	{
	  LOG(LOG_ERROR, "Internal error [select: %s]",
	      strerror(errno));
	  return (84);
	}
      else if (rc > 0)
	{
	  zappy_io(data);
	}
      zappy_logic(data);
    }
}
