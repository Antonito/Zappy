/*
** vision.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 17:31:40 2017 Antoine Baché
** Last update Mon Jun 26 19:03:12 2017 Antoine Baché
*/

#include <assert.h>
#include "zappy_client.h"
#include "zappy_map.h"
#include "zappy_client_vision.h"

void	zappy_vision_exec(t_zappy_map const * const map,
			  t_zappy_client const * const cli,
			  t_zappy_client_vision * const vis)
{
  assert(map && cli && vis);
  (void)map;
  (void)cli;
  (void)vis;
}
