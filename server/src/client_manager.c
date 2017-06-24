/*
** client_manager.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 17:42:50 2017 Antoine Baché
** Last update Sat Jun 24 12:44:04 2017 Antoine Baché
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "clogger.h"
#include "zappy_client_list.h"

void			zappy_for_each_client(t_zappy_client_list_manager *
					      list,
					      void *data,
					      void (*func)
					      (t_zappy_client const *
					       const cli,
					       void *data))
{
  int32_t		i;
  t_zappy_client_list	*cli;

  assert(list && func);
  i = 0;
  cli = list->list;
  while (i < list->nb_clients)
    {
      func(&cli->data, data);
      ++i;
    }
}

void			_zappy_for_each_client(t_zappy_client_list_manager *
					       list,
					       void *data,
					       void (*func)
					       (t_zappy_client *
						const cli,
						void *data))
{
  int32_t		i;
  t_zappy_client_list	*cli;

  assert(list && func);
  i = 0;
  cli = list->list;
  while (i < list->nb_clients)
    {
      func(&cli->data, data);
      ++i;
    }
}

int32_t			zappy_client_add(t_zappy_client_list_manager *
					 const list, t_sock const socket,
					 t_sockaddr_in *addr,
					 socklen_t const len)
{
  t_zappy_client_list	*elem;
  t_zappy_client_list	*tmp;

  assert(list && socket > 0 && addr);
  if (!(elem = calloc(1, sizeof(*elem))))
    {
      LOG(LOG_WARNING, "Cannot accept client: %s [%s]",
	  inet_ntoa(addr->sin_addr), strerror(errno));
      return (1);
    }
  zappy_client_fill(&elem->data, socket, addr, len);
  elem->data.id = list->nb_clients;
  zappy_client_print(&elem->data, "New client");
  tmp = list->list;
  while (tmp && tmp->next)
    tmp = tmp->next;
  if (!tmp)
    list->list = elem;
  else
    {
      tmp->next = elem;
      elem->prev = tmp;
    }
  ++list->nb_clients;
  return (0);
}

int32_t			zappy_client_remove(t_zappy_client_list_manager *
					    const list,
					    t_zappy_client const *
					    const data)
{
  // TODO
  (void)list, (void)data;
  return (0);
}

void			zappy_client_purify_list(t_zappy_client_list_manager *
						 const list)
{
  // TODO: Remove all disconnected clients
  (void)list;
}
