/*
** zappy_admin.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 19:28:17 2017 Antoine Baché
** Last update Sun Jul  2 22:46:03 2017 Antoine Baché
*/

#ifndef ZAPPY_ADMIN_H_
#define ZAPPY_ADMIN_H_

#include <stdbool.h>
#include <stdio.h>
#include "zappy_socket.h"
#include "zappy_ring_buffer.h"

#if defined(__GNUC__)
#define ZAPPY_PRINT_ARG __attribute__((__format__ (__printf__, 2, 0)))
#else
#define ZAPPY_PRINT_ARG
#endif

/*
** Forward declaration of t_zappy
*/
typedef struct		s_zappy	t_zappy;

typedef struct		s_zappy_admin
{
  t_zappy_ring_buffer	buff;
  t_zappy_socket	sock;
  t_zappy_socket	client;
  FILE			*sock_stream;
  bool			can_write;
  bool			authenticated;
  uint8_t		padding[6];
}			t_zappy_admin;

int32_t			zappy_start_admin(t_zappy * const data);
void			zappy_admin_accept(t_zappy * const data);
void			zappy_admin_disconnect(t_zappy_admin * const adm);
void			zappy_admin_read(t_zappy * const data);
void			zappy_admin_write(t_zappy * const data);
void			zappy_admin_authenticate(t_zappy * const data,
						 char const * const pass);

#endif /* !ZAPPY_ADMIN_H_ */
