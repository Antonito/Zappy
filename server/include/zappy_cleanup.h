/*
** zappy_cleanup.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 21:02:59 2017 Antoine Baché
** Last update Fri Jun 23 21:05:37 2017 Antoine Baché
*/

#ifndef ZAPPY_CLEANUP_H_
#define ZAPPY_CLEANUP_H_

#include "zappy_config.h"
#include "zappy_socket.h"
#include "zappy_multiplexer.h"
#include "zappy_client_list.h"

void	zappy_cleanup_config(t_zappy_config * const conf);
void	zappy_cleanup_socket(t_zappy_socket * const net);
void	zappy_cleanup_multiplexer(t_zappy_multiplexer * const multiplex);
void	zappy_cleanup_clients(t_zappy_client_list_manager * const clients);

#endif /* !ZAPPY_CLEANUP_H_ */
