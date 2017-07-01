/*
** team.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Thu Jun 29 14:37:15 2017 Antoine Baché
** Last update Sat Jul  1 12:34:50 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_map.h"
#include "zappy_team_manager.h"
#include "zappy_team.h"

void		zappy_team_set_max_players(t_zappy_team_manager *teams,
					   int32_t const max)
{
  int32_t	i;

  assert(teams);
  i = 0;
  while (i < teams->nb_teams)
    {
      teams->team[i].nb_players_max = max;
      ++i;
    }
}

static int32_t	zappy_team_update_map(t_zappy * const data,
				      size_t const max_players)
{
  int32_t	x;
  int32_t	y;
  void		*tmp;

  y = 0;
  while (y < data->map.height)
    {
      x = 0;
      while (x < data->map.width)
	{
	  tmp = realloc(data->map.data[y][x].player,
			sizeof(t_zappy_client_game *) * (max_players));
	  if (!tmp)
	    return (1);
	  data->map.data[y][x].player = tmp;
	  data->map.data[y][x].player[max_players - 1] = NULL;
	  ++x;
	}
      ++y;
    }
  return (0);
}

int32_t		zappy_team_add_slot(t_zappy_team * const team,
				    t_zappy * const data)
{
  assert(team);
  LOG(LOG_INFO, "Adding slot to team %s", team->name);
  if (zappy_team_update_map(data, (size_t)zappy_get_max_player(data) + 1))
    {
      LOG(LOG_ERROR, "Cannot add slot to team %s", team->name);
      return (1);
    }
  ++team->nb_players_max;
  return (0);
}
