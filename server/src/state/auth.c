/*
** auth.c for zappy in PSU_2016_zappy/server/src/state
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 00:19:33 2017 Antoine Baché
** Last update Tue Jun 27 14:45:03 2017 Antoine Baché
*/

#include <stdlib.h>
#include <string.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_client_state.h"
#include "zappy_message.h"

void			zappy_cli_state_auth_r(t_zappy_client * const cli,
					       t_zappy * const data,
					       char const * const msg)
{
  (void)data;
  cli->game.team_name = strdup(msg);
  if (!cli)
    {
      cli->connected = false;
      return ;
    }
  LOG(LOG_DEBUG, "Team name %s", cli->game.team_name);
  cli->state = CLI_CONNECTED;
  cli->can_write = true;
}

void			zappy_cli_state_auth_w(t_zappy_client * const cli,
					       t_zappy * const data)
{
  t_zappy_message	*cur;

  (void)data;
  cur = zappy_alloc_message();
  if (cur)
    {
      cur->len = sizeof("WELCOME\n") - 1;
      cur->msg = strndup("WELCOME\n", (size_t)cur->len + 1);
      if (cur->msg && cqueue_push(&cli->output_queue, cur))
	{
	  cli->can_write = false;
	  return ;
	}
      free(cur->msg);
      zappy_free_message(cur);
    }
  cli->connected = false;
}
