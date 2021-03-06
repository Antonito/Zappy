/*
** zappy_client_list.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 16:59:51 2017 Antoine Baché
** Last update Thu Jun 29 12:35:17 2017 Antoine Baché
*/

#ifndef ZAPPY_CLIENT_LIST
#define ZAPPY_CLIENT_LIST

#include <stdint.h>
#include "zappy_client.h"

/*
** Forward declaration of t_zappy
*/
typedef struct s_zappy			t_zappy;

typedef struct s_zappy_client_list	t_zappy_client_list;

/*
** Double linked list of clients
*/
struct					s_zappy_client_list
{
  t_zappy_client			data;
  t_zappy_client_list			*next;
  t_zappy_client_list			*prev;
};

/*
** Client list meta-datas, allows a better handling of them
*/
typedef struct				s_zappy_client_list_manager
{
  uint64_t				next_action;
  t_zappy_client_list			*list;
  int32_t				nb_clients;
  bool					has_player;
  uint8_t				padding[3];
}					t_zappy_client_list_manager;

/*
** const forearch
*/
void	zappy_for_each_client(t_zappy_client_list_manager *list,
			      void *data,
			      void (*func)(t_zappy_client const * const,
					   void *data));

/*
** Non-const version of the foreach
*/
void	_zappy_for_each_client(t_zappy_client_list_manager *list,
			       void *data,
			       void (*func)(t_zappy_client * const,
					    void *data));

/*
** Add a client to the list
*/
int32_t	zappy_client_add(t_zappy * const data,
			 t_sock const socket,
			 t_sockaddr_in *addr, socklen_t len);

/*
** Remove a client from the list
*/
int32_t	zappy_client_remove(t_zappy_client_list_manager * const list,
			    t_zappy_client_list * const cur,
			    t_zappy * const data);

/*
** Remove all disconnected clients from the list
*/
void	zappy_client_purify_list(t_zappy_client_list_manager * const list,
				 t_zappy * const data);

#endif /* !ZAPPY_CLIENT_LIST */
