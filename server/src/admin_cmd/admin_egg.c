/*
** admin_egg.c for zappy in PSU_2016_zappy/server/src/admin_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jul  1 20:57:38 2017 Antoine Baché
** Last update Sun Jul  2 14:46:41 2017 Antoine Baché
*/

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_admin_cmd.h"
#include "zappy_team.h"
#include "zappy_egg.h"
#include "zappy_client_serial.h"
#include "zappy_time.h"
#include "zappy_graphic.h"

static void		zappy_admin_cmd_egg_fill(t_zappy * const data,
						 uint64_t const now)
{
  t_zappy_client_serial	*resp;

  resp = zappy_alloc_serial();
  if (resp)
    {
      resp->callback = &zappy_client_hatch_egg;
      resp->remaining_time = 1;
      resp->exec_time = (uint64_t)(((double)resp->remaining_time * 1000.0)
				   / data->conf.freq) + now;
      cqueue_push(&data->glob_events, resp);
      zappy_client_serial_sort(&data->glob_events);
      LOG(LOG_INFO, "Admin added Egg to the hatchery");
    }
}

void			zappy_admin_cmd_egg(t_zappy * const data,
					    char const * cmd)
{
  t_zappy_egg		*egg;
  int32_t		team_id;
  uint64_t		now;
  t_zappy_graph_arg	g;

  (void)cmd;
  assert(data && data->admin.authenticated == true);
  LOG(LOG_DEBUG, "Treating Admin command spawn egg");
  now = zappy_get_cur_time();
  team_id = rand() % data->conf.teams.nb_teams;
  if (team_id == 0)
    ++team_id;
  egg = zappy_egg_add(data, team_id, now);
  if (egg)
    {
      egg->player_id = 0;
      egg->x = rand() % data->map.width;
      egg->y = rand() % data->map.height;
      g = (t_zappy_graph_arg){ egg, 0, 0 };
      zappy_graph_send(&g, data, NULL, &zappy_graph_enw);
      zappy_admin_cmd_egg_fill(data, now);
      dprintf(data->admin.client.sock,
	      "Spawned an egg at %dx%d for team %d\n",
	      egg->x, egg->y, team_id);
    }
}
