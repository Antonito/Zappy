/*
** cleanup_map.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 11:08:16 2017 Antoine Baché
** Last update Mon Jun 26 11:16:37 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "clogger.h"
#include "zappy_alloc.h"
#include "zappy_cleanup.h"
#include "zappy_map.h"

void			zappy_cleanup_map(t_zappy_map * const map)
{
  int32_t		i;

  LOG(LOG_DEBUG, "Cleaning map");
  assert(map);
  i = 0;
  while (i < map->height)
    {
      free(map->data[i]);
      ++i;
    }
  free(map->data);
}
