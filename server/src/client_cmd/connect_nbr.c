/*
** connect_nbr.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 09:42:07 2017 Antoine Baché
** Last update Fri Jun 30 21:10:37 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "cqueue.h"
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_client_cmd.h"
#include "zappy_message.h"
#include "zappy_team_manager.h"

static void	zappy_client_cmd_cnbr_fill(t_zappy_client * const cli,
					   t_zappy_message * const msg)
{
  if (msg->msg && cqueue_push(&cli->output_queue, msg))
    {
      cli->state = CLI_RESPONSE;
      cli->can_write = true;
      return ;
    }
  zappy_free_message(msg);
}

void			zappy_client_cmd_connect_nbr(t_zappy_client *
						     const cli,
						     t_zappy * const data,
						     char const * const arg)
{
  int32_t		rem;
  t_zappy_message	*msg;
  char			buff[512];

  LOG(LOG_DEBUG, "Treating connect_nbr command");
  (void)arg;
  (void)data;
  msg = zappy_alloc_message();
  if (msg)
    {
      rem = zappy_team_manager_get_space(cli->game.team_id, &data->conf.teams);
      assert(rem >= 0);
      msg->msg = NULL;
      msg->len = snprintf(buff, sizeof(buff), "%d\n", rem);
      if (msg->len != -1)
	msg->msg = strdup(buff);
      zappy_client_cmd_cnbr_fill(cli, msg);
    }
}
