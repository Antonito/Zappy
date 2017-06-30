/*
** pre_incantation.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 30 12:19:19 2017 Antoine Baché
** Last update Fri Jun 30 12:48:53 2017 Antoine Baché
*/

#include <assert.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client_cmd.h"
#include "zappy_elevation.h"
#include "zappy_message.h"

static void		zappy_client_pre_elevation_msg(t_zappy_client *
						       const cli)
{
  t_zappy_message	*msg;

  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = sizeof("Elevation underway\n") - 1;
      msg->msg = strdup("Elevation underway\n");
      if (msg && cqueue_push(&cli->output_queue, msg))
	{
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	  return ;
	}
      free(msg->msg);
      zappy_free_message(msg);
    }
}

static bool		zappy_client_pre_elevation(t_zappy_client * const cli,
						   t_zappy * const data)
{
  int32_t		i;
  int32_t		max;
  t_zappy_client_game	*cur;
  t_zappy_client	*cur_cli;

  if (!zappy_elevation_check(cli, data))
    return (false);
  max = zappy_get_max_player(data);
  i = 0;
  while (i < max)
    {
      cur = data->map.data[cli->game.y][cli->game.x].player[i];
      if (cur)
	{
	  cur_cli = (t_zappy_client *)((uintptr_t)cur -
				       offsetof(t_zappy_client, game));
	  zappy_client_pre_elevation_msg(cur_cli);
	}
      ++i;
    }
  return (true);
}

static void		zappy_client_pre_incant_fail(t_zappy_client *
						     const cli)
{
  t_zappy_message	*msg;

  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = sizeof("ko\n") - 1;
      msg->msg = strdup("ko\n");
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	  return ;
	}
      free(msg->msg);
      zappy_free_message(msg);
    }
}

void			zappy_client_pre_incantation(t_zappy_client *
						     const cli,
						     t_zappy * const data)
{
  assert(cli && data);
  LOG(LOG_DEBUG, "Treating pre incantation");
  if (!zappy_client_pre_elevation(cli, data))
    {
      zappy_client_pre_incant_fail(cli);
    }
}
