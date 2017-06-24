/*
** cleanup_client.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 14:16:40 2017 Antoine Baché
** Last update Sat Jun 24 14:30:14 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy_cleanup.h"
#include "zappy_message.h"

void			zappy_cleanup_cqueue(t_cqueue **queue)
{
  t_cqueue		*to_clean;

  while (!cqueue_is_empty(*queue))
    {
      to_clean = cqueue_get_front(*queue);
      cqueue_pop(queue);
      zappy_message_clean(to_clean->data);
      free(to_clean->data);
      free(to_clean);
    }
}

void			zappy_cleanup_client(t_zappy_client * const cli)
{
  LOG(LOG_DEBUG, "Cleaning single client");
  assert(cli);
  if (cli->net.sock > 0)
    {
      closesocket(cli->net.sock);
      cli->net.sock = -1;
    }
  zappy_cleanup_cqueue(&cli->input_queue);
  zappy_cleanup_cqueue(&cli->output_queue);
}
