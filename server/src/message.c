/*
** message.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 11:54:37 2017 Antoine Baché
** Last update Sun Jun 25 11:58:20 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "zappy_message.h"
#include "zappy_network.h"
#include "zappy_ring_buffer.h"

t_zappy_message_action		zappy_message_read(t_zappy_socket const *
						   const sock,
						   t_zappy_ring_buffer *
						   const ring)
{
  t_zappy_message_action	ret;
  int32_t			rc;
  char				buff[4096];

  assert(sock && ring);
  ret = MSG_SUCCESS;
  rc = zappy_network_read(sock, buff, sizeof(buff) - 1);
  if (rc > 0)
    {
      zappy_ring_buffer_write(ring, (uint8_t const *)buff, rc);
    }
  return (ret);
}

t_zappy_message_action		zappy_message_write(t_zappy_socket const *
						    const sock,
						    t_zappy_message const *
						    const data)
{
  t_zappy_message_action	ret;
  int32_t			rc;
  int32_t			offset;

  assert(sock && data);
  ret = MSG_SUCCESS;
  offset = 0;
  while (offset != data->len)
    {
      rc = zappy_network_write(sock, data->msg + offset, data->len - offset);
      if (rc == -1 || rc == 0)
	{
	  ret = (rc == -1) ? MSG_FAILURE : MSG_DISCONNECT;
	  break;
	}
      offset += rc;
    }
  return (ret);
}

void				zappy_message_clean(t_zappy_message *
						    const data)
{
  assert(data);
  free(data->msg);
  data->msg = NULL;
}
