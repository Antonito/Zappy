/*
** zappy_egg.h for zappy in PSU_2016_zappy/server
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 30 15:51:03 2017 Antoine Baché
** Last update Sat Jul  1 21:07:16 2017 Antoine Baché
*/

#ifndef ZAPPY_EGG_HPP_
#define ZAPPY_EGG_HPP_

#include <stdint.h>

/*
** Forward declaration of t_zappy
*/
typedef struct		s_zappy		t_zappy;

/*
** Forward declaration of t_zappy_client
*/
typedef struct		s_zappy_client	t_zappy_client;

typedef struct		s_zappy_egg	t_zappy_egg;

struct			s_zappy_egg
{
  uint64_t		hatch_date;
  t_zappy_egg		*next;
  t_zappy_egg		*prev;
  int32_t		team_id;
  int32_t		hatched;
  int32_t		id;
  int32_t		x;
  int32_t		y;
  int32_t		player_id;
};

void			zappy_client_hatch_egg(t_zappy_client * const cli,
					       t_zappy * const data,
					       char const * const arg);

#endif /* !ZAPPY_EGG_HPP_ */
