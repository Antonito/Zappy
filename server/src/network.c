/*
** network.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 12:06:12 2017 Antoine Baché
** Last update Sun Jun 25 17:59:38 2017 Antoine Baché
*/

#include <assert.h>
#include <errno.h>
#include "zappy_socket.h"
#include "zappy_network.h"

int32_t		zappy_network_write(t_zappy_socket const * const sock,
				    void const * data, int32_t const len)
{
  int32_t	ret;
  int32_t	total;
  char const	*buff;

  assert(sock && data);
  assert(len > 0);
  total = 0;
  buff = data;
  while (total != len)
    {
      errno = EINTR;
      ret = -1;
      while (errno == EINTR && ret == -1)
	ret = (int32_t)write(sock->sock, buff + total,
			     (size_t)len - (size_t)total);
      if (ret == -1 || ret == 0)
	{
	  return (ret);
	}
      total += ret;
      assert(total <= len);
    }
  return (total);
}

int32_t		zappy_network_read(t_zappy_socket const * const sock,
				   void *data, int32_t const len)
{
  int32_t	ret;
  char		*buff;

  assert(sock && data);
  assert(len > 0);
  buff = data;
  errno = EINTR;
  ret = -1;
  while (errno == EINTR && ret == -1)
    {
      ret = (int32_t)read(sock->sock, buff, (size_t)len);
    }
  return (ret);
}
