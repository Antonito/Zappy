/*
** message.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 11:54:37 2017 Antoine Baché
** Last update Sat Jun 24 14:38:19 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "zappy_message.h"
#include "zappy_network.h"

t_zappy_message_action		zappy_message_fill(t_zappy_message *data,
						   char *buff)
{
  ++data->len;
  data->msg = realloc(data->msg, data->len);
  if (!data->msg)
    return (MSG_DISCONNECT);
  memcpy(data->msg + data->len - 1, &buff, 1);
  return (MSG_SUCCESS);
}

/*
** TODO: Use temporary buff, not read 1
*/
t_zappy_message_action		zappy_message_read(t_zappy_socket const *
						   const sock,
						   t_zappy_message **data)
{
  t_zappy_message_action	ret;
  int32_t			rc;
  char				buff;

  assert(data);
  ret = MSG_SUCCESS;
  if (!(*data = calloc(1, sizeof(**data))))
    return (MSG_DISCONNECT);
  (*data)->len = 0;
  while (1)
    {
      rc = zappy_network_read(sock, &buff, 1);
      if (rc <= 0)
	{
	  free((*data)->msg);
	  free(*data);
	  *data = NULL;
	  return ((rc == 0) ? MSG_DISCONNECT : MSG_FAILURE);
	}
      if (zappy_message_fill(*data, &buff) != MSG_SUCCESS)
	return (MSG_DISCONNECT);
      if (buff == '\n')
	break;
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
