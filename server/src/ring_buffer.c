/*
** ring_buffer.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 21:55:49 2017 Antoine Baché
** Last update Sun Jun 25 13:15:51 2017 Antoine Baché
*/

#include <assert.h>
#include <ctype.h>
#include "zappy_ring_buffer.h"

void		zappy_ring_buffer_write(t_zappy_ring_buffer * const buf,
					uint8_t const * const data,
					int32_t const size)
{
  int32_t	i;
  int32_t const	max = ZAPPY_RING_BUFFER_SIZE;

  assert(buf && data);
  i = 0;
  while (i < size)
    {
      if (buf->ndx_write == max)
	{
	  buf->ndx_write = 0;
	}
      if (isprint(data[i]) || data[i] == '\r' || data[i] == '\n')
	{
	  buf->buff[buf->ndx_write] = data[i];
	}
      else
	{
	  buf->buff[buf->ndx_write] = '?';
	}
      ++buf->ndx_write;
      ++i;
    }
}

void		zappy_ring_buffer_read(t_zappy_ring_buffer * const buf,
				       uint8_t * const data,
				       int32_t const size)
{
  int32_t	i;
  int32_t const	max = ZAPPY_RING_BUFFER_SIZE;

  assert(buf && data);
  i = 0;
  while (i < size)
    {
      if (buf->ndx_read == max)
	buf->ndx_read = 0;
      data[i] = buf->buff[buf->ndx_read];
      buf->buff[buf->ndx_read] = '\0';
      ++buf->ndx_read;
      ++i;
    }
}

int32_t		zappy_ring_buffer_has_cmd(t_zappy_ring_buffer const *
					  const buf)
{
  int32_t	i;
  int32_t	j;
  int32_t	len;
  int32_t const	max = ZAPPY_RING_BUFFER_SIZE;

  i = buf->ndx_read;
  len = 0;
  j = 0;
  while (j < max)
    {
      if (i >= max)
	i = 0;
      if (buf->buff[i] == '\n')
	{
	  return (len + 1);
	}
      ++j;
      ++i;
      ++len;
    }
  return (0);
}
