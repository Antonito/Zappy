/*
** zappy_egg.h for zappy in PSU_2016_zappy/server
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 30 15:51:03 2017 Antoine Baché
** Last update Fri Jun 30 18:13:57 2017 Antoine Baché
*/

#ifndef ZAPPY_EGG_HPP_
#define ZAPPY_EGG_HPP_

#include <stdint.h>

typedef struct		s_zappy_egg	t_zappy_egg;

struct			s_zappy_egg
{
  uint64_t		hatch_date;
  t_zappy_egg		*next;
  t_zappy_egg		*prev;
  int32_t		team_id;
  int32_t		hatched;
  int32_t		id;
  uint8_t		padding[4];
};

#endif /* !ZAPPY_EGG_HPP_ */
