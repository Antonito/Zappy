/*
** multiplexer.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 16:50:48 2017 Antoine Baché
** Last update Fri Jun 23 17:21:34 2017 Antoine Baché
*/

#include <assert.h>
#include <errno.h>
#include "zappy_multiplexer.h"

static void	zappy_multiplexer_add_client(t_zappy_client const *
					     const cli,
					     t_zappy_multiplexer * const data)
{
  assert(cli && data && cli->net.sock != -1);
  if (cli->net.sock > data->max_sock)
    {
      data->max_sock = cli->net.sock;
    }
  FD_SET(cli->net.sock, &data->readfds);
  FD_SET(cli->net.sock, &data->exceptfds);
  if (cli->can_write)
    {
      FD_SET(cli->net.sock, &data->writefds);
    }
}

static void	zappy_multiplexer_add_client_wrap(t_zappy_client const *
						  const cli,
						  void * const data)
{
  zappy_multiplexer_add_client(cli, (t_zappy_multiplexer * const)data);
}

static void	zappy_multiplexer_clients(t_zappy_client_list_manager *
					  const clients,
					  t_zappy_multiplexer * const data)
{
  FD_SET(STDIN_FILENO, &data->readfds);
  data->max_sock = STDIN_FILENO;
  zappy_for_each_client(clients, data, &zappy_multiplexer_add_client_wrap);
}

int32_t		zappy_multiplexer(t_zappy_client_list_manager * const clients,
				  t_zappy_multiplexer * const data)
{
  int32_t	rc;

  errno = EINTR;
  rc = -1;
  while (rc == -1 && errno == EINTR)
    {
      FD_ZERO(&data->readfds);
      FD_ZERO(&data->writefds);
      FD_ZERO(&data->exceptfds);
      zappy_multiplexer_clients(clients, data);
      rc = select(data->max_sock + 1, &data->readfds, &data->writefds,
		  &data->exceptfds, &data->tv);
    }
  return (rc);
}
