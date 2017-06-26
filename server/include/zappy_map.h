/*
** zappy_map.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 01:22:04 2017 Antoine Baché
** Last update Mon Jun 26 13:18:51 2017 Antoine Baché
*/

#ifndef ZAPPY_MAP_H_
#define ZAPPY_MAP_H_

#include <stdint.h>
#include "zappy_resource.h"

#define ZAPPY_MAP_MAX_RESSOURCE	32

/*
** Forward declaration of t_zappy_config
*/
typedef struct	s_zappy_config	t_zappy_config;

typedef struct			s_zappy_map_case
{
  int32_t			x;
  int32_t			y;
  int32_t			content[NB_RESOURCE];
}				t_zappy_map_case;

typedef struct			s_zappy_map
{
  t_zappy_map_case		**data;
  int32_t			width;
  int32_t			height;
}				t_zappy_map;

int32_t	zappy_create_map(t_zappy_map * const map,
			 t_zappy_config const * const conf);

#endif /* !ZAPPY_MAP_H_ */
