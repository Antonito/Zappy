/*
** zappy.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 14:46:55 2017 Antoine Baché
** Last update Sun Jun 25 20:24:48 2017 Antoine Baché
*/

#ifndef ZAPPY_H_
#define ZAPPY_H_

#include "zappy_config.h"
#include "zappy_socket.h"
#include "zappy_multiplexer.h"
#include "zappy_client_list.h"

#if defined __GNUC__
#define ZAPPY_NORETURN __attribute__((noreturn))
#else
#define ZAPPY_NORETURN
#endif

/*
** Main structure of the server
** See the corresponding header files
*/
typedef struct			s_zappy
{
  t_zappy_client_list_manager	clients;
  t_zappy_multiplexer		multiplex;
  t_zappy_config		conf;
  t_zappy_socket		net;
  uint8_t			padding[4];
}				t_zappy;

int32_t		zappy_parse_args(int const ac,
				 char const * const * av,
				 t_zappy_config * const data);

#endif /* !ZAPPY_H_ */
