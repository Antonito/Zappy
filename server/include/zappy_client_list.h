/*
** zappy_client_list.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 16:59:51 2017 Antoine Baché
** Last update Fri Jun 23 21:37:32 2017 Antoine Baché
*/

#ifndef ZAPPY_CLIENT_LIST
#define ZAPPY_CLIENT_LIST

#include <stdint.h>
#include "zappy_client.h"

typedef struct s_zappy_client_list	t_zappy_client_list;

struct					s_zappy_client_list
{
  t_zappy_client			data;
  t_zappy_client_list			*next;
  t_zappy_client_list			*prev;
};

typedef struct				s_zappy_client_list_manager
{
  t_zappy_client_list			*list;
  int32_t				nb_clients;
}					t_zappy_client_list_manager;

void	zappy_for_each_client(t_zappy_client_list_manager *list,
			      void *data,
			      void (*func)(t_zappy_client const * const,
					   void *data));
int32_t	zappy_client_add(t_zappy_client_list_manager * const list);
int32_t	zappy_client_remove(t_zappy_client_list_manager * const list,
			    t_zappy_client const * const data);
void	zappy_client_purify_list(t_zappy_client_list_manager * const list);

#endif /* !ZAPPY_CLIENT_LIST */
