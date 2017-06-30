/*
** team.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Thu Jun 29 14:37:15 2017 Antoine Baché
** Last update Thu Jun 29 14:40:25 2017 Antoine Baché
*/

#include <assert.h>
#include "zappy_team_manager.h"
#include "zappy_team.h"

void		zappy_team_set_max_players(t_zappy_team_manager *teams,
					   int32_t const max)
{
  int32_t	i;

  assert(teams && max >= 6);
  i = 0;
  while (i < teams->nb_teams)
    {
      teams->team[i].nb_players_max = max;
      ++i;
    }
}
