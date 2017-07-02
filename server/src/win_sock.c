/*
** win_sock.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jul  2 20:59:23 2017 Antoine Baché
** Last update Sun Jul  2 21:03:25 2017 Antoine Baché
*/

#include <stdbool.h>
#include "zappy_network_gen.h"

bool		zappy_winsock_init(void)
{
  WSADATA	wsa;

  if (WSAStartup(MAKEWORD(2, 2), &wsa) < 0)
    {
      return (false);
    }
  return (true);
}

void		zappy_winsock_deinit(void)
{
  WSACleanup();
}
