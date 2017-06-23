/*
** zappy_multiplexer.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 16:46:10 2017 Antoine Baché
** Last update Fri Jun 23 17:55:09 2017 Antoine Baché
*/

#ifndef ZAPPY_MULTIPLEXER_H_
#define ZAPPY_MULTIPLEXER_H_

#include <stdint.h>
#include <sys/time.h>
#include <sys/select.h>
#include "zappy_network_gen.h"
#include "zappy_client_list.h"

/*
** Forward declaration of t_zappy
*/
typedef struct s_zappy	t_zappy;

typedef struct		s_zappy_multiplexer
{
  t_sock		max_sock;
  fd_set		readfds;
  fd_set		writefds;
  fd_set		exceptfds;
  struct timeval	tv;
}			t_zappy_multiplexer;

int32_t			zappy_multiplexer(int32_t const server_sock,
					  t_zappy_client_list_manager *
					  const clients,
					  t_zappy_multiplexer * const data);
void			zappy_io(t_zappy * const data);

#endif /* ZAPPY_MULTIPLEXER_H_ */
