/*
** fork.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:29:34 2017 Antoine Baché
** Last update Sun Jul  2 14:45:24 2017 Antoine Baché
*/

#include <string.h>
#include <stdlib.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_client_cmd.h"
#include "zappy_client_serial.h"
#include "zappy_egg.h"
#include "zappy_graphic.h"
#include "zappy_message.h"
#include "zappy_team.h"
#include "zappy_time.h"

void			zappy_client_hatch_egg(t_zappy_client * const cli,
					       t_zappy * const data,
					       char const * const arg)
{
  t_cqueue		*egg_storage;
  t_zappy_egg		*egg;
  t_zappy_graph_arg	g;

  (void)cli;
  (void)arg;
  LOG(LOG_DEBUG, "Treating \'hatch egg\'");
  egg_storage = cqueue_get_front(data->egg_manager.eggs);
  if (egg_storage)
    {
      cqueue_pop(&data->egg_manager.eggs);
      egg = egg_storage->data;
      egg->hatched = 1;
      if (cqueue_push(&data->egg_manager.hatched, egg))
	{
	  if (!zappy_team_add_slot(&data->conf.teams.team[egg->team_id],
				   data))
	    {
	      LOG(LOG_DEBUG, "The egg %d has hatched", egg->id);
	      g = (t_zappy_graph_arg){ NULL, egg->id, 0 };
	      zappy_graph_send(&g, data, NULL, &zappy_graph_eht);
	      ++data->egg_manager.nb_hatched_eggs;
	    }
	}
    }
}

static void		zappy_client_post_fork(t_zappy_client * const cli,
					       t_zappy * const data)
{
  t_zappy_graph_arg	g;
  t_zappy_egg		*egg;
  t_zappy_client_serial	*resp;
  uint64_t		now;

  now = zappy_get_cur_time();
  egg = zappy_egg_add(data, cli->game.team_id, now);
  if (egg)
    {
      egg->player_id = cli->id;
      egg->x = cli->game.x;
      egg->y = cli->game.y;
      g = (t_zappy_graph_arg){ egg, 0, 0 };
      zappy_graph_send(&g, data, NULL, &zappy_graph_enw);
      resp = zappy_alloc_serial();
      if (resp)
	{
	  resp->callback = &zappy_client_hatch_egg;
	  resp->remaining_time = 600;
	  resp->exec_time = (uint64_t)(((double)resp->remaining_time * 1000.0)
				       / data->conf.freq) + now;
	  cqueue_push(&data->glob_events, resp);
	}
    }
}

void			zappy_client_cmd_fork(t_zappy_client * const cli,
					      t_zappy * const data,
					      char const * const arg)
{
  t_zappy_message	*msg;

  (void)arg;
  LOG(LOG_DEBUG, "Treating fork command");
  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = sizeof("ok\n") - 1;
      msg->msg = strdup("ok\n");
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  zappy_client_post_fork(cli, data);
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	  return ;
	}
      zappy_free_message(msg);
    }
}
