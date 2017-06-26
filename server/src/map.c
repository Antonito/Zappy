/*
** map.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 01:40:45 2017 Antoine Baché
** Last update Mon Jun 26 13:07:53 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "clogger.h"
#include "zappy_map.h"
#include "zappy_config.h"

static void		zappy_fill_map(t_zappy_map_case * const map,
				       int32_t const x,
				       int32_t const y)
{
  int32_t		max;

  assert(map);
  map->x = x;
  map->y = y;
  max = rand() % ZAPPY_MAP_MAX_RESSOURCE + 1;
  map->content[RES_LINEMATE] = rand() % max;
  map->content[RES_DERAUMERE] = rand() % max +
    rand() % (map->content[RES_LINEMATE] + 1);
  map->content[RES_SIBUR] =
    rand() % (map->content[RES_DERAUMERE] + 1) + rand() % max;
  map->content[RES_MENDIANE] = rand() %
    (map->content[RES_SIBUR] + map->content[RES_DERAUMERE] + 1);
  map->content[RES_PHIRAS] = rand() % max;
  map->content[RES_THYSTAME] = rand() % max +
    rand() % (map->content[RES_PHIRAS] + 1);
  map->content[RES_FOOD] = rand() % max;
}

static t_zappy_map_case	**zappy_create_map_case(int32_t const x,
						int32_t const y)
{
  int32_t		_y;
  int32_t		i;
  t_zappy_map_case	**map;

  _y = 0;
  map = calloc((size_t)y + 1, sizeof(*map));
  if (!map)
    return (NULL);
  while (_y < y)
    {
      map[_y] = calloc((size_t)x, sizeof(**map));
      if (!map[_y])
	return (NULL);
      i = 0;
      while (i < x)
	{
	  zappy_fill_map(&map[_y][i], i, _y);
	  ++i;
	}
      ++_y;
    }
  return (map);
}

int32_t			zappy_create_map(t_zappy_map * const map,
					 t_zappy_config const * const conf)
{
  assert(map && conf);
  map->width = conf->world_width;
  map->height = conf->world_height;
  LOG(LOG_INFO, "Generating resources...");
  map->data = zappy_create_map_case(map->width, map->height);
  return (!map->data);
}
