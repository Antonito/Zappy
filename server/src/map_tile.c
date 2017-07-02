/*
** map_tile.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 09:44:50 2017 Antoine Baché
** Last update Tue Jun 27 17:50:14 2017 Antoine Baché
*/

#include <assert.h>
#include "clogger.h"
#include "zappy_map.h"

t_zappy_map_tile const	*zappy_get_map_tile(t_zappy_map const * const map,
					    int32_t x, int32_t y)
{
  int32_t		real_x;
  int32_t		real_y;

  if (x >= 0 && x < map->width && y >= 0 && y < map->height)
    return (&map->data[y][x]);
  real_x = x % map->width;
  real_y = y % map->height;
  if (real_x < 0)
    real_x += map->width;
  if (real_y < 0)
    real_y += map->height;
  assert(real_y >= 0 && real_x >= 0);
  return (&map->data[real_y][real_x]);
}
