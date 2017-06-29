/*
** player.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Thu Jun 29 13:28:54 2017 Antoine Baché
** Last update Thu Jun 29 14:03:40 2017 Antoine Baché
*/

#include <assert.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_client_game.h"
#include "zappy_team.h"
#include "zappy_team_manager.h"

static int32_t		zappy_player_check_team(t_zappy * const data)
{
  int32_t		i;
  int32_t		total;

  i = 0;
  total = 0;
  while (i < data->conf.teams.nb_teams)
    {
      total += data->conf.teams.team[i].nb_players;
      ++i;
    }
  return (total);
}

void			zappy_has_player(t_zappy * const data)
{
  int32_t		clients;
  t_zappy_team const	*graph_team;

  assert(data);
  clients = data->clients.nb_clients;
  if (clients != 0)
    {
      graph_team = zappy_team_manager_get_team_by_name("GRAPHIC",
						   &data->conf.teams);
      assert(graph_team);
      clients = zappy_player_check_team(data);
      data->clients.has_player = (graph_team->nb_players != clients);
    }
  else
    {
      data->clients.has_player = false;
    }
  if (!data->clients.has_player)
    {
      data->multiplex.tv_ref.tv_sec = 0;
      data->multiplex.tv_ref.tv_usec = 0;
    }
  LOG(LOG_DEBUG, "Checked players : %d", data->clients.has_player);
}
