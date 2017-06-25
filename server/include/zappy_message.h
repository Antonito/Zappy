/*
** zappy_message.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 11:39:52 2017 Antoine Baché
** Last update Sat Jun 24 23:01:29 2017 Antoine Baché
*/

#ifndef ZAPPY_MESSAGE_H_
#define ZAPPY_MESSAGE_H_

#include <stdint.h>

/*
** Forward declaration of t_zappy_socket
*/
typedef struct	s_zappy_socket		t_zappy_socket;

/*
** Forward declaration of t_zappy_ring_buffer
*/
typedef struct	s_zappy_ring_buffer	t_zappy_ring_buffer;

typedef enum		e_zappy_message_action
  {
    MSG_SUCCESS		= 0,
    MSG_FAILURE,
    MSG_DISCONNECT
  }			t_zappy_message_action;

/*
** Internal representation of a network message
*/
typedef struct		s_zappy_message
{
  char			*msg;
  int32_t		len;
  uint8_t		padding[4];
}			t_zappy_message;

t_zappy_message_action	zappy_message_read(t_zappy_socket const * const,
					   t_zappy_ring_buffer * const);
t_zappy_message_action	zappy_message_write(t_zappy_socket const * const,
					    t_zappy_message const *
					    const data);
void			zappy_message_clean(t_zappy_message * const data);

#endif /* !ZAPPY_MESSAGE_H_ */
