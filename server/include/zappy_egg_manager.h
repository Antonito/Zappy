/*
** zappy_egg_manager.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 30 15:54:46 2017 Antoine Baché
** Last update Sat Jul  1 10:46:44 2017 Antoine Baché
*/

#ifndef ZAPPY_EGG_MANAGER_H_
#define ZAPPY_EGG_MANAGER_H_

#include "zappy_egg.h"

/*
** Forward declaration of t_zappy
*/
typedef struct		s_zappy		t_zappy;

/*
** Forward declaration of t_zappy
*/
typedef struct		s_cqueue	t_cqueue;

typedef struct		s_zappy_egg_manager
{
  t_cqueue		*eggs;
  t_cqueue		*hatched;
  int32_t		nb_eggs;
  int32_t		nb_hatched_eggs;
}			t_zappy_egg_manager;

typedef void (*t_zappy_egg_callback)(t_zappy_egg * const egg,
				     void * const data);

void			zappy_remove_egg(t_zappy * const data,
					 t_zappy_egg * const egg);
t_zappy_egg		*zappy_egg_add(t_zappy * const data,
				       int32_t const team_id,
				       uint64_t const now);
int32_t			zappy_get_number_hatched_eggs(t_zappy * const data,
						      int32_t const team_id);
t_zappy_egg		*zappy_get_egg_from_team(t_zappy * const data,
						 int32_t const team_id);

#endif /* !ZAPPY_EGG_MANAGER_H_ */
