/*
** win.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Thu Jun 29 10:42:25 2017 Antoine Baché
** Last update Thu Jun 29 17:42:07 2017 Antoine Baché
*/

#include "zappy.h"
#include "zappy_team.h"

static char const	*zappy_get_winner_team(t_zappy * const data)
{
  int32_t		i;
  t_zappy_team		*team;

  i = 0;
  while (i < data->conf.teams.nb_teams)
    {
      team = &data->conf.teams.team[i];
      if (team->nb_player_lvl_max >= 6)
	{
	  return (team->name);
	}
      ++i;
    }
  return (NULL);
}

bool			zappy_has_winner(t_zappy * const data)
{
  char const		*team_name;

  team_name = zappy_get_winner_team(data);
  if (team_name)
    {
      LOG(LOG_INFO, "Team %s won the game !", team_name);
    }
  return (team_name != NULL);
}
