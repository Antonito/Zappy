/*
** socket.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 16:07:39 2017 Antoine Baché
** Last update Fri Jun 23 23:00:39 2017 Antoine Baché
*/

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "clogger.h"
#include "zappy_socket.h"

static void	zappy_socket_init_addr(uint16_t const port,
				       t_sockaddr_in * const addr)
{
  addr->sin_addr.s_addr = htonl(INADDR_ANY);
  addr->sin_family = AF_INET;
  addr->sin_port = htons(port);
}

static int32_t	zappy_socket_host(t_zappy_socket * const data)
{
  int32_t	rc;

  rc = bind(data->sock, (t_sockaddr *)&data->addr, sizeof(t_sockaddr_in));
  if (rc == -1)
    {
      LOG(LOG_ERROR, "Cannot initialize connection [bind: %s]",
	  strerror(errno));
      return (1);
    }
  rc = listen(data->sock, 5);
  if (rc == -1)
    {
      LOG(LOG_ERROR, "Cannot initialize connection [listen: %s]",
	  strerror(errno));
      return (1);
    }
  return (0);
}

int32_t		zappy_create_socket(uint16_t const port,
				   t_zappy_socket * const data)
{
  int32_t	rc;

  zappy_socket_init_addr(port, &data->addr);
  data->sock = socket(AF_INET, SOCK_STREAM, 0);
  if (data->sock == -1)
    {
      LOG(LOG_ERROR, "Cannot initialize connection [socket: %s]",
	  strerror(errno));
      return (1);
    }
  rc = setsockopt(data->sock, SOL_SOCKET, SO_REUSEADDR,
		  (int32_t[]){1}, sizeof(int32_t));
  if (rc == -1)
    {
      LOG(LOG_WARNING, "Cannot configure socket [setsockopt: %d]",
	  strerror(errno));
    }
  rc = zappy_socket_host(data);
  return (rc);
}
