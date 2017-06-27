/*
** client_for_each.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 15:05:16 2017 Antoine Baché
** Last update Mon Jun 26 15:09:24 2017 Antoine Baché
*/

#include <assert.h>
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
