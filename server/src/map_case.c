/*
** map_case.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 09:44:50 2017 Antoine Baché
** Last update Tue Jun 27 10:20:13 2017 Antoine Baché
*/

#include "zappy_map.h"

t_zappy_map_case const	*zappy_get_map_case(t_zappy_map const * const map,
					    int32_t x, int32_t y)
{
  if (x >= 0 && x < map->width && y >= 0 && y < map->height)
    return (&map->data[y][x]);
  return (&map->data[y % map->height][x % map->width]);
}
