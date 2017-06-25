/*
** elevation.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 17:25:22 2017 Antoine Baché
** Last update Sun Jun 25 20:25:39 2017 Antoine Baché
*/

#include <assert.h>
#include "zappy_client.h"
#include "zappy_client_game.h"
#include "zappy_elevation.h"

static t_zappy_elevation const	elevation_table[] =
  {
    { 1, 1, 0, 0, 0, 0, 0 },
    { 2, 1, 1, 1, 0, 0, 0 },
    { 2, 2, 0, 1, 0, 2, 0 },
    { 4, 1, 1, 2, 0, 1, 0 },
    { 4, 1, 2, 1, 3, 0, 0 },
    { 6, 1, 2, 3, 0, 1, 0 },
    { 6, 2, 2, 2, 2, 2, 1 }
  };

#if (__STDC_VERSION__ >= 201112L) && defined static_assert
_Static_assert(sizeof(elevation_table) / sizeof(elevation_table[0]) == 7,
	       "Incorrect number of elevation level");
#endif

static bool	zappy_elevation_check_table(t_zappy_client_inventory const *
					    const inv, int32_t const cur_lvl)
{
  assert(cur_lvl > 0);
  if (inv->linemate != elevation_table[cur_lvl - 1].linemate ||
      inv->deraumere != elevation_table[cur_lvl - 1].deraumere ||
      inv->sibur != elevation_table[cur_lvl - 1].sibur ||
      inv->mendiane != elevation_table[cur_lvl - 1].mendiane ||
      inv->phiras != elevation_table[cur_lvl - 1].phiras ||
      inv->thystame != elevation_table[cur_lvl - 1].thystame)
    {
      return (false);
    }
  return (true);
}

bool		zappy_elevation_check(t_zappy_client * const cli,
				      t_zappy *data)
{
  assert(cli && data);
  (void)data;
  if (!zappy_elevation_check_table(&cli->game.inv, cli->game.level))
    return (false);
  // TODO: check number of player and their levels
  return (true);
}
