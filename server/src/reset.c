/*
** reset.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Thu Jun 29 16:29:53 2017 Antoine Baché
** Last update Sat Jul  1 18:02:15 2017 Antoine Baché
*/

#include <assert.h>
#include <string.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_cleanup.h"
#include "zappy_team_manager.h"

static void	zappy_cleanup_global_events(t_zappy * const data)
{
  t_cqueue	*cur;

  assert(data);
  LOG(LOG_DEBUG, "Cleaning global events");
  while (!cqueue_is_empty(data->glob_events))
    {
      cur = cqueue_get_front(data->glob_events);
      cqueue_pop(&data->glob_events);
      zappy_free_serial(cur->data);
      zappy_free_cqueue(cur);
    }
}

void		zappy_reset(t_zappy * const data)
{
  assert(data);
  LOG(LOG_INFO, "Reseting game");
  zappy_cleanup_socket(&data->net);
  zappy_cleanup_multiplexer(&data->multiplex);
  zappy_cleanup_clients(&data->clients, data);
  zappy_cleanup_config(&data->conf);
  zappy_cleanup_map(&data->map);
  zappy_cleanup_eggs(&data->egg_manager);
  zappy_cleanup_admin(&data->admin);
  zappy_cleanup_global_events(data);
  memset(data, 0, sizeof(*data));
}
