/*
** map.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 01:40:45 2017 Antoine Baché
** Last update Sun Jun 25 01:54:46 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "zappy_game.h"

static void		zappy_fill_map(t_zappy_map_case * const map,
				       int32_t const x,
				       int32_t const y)
{
  assert(map);
  map->x = x;
  map->y = y;
}

t_zappy_map_case	**zappy_create_map(int32_t const x,
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
