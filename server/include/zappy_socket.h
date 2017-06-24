/*
** zappy_socket.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 16:08:19 2017 Antoine Baché
** Last update Sat Jun 24 00:32:59 2017 Antoine Baché
*/

#ifndef ZAPPY_SOCKET_H_
#define ZAPPY_SOCKET_H_

#include "zappy_network_gen.h"

/*
** Netowrk informations
** sock -> the socket
** addr -> the connection informations
*/
typedef struct		s_zappy_socket
{
  t_sock		sock;
  t_sockaddr_in		addr;
}			t_zappy_socket;

/*
** Create a socket, listening on port `port`
*/
int32_t			zappy_create_socket(uint16_t const port,
					    t_zappy_socket * const data);

#endif /* ZAPPY_SOCKET_H_ */
