/*
** team_manager.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 19:43:18 2017 Antoine Baché
** Last update Mon Jun 26 09:48:50 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "zappy_config.h"
#include "zappy_team.h"
#include "zappy_team_manager.h"
#include "zappy_client.h"

int32_t		zappy_team_manager_add_team(char const * const name,
					    t_zappy_team_manager * const man)
{
  assert(name && man);
  man->team = realloc(man->team,
		      sizeof(*(man->team)) * ((size_t)man->nb_teams + 1));
  if (!man->team)
    {
      return (1);
    }
  man->team[man->nb_teams].id = man->nb_teams;
  man->team[man->nb_teams].nb_players = 0;
  man->team[man->nb_teams].name = name;
  ++man->nb_teams;
  return (0);
}

t_zappy_team	*zappy_team_manager_get_team_by_name(char const * const name,
						     t_zappy_team_manager *
						     const man)
{
  int32_t	i;
  size_t	len;

  assert(name && man);
  i = 0;
  len = strlen(name);
  while (i < man->nb_teams)
    {
      if (!memcmp(name, man->team[i].name, len))
	{
	  return (&man->team[i]);
	}
      ++i;
    }
  return (NULL);
}

int32_t		zappy_team_manager_add_client(char const * const teamname,
					      t_zappy_client * const cli,
					      t_zappy_team_manager * const man)
{
  t_zappy_team	*team;

  assert(teamname && cli && man);
  team = zappy_team_manager_get_team_by_name(teamname, man);
  if (team)
    {
      if (team->nb_players < man->nb_client_per_team)
	{
	  cli->game.team_id = team->id;
	  ++team->nb_players;
	  return (man->nb_client_per_team - team->nb_players);
	}
    }
  return (-1);
}

int32_t		zappy_team_manager_get_space(int32_t const ndx,
					     t_zappy_team_manager const *
					     const man)
{
  assert(ndx < man->nb_teams);
  return (man->nb_client_per_team - man->team[ndx].nb_players);
}
