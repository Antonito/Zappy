/*
** zappy.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 14:46:55 2017 Antoine Baché
** Last update Sun Jul  2 19:55:56 2017 Antoine Baché
*/

#ifndef ZAPPY_H_
#define ZAPPY_H_

#include <stdint.h>
#include <stdbool.h>

#if defined(_WIN32)
#include "zappy_windows.h"
#endif

#include "zappy_admin.h"
#include "zappy_config.h"
#include "zappy_socket.h"
#include "zappy_multiplexer.h"
#include "zappy_client_list.h"
#include "zappy_map.h"
#include "zappy_egg_manager.h"

#if defined __GNUC__
#define ZAPPY_NORETURN __attribute__((noreturn))
#else
#define ZAPPY_NORETURN
#endif

/*
** Forward declaration of t_cqueue
*/
typedef struct	s_cqueue	t_cqueue;

/*
** Main structure of the server
** See the corresponding header files
*/
typedef struct			s_zappy
{
  t_zappy_client_list_manager	clients;
  t_zappy_multiplexer		multiplex;
  t_zappy_map			map;
  t_zappy_config		conf;
  t_zappy_egg_manager		egg_manager;
  t_zappy_admin			admin;
  t_cqueue			*glob_events;
  t_zappy_socket		net;
  bool				should_reset;
  uint8_t			padding[3];
}				t_zappy;

int32_t		zappy_parse_args(int const ac,
				 char const * const * av,
				 t_zappy_config * const data);
void		zappy_reset(t_zappy * const data);

#endif /* !ZAPPY_H_ */
