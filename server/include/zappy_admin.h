/*
** zappy_admin.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 19:28:17 2017 Antoine Baché
** Last update Mon Jun 26 19:48:49 2017 Antoine Baché
*/

#ifndef ZAPPY_ADMIN_H_
#define ZAPPY_ADMIN_H_

#include <stdbool.h>
#include "zappy_socket.h"

/*
** Forward declaration of t_zappy
*/
typedef struct		s_zappy	t_zappy;

typedef struct		s_zappy_admin
{
  t_zappy_socket	sock;
  bool			can_write;
  uint8_t	        padding[7];
}			t_zappy_admin;

int32_t			zappy_start_admin(t_zappy * const data);

#endif /* !ZAPPY_ADMIN_H_ */
