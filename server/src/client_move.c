/*
** client_move.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 14:09:15 2017 Antoine Baché
** Last update Mon Jun 26 14:21:23 2017 Antoine Baché
*/

#include <assert.h>
#include "zappy_client_game.h"
#include "zappy_map.h"

void		zappy_client_forward(t_zappy_client_game * const game,
				     t_zappy_map * const map)
{
  assert(game && map);
  if (game->orientation == CLI_NORTH || game->orientation == CLI_SOUTH)
    {
      game->y += 1 * ((game->orientation == CLI_NORTH) ? 1 : -1);
      if (game->y == -1)
	game->y = map->height - 1;
      else if (game->y == map->height)
	game->y = 0;
    }
  else if (game->orientation == CLI_WEST || game->orientation == CLI_EAST)
    {
      game->x += 1 * ((game->orientation == CLI_EAST) ? 1 : -1);
      if (game->x == -1)
	game->x = map->width - 1;
      else if (game->x == map->width)
	game->x = 0;
    }
}
