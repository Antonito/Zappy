/*
** message.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 11:54:37 2017 Antoine Baché
** Last update Sat Jun 24 12:17:08 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "zappy_message.h"
#include "zappy_network.h"

t_zappy_message_action		zappy_message_read(t_zappy_socket const *
						   const sock,
						   t_zappy_message **data)
{
  t_zappy_message_action	ret;

  assert(data);
  ret = MSG_SUCCESS;
  (void)sock, (void)data;
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

  assert(data);
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
}
