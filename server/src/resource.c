/*
** resource.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 12:46:33 2017 Antoine Baché
** Last update Mon Jun 26 13:21:31 2017 Antoine Baché
*/

#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include "zappy_map.h"
#include "zappy_resource.h"

static char const	*zappy_resource_table[] =
  {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame"
  };

void			zappy_resource_spawn(t_zappy_resource const res,
					     t_zappy_map * const map)
{
  int			x;
  int			y;

  assert(res != RES_UNKNOWN && map);
  x = rand() % map->width;
  y = rand() % map->height;
  ++map->data[y][x].content[res];
}

t_zappy_resource	zappy_get_resource_by_name(char const * const name)
{
  int32_t		i;
  size_t		len;

  assert(name);
  i = 0;
  len = strlen(name);
  while (i < NB_RESOURCE)
    {
      if (!memcmp(name, zappy_resource_table[i], len))
	{
	  return (i);
	}
      ++i;
    }
  return (RES_UNKNOWN);
}
