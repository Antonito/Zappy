/*
** zappy_ring_buffer.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 21:58:48 2017 Antoine Baché
** Last update Mon Jun 26 22:05:56 2017 Antoine Baché
*/

#ifndef ZAPPY_RING_BUFFER_H_
#define ZAPPY_RING_BUFFER_H_

#include <stdint.h>

/*
** Ring buffer capacity
*/
#define ZAPPY_RING_BUFFER_SIZE		(4096)

typedef struct		s_zappy_ring_buffer
{
  uint8_t		buff[ZAPPY_RING_BUFFER_SIZE];
  int32_t		ndx_write;
  int32_t		ndx_read;
}			t_zappy_ring_buffer;

void	zappy_ring_buffer_write(t_zappy_ring_buffer * const buf,
				void const * const data,
				int32_t const size);
void	zappy_ring_buffer_read(t_zappy_ring_buffer * const buf,
			       void * const data,
			       int32_t const size);
int32_t	zappy_ring_buffer_has_cmd(t_zappy_ring_buffer const * const buf);

#endif /* !ZAPPY_RING_BUFFER_H_ */
