/*
** zappy_egg_manager.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 30 15:54:46 2017 Antoine Baché
** Last update Fri Jun 30 16:26:41 2017 Antoine Baché
*/

#ifndef ZAPPY_EGG_MANAGER_H_
#define ZAPPY_EGG_MANAGER_H_

#include "zappy_egg.h"

/*
** Forward declaration of t_zappy
*/
typedef struct		s_zappy		t_zappy;

typedef struct		s_zappy_egg_manager
{
  t_zappy_egg		*eggs;
  int32_t		nb_eggs;
  uint8_t		padding[4];
}			t_zappy_egg_manager;

typedef void (*t_zappy_egg_callback)(t_zappy_egg * const egg,
				     void * const data);

t_zappy_egg		*zappy_egg_add(t_zappy * const data,
				       int32_t const team_id,
				       uint64_t const now);
void			zappy_egg_remove(t_zappy_egg_manager * const man,
					 t_zappy_egg * const egg);
void			zappy_egg_foreach(t_zappy * const data,
					  void * const user_data,
					  t_zappy_egg_callback call);

#endif /* !ZAPPY_EGG_MANAGER_H_ */
