/*
** zappy_multiplexer.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 16:46:10 2017 Antoine Baché
** Last update Fri Jun 23 17:21:48 2017 Antoine Baché
*/

#ifndef ZAPPY_MULTIPLEXER_H_
#define ZAPPY_MULTIPLEXER_H_

#include <stdint.h>
#include <sys/time.h>
#include <sys/select.h>
#include "zappy_network_gen.h"
#include "zappy_client_list.h"

typedef struct		s_zappy_multiplexer
{
  t_sock		max_sock;
  fd_set		readfds;
  fd_set		writefds;
  fd_set		exceptfds;
  struct timeval	tv;
}			t_zappy_multiplexer;

int32_t			zappy_multiplexer(t_zappy_client_list_manager *
					  const clients,
					  t_zappy_multiplexer * const data);

#endif /* ZAPPY_MULTIPLEXER_H_ */
