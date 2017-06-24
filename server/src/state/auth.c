/*
** auth.c for zappy in PSU_2016_zappy/server/src/state
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 00:19:33 2017 Antoine Baché
** Last update Sat Jun 24 14:33:05 2017 Antoine Baché
*/

#include <stdlib.h>
#include <string.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy_client.h"
#include "zappy_client_state.h"
#include "zappy_message.h"

void			zappy_cli_state_auth_r(t_zappy_client * const cli,
					       t_zappy * const data)
{
  t_cqueue		*to_treat;

  to_treat = cqueue_get_front(cli->input_queue);
  if (to_treat)
    {
      LOG(LOG_DEBUG, "Got message %p from input_queue", to_treat);
      // TODO: analyze
      (void)data;
      cqueue_pop(&cli->input_queue);
      zappy_message_clean(to_treat->data);
      free(to_treat->data);
      free(to_treat);
    }
}

void			zappy_cli_state_auth_w(t_zappy_client * const cli,
					       t_zappy * const data)
{
  t_zappy_message	*cur;

  (void)data;
  cur = malloc(sizeof(*cur));
  if (cur)
    {
      cur->len = sizeof("WELCOME\n") - 1;
      cur->msg = strndup("WELCOME\n", cur->len + 1);
      if (cur->msg && cqueue_push(&cli->output_queue, cur))
	{
	  cli->can_write = false;
	  return ;
	}
      free(cur->msg);
      free(cur);
    }
  cli->connected = false;
}
