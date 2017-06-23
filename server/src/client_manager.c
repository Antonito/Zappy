/*
** client_manager.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 17:42:50 2017 Antoine Baché
** Last update Fri Jun 23 21:41:50 2017 Antoine Baché
*/

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

  i = 0;
  cli = list->list;
  while (i < list->nb_clients)
    {
      func(&cli->data, data);
      ++i;
    }
}

int32_t			zappy_client_add(t_zappy_client_list_manager *
					 const list)
{
  // TODO
  (void)list;
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
