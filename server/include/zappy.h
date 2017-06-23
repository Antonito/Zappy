/*
** zappy.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 14:46:55 2017 Antoine Baché
** Last update Fri Jun 23 14:57:34 2017 Antoine Baché
*/

#ifndef ZAPPY_H_
#define ZAPPY_H_

#include "zappy_config.h"

typedef struct			s_zappy
{
  t_zappy_config		conf;
}				t_zappy;

int32_t		zappy_parse_args(int const ac,
				 char const * const * av,
				 t_zappy_config * const data);

#endif /* !ZAPPY_H_ */
