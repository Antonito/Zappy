/*
** logic.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 22:35:31 2017 Antoine Baché
** Last update Sat Jul  1 17:59:05 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include <inttypes.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_logic.h"
#include "zappy_client_serial.h"
#include "zappy_client_cmd.h"
#include "zappy_time.h"
#include "zappy_math.h"

static void		zappy_logic_ticks(t_zappy_client * const cli,
					  t_zappy * const data)
{
  t_cqueue		*cur;
  t_zappy_client_serial	*order;

  cur = cqueue_get_front(cli->input_queue);
  if (cur)
    {
      order = cur->data;
      if (data->clients.next_action == 0)
	{
	  data->clients.next_action = order->exec_time;
	}
      else
	{
	  data->clients.next_action = ZAPPY_MIN(data->clients.next_action,
						order->exec_time);
	}
    }
  if (data->clients.next_action == 0)
    data->clients.next_action = cli->game.food_time;
  else
    data->clients.next_action = ZAPPY_MIN(data->clients.next_action,
					  cli->game.food_time);
}

static void		zappy_logic_client(t_zappy_client * const cli,
					   t_zappy * const data,
					   uint64_t const cur_time)
{
  t_cqueue		*cur;
  t_zappy_client_serial	*order;

  assert(cli->graphical == false);
  while (!cqueue_is_empty(cli->input_queue))
    {
      cur = cqueue_get_front(cli->input_queue);
      order = cur->data;
      if (order->exec_time > cur_time)
	break;
      cqueue_pop(&cli->input_queue);
      order->callback(cli, data, order->buff);
      zappy_free_serial(order);
      zappy_free_cqueue(cur);
    }
  zappy_logic_ticks(cli, data);
}

static void		zappy_logic_client_wrap(t_zappy_client * const cli,
						void *data)
{
  t_zappy		*zap;
  uint64_t		cur_time;

  assert(cli && data);
  zap = data;
  if (cli->connected && cli->state == CLI_CONNECTED
      && !cli->graphical && cli->authenticated)
    {
      cur_time = zappy_get_cur_time();
      if (cur_time >= cli->game.food_time)
	{
	  LOG(LOG_DEBUG, "Removing 1 food");
	  --cli->game.inv[RES_FOOD];
	  cli->game.food_time = (uint64_t)((126 * 1000) / zap->conf.freq)
	    + cur_time;
	}
      if (cli->game.inv[RES_FOOD] == 0)
	{
	  zappy_client_cmd_dead(cli, data, NULL);
	  return ;
	}
      zappy_logic_client(cli, data, cur_time);
    }
}

static void		zappy_treat_global_events(t_zappy * const data)
{
  t_cqueue		*cur;
  t_zappy_client_serial	*order;
  uint64_t		cur_time;

  while (!cqueue_is_empty(data->glob_events))
    {
      cur_time = zappy_get_cur_time();
      cur = cqueue_get_front(data->glob_events);
      order = cur->data;
      if (order->exec_time > cur_time)
	break;
      cqueue_pop(&data->glob_events);
      order->callback(NULL, data, NULL);
      zappy_free_serial(order);
      zappy_free_cqueue(cur);
    }
}

bool			zappy_logic(t_zappy * const data)
{
  uint64_t		cur_time;

  if (data->clients.has_player)
    {
      _zappy_for_each_client(&data->clients, data, &zappy_logic_client_wrap);
    }
  zappy_treat_global_events(data);
  zappy_client_purify_list(&data->clients, data);
  if (data->clients.has_player)
    {
      cur_time = zappy_get_cur_time() + 1000;
      if (data->clients.next_action <= cur_time)
	cur_time = 1;
      else
	cur_time = data->clients.next_action - cur_time;
      data->multiplex.tv_ref.tv_sec = cur_time / 1000;
      data->multiplex.tv_ref.tv_usec = cur_time % 1000;
      data->clients.next_action = 0;
      return (zappy_has_winner(data));
    }
  return (false);
}
