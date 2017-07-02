/*
** zappy_map.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 01:22:04 2017 Antoine Baché
** Last update Sat Jul  1 15:54:59 2017 Antoine Baché
*/

#ifndef ZAPPY_MAP_H_
#define ZAPPY_MAP_H_

#include <stdint.h>
#include "zappy_resource.h"

#define ZAPPY_MAP_MAX_RESSOURCE	20

/*
** Forward declaration of t_zappy_config
*/
typedef struct	s_zappy_config	t_zappy_config;

/*
** Forward declaration of t_zappy_client_game
*/
typedef struct	s_zappy_client_game	t_zappy_client_game;

typedef struct			s_zappy_map_tile
{
  t_zappy_client_game		**player;
  int32_t			x;
  int32_t			y;
  int32_t			content[NB_RESOURCE];
  int32_t			nb_players;
}				t_zappy_map_tile;

typedef struct			s_zappy_map
{
  t_zappy_map_tile		**data;
  int32_t			width;
  int32_t			height;
}				t_zappy_map;

int32_t			zappy_create_map(t_zappy_map * const map,
					 t_zappy_config const * const conf);
t_zappy_map_tile const	*zappy_get_map_tile(t_zappy_map const * const,
					    int32_t x, int32_t y);

#endif /* !ZAPPY_MAP_H_ */
