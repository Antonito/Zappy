/*
** zappy_resource.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 12:48:19 2017 Antoine Baché
** Last update Mon Jun 26 13:20:02 2017 Antoine Baché
*/

#ifndef ZAPPY_RESOURCE_H_
#define ZAPPY_RESOURCE_H_

/*
** Forward declaration of t_zappy_map
*/
typedef struct	s_zappy_map	t_zappy_map;

typedef enum		e_zappy_resource
  {
    RES_UNKNOWN		= -1,
    RES_FOOD		= 0,
    RES_LINEMATE,
    RES_DERAUMERE,
    RES_SIBUR,
    RES_MENDIANE,
    RES_PHIRAS,
    RES_THYSTAME,
    NB_RESOURCE
  }			t_zappy_resource;

t_zappy_resource	zappy_get_resource_by_name(char const * const name);
void			zappy_resource_spawn(t_zappy_resource const res,
					     t_zappy_map * const map);

#endif /* !ZAPPY_RESOURCE_H_ */
