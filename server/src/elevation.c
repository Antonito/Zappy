/*
** elevation.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 17:25:22 2017 Antoine Baché
** Last update Fri Jun 30 17:02:06 2017 Antoine Baché
*/

#include <assert.h>
#include "clogger.h"
#include "zappy.h"
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

static bool		zappy_elevation_check_table(t_zappy_client_game
						    const *cli,
						    t_zappy * const data)
{
  t_zappy_map_case	*cur;
  int32_t		cur_lvl;

  cur = &data->map.data[cli->y][cli->x];
  cur_lvl = cli->level;
  assert(cur_lvl > 0);
  if (cur->content[RES_LINEMATE] != elevation_table[cur_lvl - 1].linemate ||
      cur->content[RES_DERAUMERE] != elevation_table[cur_lvl - 1].deraumere ||
      cur->content[RES_SIBUR] != elevation_table[cur_lvl - 1].sibur ||
      cur->content[RES_MENDIANE] != elevation_table[cur_lvl - 1].mendiane ||
      cur->content[RES_PHIRAS] != elevation_table[cur_lvl - 1].phiras ||
      cur->content[RES_THYSTAME] != elevation_table[cur_lvl - 1].thystame)
    {
      return (false);
    }
  return (true);
}

static bool		zappy_elevation_check_lvl(int32_t const cur_lvl,
						  int32_t const nb_players,
						  t_zappy_client_game const *
						  const cli,
						  t_zappy_client_game *
						  const *players)
{
  int32_t		i;
  int32_t		found;

  assert(cur_lvl > 0);
  i = 0;
  found = 0;
  while (i < nb_players)
    {
      if (players[i] && players[i] != cli && players[i]->level == cur_lvl)
	{
	  ++found;
	}
      ++i;
    }
  if (found != elevation_table[cur_lvl - 1].nb_player - 1)
    return (false);
  return (true);
}

bool			zappy_elevation_check(t_zappy_client * const cli,
					      t_zappy *data)
{
  int32_t		x;
  int32_t		y;

  assert(cli && data);
  if (!zappy_elevation_check_table(&cli->game, data))
    {
      LOG(LOG_DEBUG, "Elevation table check KO");
      return (false);
    }
  LOG(LOG_DEBUG, "Elevation table check OK");
  x = cli->game.x;
  y = cli->game.y;
  return (zappy_elevation_check_lvl(cli->game.level,
				    zappy_get_max_player(data),
				    &cli->game,
				    data->map.data[y][x].player));
}

void			zappy_elevation_end_inv(t_zappy_client_game *
						const cli,
						t_zappy * const data)
{
  t_zappy_map_case	*cur;

  cur = &data->map.data[cli->y][cli->x];
  cur->content[RES_LINEMATE] -= elevation_table[cli->level - 1].linemate;
  cur->content[RES_DERAUMERE] -= elevation_table[cli->level - 1].deraumere;
  cur->content[RES_SIBUR] -= elevation_table[cli->level - 1].sibur;
  cur->content[RES_MENDIANE] -= elevation_table[cli->level - 1].mendiane;
  cur->content[RES_PHIRAS] -= elevation_table[cli->level - 1].phiras;
  cur->content[RES_THYSTAME] -= elevation_table[cli->level - 1].thystame;
}
