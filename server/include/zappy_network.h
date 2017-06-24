/*
** zappy_network.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 12:00:09 2017 Antoine Baché
** Last update Sat Jun 24 12:02:08 2017 Antoine Baché
*/

#ifndef ZAPPY_NETWORK_H_
#define ZAPPY_NETWORK_H_

#include <stdint.h>

/*
** Forward declaration of t_zappy_socket
*/
typedef struct	s_zappy_socket	t_zappy_socket;

int32_t		zappy_network_write(t_zappy_socket const * const sock,
				    void const *data, int32_t const len);
int32_t		zappy_network_read(t_zappy_socket const * const sock,
				   void *data, int32_t const len);

#endif /* !ZAPPY_NETWORK_H_ */
