/*
** tna.c for zappy in PSU_2016_zappy/server/src/graphic_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 20:01:51 2017 Antoine Baché
** Last update Tue Jun 27 20:50:17 2017 Antoine Baché
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_graphic.h"
#include "zappy_team.h"
#include "zappy_message.h"

static void		zappy_graph_tna_single(t_zappy_team const * const t,
					       t_zappy_client * const cli)
{
  t_zappy_message	*msg;
  char			buff[4096];

  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = snprintf(buff, sizeof(buff),
			  "tna %s\n", t->name);
      if (msg->len != -1)
	msg->msg = strdup(buff);
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	}
      free(msg->msg);
      zappy_free_message(msg);
    }
}

void			zappy_graph_tna(t_zappy_client * const cli,
					t_zappy *data,
					char const * const arg)
{
  int32_t		i;

  LOG(LOG_DEBUG, "Treating graphic tna command");
  (void)arg;
  i = 0;
  while (i < data->conf.teams.nb_teams)
    {
      zappy_graph_tna_single(&data->conf.teams.team[i], cli);
      ++i;
    }
}
