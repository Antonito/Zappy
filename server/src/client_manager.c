/*
** client_manager.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 17:42:50 2017 Antoine Baché
** Last update Sun Jun 25 18:21:27 2017 Antoine Baché
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "clogger.h"
#include "zappy_color.h"
#include "zappy_client_list.h"
#include "zappy_cleanup.h"

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
      cli = cli->next;
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
      cli = cli->next;
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
  zappy_client_print(&elem->data, YELLOW_BOLD_INTENS"New client"CLEAR);
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
					    t_zappy_client_list *
					    const cur)
{
  LOG(LOG_INFO, YELLOW_BOLD_INTENS"Disconnecting client %d"
      CLEAR, cur->data.id);
  assert(list && cur);
  assert(list->nb_clients > 0);
  if (cur->prev)
    {
      assert(cur->prev->next == cur);
      cur->prev->next = cur->next;
    }
  else
    list->list = cur->next;
  if (cur->next)
    {
      assert(cur->next->prev == cur);
      cur->next->prev = cur->prev;
    }
  zappy_cleanup_client(&cur->data);
  free(cur);
  --list->nb_clients;
  assert(list->nb_clients >= 0);
  return (0);
}

void			zappy_client_purify_list(t_zappy_client_list_manager *
						 const list)
{
  int32_t		i;
  t_zappy_client_list	*cur;
  t_zappy_client_list	*tmp;

  LOG(LOG_DEBUG, "Purifying client list...");
  i = 0;
  cur = list->list;
  while (i < list->nb_clients)
    {
      tmp = cur->next;
      LOG(LOG_DEBUG, "Checking client %d", cur->data.id);
      if (cur->data.connected == false)
	{
	  zappy_client_remove(list, cur);
	}
      else
	{
	  ++i;
	}
      cur = tmp;
    }
}
