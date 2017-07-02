/*
** zappy_cleanup.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 21:02:59 2017 Antoine Baché
** Last update Fri Jun 30 21:35:43 2017 Antoine Baché
*/

#ifndef ZAPPY_CLEANUP_H_
#define ZAPPY_CLEANUP_H_

#include "zappy_admin.h"
#include "zappy_config.h"
#include "zappy_socket.h"
#include "zappy_multiplexer.h"
#include "zappy_client_list.h"
#include "zappy_team_manager.h"
#include "zappy_map.h"
#include "zappy_egg_manager.h"

/*
** Cleanup functions
** Those functions are automatically called on programs's termination
*/
void	zappy_cleanup_config(t_zappy_config * const conf);
void	zappy_cleanup_socket(t_zappy_socket * const net);
void	zappy_cleanup_multiplexer(t_zappy_multiplexer * const multiplex);
void	zappy_cleanup_clients(t_zappy_client_list_manager * const clients,
			      t_zappy * const data);
void	zappy_cleanup_teams(t_zappy_team_manager * const teams);
void	zappy_cleanup_map(t_zappy_map * const map);
void	zappy_cleanup_admin(t_zappy_admin * const admin);
void	zappy_cleanup_eggs(t_zappy_egg_manager * const man);
void    zappy_cleanup_client(t_zappy_client * const cli,
			     t_zappy * const data);
void	zappy_cleanup_cqueue(t_cqueue **queue);

#endif /* !ZAPPY_CLEANUP_H_ */
