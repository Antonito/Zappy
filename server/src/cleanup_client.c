/*
** cleanup_client.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 14:16:40 2017 Antoine Baché
** Last update Fri Jun 30 21:37:53 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_cleanup.h"
#include "zappy_message.h"

static void		zappy_cleanup_cqueue_serial(t_cqueue **queue)
{
  t_cqueue		*to_clean;

  while (!cqueue_is_empty(*queue))
    {
      to_clean = cqueue_get_front(*queue);
      cqueue_pop(queue);
      zappy_free_serial(to_clean->data);
      zappy_free_cqueue(to_clean);
    }
}

void			zappy_cleanup_cqueue(t_cqueue **queue)
{
  t_cqueue		*to_clean;

  while (!cqueue_is_empty(*queue))
    {
      to_clean = cqueue_get_front(*queue);
      cqueue_pop(queue);
      zappy_message_clean(to_clean->data);
      zappy_free_message(to_clean->data);
      zappy_free_cqueue(to_clean);
    }
}

void			zappy_cleanup_client(t_zappy_client * const cli,
					     t_zappy *const data)
{
  LOG(LOG_DEBUG, "Cleaning single client");
  assert(cli);
  if (cli->game.team_name && cli->authenticated)
    zappy_team_manager_delete_client(cli->game.team_name,
				     &data->conf.teams);
  data->map.data[cli->game.y][cli->game.x].player[cli->id] = NULL;
  if (cli->net.sock > 0)
    {
      closesocket(cli->net.sock);
      cli->net.sock = -1;
    }
  free(cli->game.team_name);
  cli->game.team_name = NULL;
  zappy_cleanup_cqueue_serial(&cli->input_queue);
  zappy_cleanup_cqueue(&cli->output_queue);
}
