/*
** logic.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 22:35:31 2017 Antoine Baché
** Last update Sun Jun 25 17:45:02 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_logic.h"
#include "zappy_client_serial.h"

static void		zappy_logic_client(t_zappy_client * const cli,
					   t_zappy * const data)
{
  t_cqueue		*cur;
  t_zappy_client_serial	*order;

  // TODO: order cqueue by time
  cur = cqueue_get_front(cli->input_queue);
  if (cur)
    {
      order = cur->data;
      LOG(LOG_DEBUG, "Logic: Order to treat");
      cqueue_pop(&cli->input_queue);
      order->callback(cli, data, order->buff);
      zappy_free_serial(order);
      zappy_free_cqueue(cur);
    }
}

static void		zappy_logic_client_wrap(t_zappy_client * const cli,
						void *data)
{
  assert(cli && data);
  if (cli->connected && cli->state == CLI_CONNECTED
      && !cli->graphical)
    {
      zappy_logic_client(cli, data);
    }
}

void			zappy_logic(t_zappy * const data)
{
  LOG(LOG_DEBUG, "Processing Game Logic");
  _zappy_for_each_client(&data->clients, data, &zappy_logic_client_wrap);
  zappy_client_purify_list(&data->clients);
}
