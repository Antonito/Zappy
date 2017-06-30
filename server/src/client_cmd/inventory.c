/*
** inventory.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:29:34 2017 Antoine Baché
** Last update Fri Jun 30 16:36:43 2017 Antoine Baché
*/

#include <stdlib.h>
#include <string.h>
#include "cqueue.h"
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_client_cmd.h"
#include "zappy_message.h"

static void		zappy_client_cmd_inventory_build(t_zappy_client *
							 const cli,
							 t_zappy_message *
							 const msg)
{
  char			buff[1024];

  msg->msg = NULL;
  msg->len =
    snprintf(buff, sizeof(buff),
	     "[ food %d, linemate %d, deraumere %d, "
	     "sibur %d, mendiane %d, phiras %d, thystame %d ]\n",
	     cli->game.inv[RES_FOOD], cli->game.inv[RES_LINEMATE],
	     cli->game.inv[RES_DERAUMERE], cli->game.inv[RES_SIBUR],
	     cli->game.inv[RES_MENDIANE], cli->game.inv[RES_PHIRAS],
	     cli->game.inv[RES_THYSTAME]);
  if (msg->len != -1)
    {
      msg->msg = strdup(buff);
    }
}

void			zappy_client_cmd_inventory(t_zappy_client * const cli,
						   t_zappy * const data,
						   char const * const arg)
{
  t_zappy_message	*msg;

  LOG(LOG_DEBUG, "Treating inventory command");
  (void)cli, (void)data, (void)arg;
  msg = zappy_alloc_message();
  if (msg)
    {
      zappy_client_cmd_inventory_build(cli, msg);
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
