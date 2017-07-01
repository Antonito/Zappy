/*
** admin_info.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jul  1 18:32:27 2017 Antoine Baché
** Last update Sat Jul  1 18:45:29 2017 Antoine Baché
*/

#include <assert.h>
#include <stdio.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_admin_cmd.h"
#include "zappy_team.h"

void		zappy_admin_cmd_info_team(t_zappy * const data)
{
  int32_t	i;
  t_zappy_team	*team;

  dprintf(data->admin.client.sock, "Teams: %d\n", data->conf.teams.nb_teams);
  i = 0;
  while (i < data->conf.teams.nb_teams)
    {
      team = &data->conf.teams.team[i];
      dprintf(data->admin.client.sock, "[%d] Team %s %d/%d {%d}\n",
	      team->id, team->name,
	      team->nb_players, team->nb_players_max, team->nb_player_lvl_max);
      ++i;
    }
}

void	zappy_admin_cmd_info(t_zappy * const data)
{
  assert(data && data->admin.authenticated == true);
  LOG(LOG_DEBUG, "Treating Admin command info");
  dprintf(data->admin.client.sock,
	  "Port:      %d\n"
	  "Freq:      %d\n"
	  "Dimension: %dx%d\n"
	  "%d clients.\n",
	  data->conf.port, data->conf.freq,
	  data->conf.world_width, data->conf.world_height,
	  data->clients.nb_clients);
  zappy_admin_cmd_info_team(data);
}
