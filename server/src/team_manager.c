/*
** team_manager.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 19:43:18 2017 Antoine Baché
** Last update Sun Jul  2 21:40:23 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "clogger.h"
#include "zappy_config.h"
#include "zappy_color.h"
#include "zappy_team.h"
#include "zappy_team_manager.h"
#include "zappy_client.h"

int32_t		zappy_team_manager_add_team(char const * const name,
					    t_zappy_team_manager * const man)
{
  assert(name && man);
  if (zappy_team_manager_get_team_by_name(name, man))
    {
      LOG(LOG_ERROR, "Team %s already exists", name);
      return (1);
    }
  man->team = realloc(man->team,
		      sizeof(*(man->team)) * ((size_t)man->nb_teams + 1));
  if (!man->team)
    {
      return (1);
    }
  LOG(LOG_DEBUG, "Added team %s", name);
  man->team[man->nb_teams].id = man->nb_teams;
  man->team[man->nb_teams].nb_players = 0;
  man->team[man->nb_teams].name = name;
  man->team[man->nb_teams].nb_players_max = 0;
  man->team[man->nb_teams].nb_player_lvl_max = 0;
  ++man->nb_teams;
  return (0);
}

t_zappy_team	*zappy_team_manager_get_team_by_name(char const * const name,
						     t_zappy_team_manager *
						     const man)
{
  int32_t	i;

  assert(name && man);
  i = 0;
  while (i < man->nb_teams)
    {
      if (man->team[i].name && !strcmp(name, man->team[i].name))
	{
	  return (&man->team[i]);
	}
      ++i;
    }
  return (NULL);
}

void		zappy_team_manager_delete_client(char const *
						 const name,
						 t_zappy_team_manager *
						 const man)
{
  t_zappy_team	*team;

  assert(name && man);
  LOG(LOG_INFO, "Removing client from team %s", name);
  team = zappy_team_manager_get_team_by_name(name, man);
  if (team)
    {
      assert(team->nb_players > 0);
      --team->nb_players;
    }
}

int32_t		zappy_team_manager_add_client(char const * const teamname,
					      t_zappy_client * const cli,
					      t_zappy_team_manager * const man)
{
  t_zappy_team	*team;

  assert(teamname && cli && man);
  LOG(LOG_INFO, "Adding client to team %s", teamname);
  team = zappy_team_manager_get_team_by_name(teamname, man);
  if (team)
    {
      if (team->nb_players < team->nb_players_max)
	{
	  cli->game.team_id = team->id;
	  ++team->nb_players;
	  if (!strncmp(teamname, "GRAPHIC", sizeof("GRAPHIC")))
	    {
	      LOG(LOG_INFO, PURPLE_BOLD_INTENS"Graphical client joined"CLEAR);
	      cli->graphical = true;
	    }
	  return (team->nb_players_max - team->nb_players);
	}
      LOG(LOG_WARNING, "Team %s is full", teamname);
    }
  else
    LOG(LOG_WARNING, "Unkown team %s", teamname);
  return (-1);
}

int32_t		zappy_team_manager_get_space(int32_t const ndx,
					     t_zappy_team_manager const *
					     const man)
{
  assert(ndx < man->nb_teams);
  return (man->team[ndx].nb_players_max - man->team[ndx].nb_players);
}
