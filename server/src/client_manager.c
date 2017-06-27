/*
** client_manager.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 17:42:50 2017 Antoine Baché
** Last update Wed Jun 28 01:18:56 2017 Antoine Baché
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_color.h"
#include "zappy_client_list.h"
#include "zappy_cleanup.h"
#include "zappy_graphic.h"

static void		zappy_client_add_list(t_zappy_client_list_manager *
					      const list,
					      t_zappy_client_list *elem)
{
  t_zappy_client_list	*tmp;

  assert(list && elem);
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
}

int32_t			zappy_client_add(t_zappy * const data,
					 t_sock const socket,
					 t_sockaddr_in *addr,
					 socklen_t const len)
{
  t_zappy_client_list	*elem;

  assert(data && socket > 0 && addr);
  if (!(elem = calloc(1, sizeof(*elem))))
    {
      LOG(LOG_WARNING, "Cannot accept client: %s [%s]",
	  inet_ntoa(addr->sin_addr), strerror(errno));
      return (1);
    }
  memset(&elem->data, 0, sizeof(t_zappy_client));
  elem->data.net.sock = socket;
  elem->data.id = data->clients.nb_clients;
  zappy_client_fill(&elem->data, data, addr, len);
  LOG(LOG_INFO, YELLOW_BOLD_INTENS"%s #%d: %s"CLEAR, "New client",
      elem->data.id,
      inet_ntoa(elem->data.net.addr.sin_addr));
  zappy_client_add_list(&data->clients, elem);
  return (0);
}

int32_t			zappy_client_remove(t_zappy_client_list_manager *
					    const list,
					    t_zappy_client_list *
					    const cur,
					    t_zappy * const data)
{
  LOG(LOG_INFO, YELLOW_BOLD_INTENS"Disconnecting client %d"
      CLEAR, cur->data.id);
  assert(list && cur && data);
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
  if (cur->data.game.team_name)
    zappy_team_manager_delete_client(cur->data.game.team_name,
				     &data->conf.teams);
  zappy_cleanup_client(&cur->data);
  free(cur);
  --list->nb_clients;
  assert(list->nb_clients >= 0);
  return (0);
}

static void		zappy_client_rm_wrap(t_zappy_client_list_manager *
					     const list,
					     t_zappy_client_list *cur,
					     t_zappy * const data)
{
  t_zappy_graph_arg	g;

  --data->map.data[cur->data.game.y][cur->data.game.x].nb_players;
  data->map.data[cur->data.game.y][cur->data.game.x].
    player[cur->data.id] = NULL;
  zappy_client_remove(list, cur, data);
  if (cur->data.state >= CLI_CONNECTED)
    {
      g = (t_zappy_graph_arg){ &cur->data, 0, 0 };
      zappy_graph_send(&g, data, NULL, &zappy_graph_pdi);
    }
}

void			zappy_client_purify_list(t_zappy_client_list_manager *
						 const list,
						 t_zappy * const data)
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
	  zappy_client_rm_wrap(list, cur, data);
	}
      else
	{
	  ++i;
	}
      cur = tmp;
    }
}
