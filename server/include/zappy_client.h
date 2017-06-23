/*
** zappy_client.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 16:58:03 2017 Antoine Baché
** Last update Fri Jun 23 21:37:46 2017 Antoine Baché
*/

#ifndef ZAPPY_CLIENT_H_
#define ZAPPY_CLIENT_H_

#include <stdbool.h>
#include "zappy_socket.h"

typedef struct		s_zappy_client
{
  t_zappy_socket	net;
  bool			can_write;
  bool			connected;
}			t_zappy_client;

#endif /* !ZAPPY_CLIENT_H_ */
