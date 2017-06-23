/*
** cleanup.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 21:07:21 2017 Antoine Baché
** Last update Fri Jun 23 21:17:10 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "clogger.h"
#include "zappy_cleanup.h"

void			zappy_cleanup_config(t_zappy_config * const conf)
{
  LOG(LOG_DEBUG, "Cleaning conf");
  assert(conf);
  (void)conf;
}

void			zappy_cleanup_socket(t_zappy_socket * const net)
{
  LOG(LOG_DEBUG, "Cleaning net");
  assert(net);
  if (net->sock > 0)
    {
      closesocket(net->sock);
      net->sock = -1;
    }
}

void			zappy_cleanup_multiplexer(t_zappy_multiplexer *
						  const multiplex)
{
  LOG(LOG_DEBUG, "Cleaning multiplexer");
  assert(multiplex);
  (void)multiplex;
}

static void		zappy_cleanup_client(t_zappy_client * const cli)
{
  LOG(LOG_DEBUG, "Cleaning single client");
  assert(cli);
  if (cli->net.sock > 0)
    {
      closesocket(cli->net.sock);
      cli->net.sock = -1;
    }
}

void			zappy_cleanup_clients(t_zappy_client_list_manager *
					      const clients)
{
  int32_t		i;
  t_zappy_client_list	*list;
  t_zappy_client_list	*tmp;

  LOG(LOG_DEBUG, "Cleaning clients");
  assert(clients);
  i = 0;
  list = clients->list;
  while (i < clients->nb_clients)
    {
      tmp = list;
      zappy_cleanup_client(&tmp->data);
      list = list->next;
      free(tmp);
      ++i;
    }
}
