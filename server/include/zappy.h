/*
** zappy.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 14:46:55 2017 Antoine Baché
** Last update Fri Jun 23 16:23:37 2017 Antoine Baché
*/

#ifndef ZAPPY_H_
#define ZAPPY_H_

#include "zappy_config.h"
#include "zappy_socket.h"

typedef struct			s_zappy
{
  t_zappy_config		conf;
  t_zappy_socket		net;
}				t_zappy;

int32_t		zappy_parse_args(int const ac,
				 char const * const * av,
				 t_zappy_config * const data);

#endif /* !ZAPPY_H_ */
