/*
** multiplexer.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 16:50:48 2017 Antoine Baché
** Last update Thu Jun 29 12:13:38 2017 Antoine Baché
*/

#include <assert.h>
#include <errno.h>
#include <string.h>
#include "clogger.h"
#include "zappy_multiplexer.h"
#include "zappy_admin.h"

static void	zappy_multiplexer_add_client(t_zappy_client const *
					     const cli,
					     t_zappy_multiplexer * const data)
{
  assert(cli->net.sock != -1);
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
  assert(cli && data);
  LOG(LOG_DEBUG, "Monitoring client #%d", cli->id);
  zappy_multiplexer_add_client(cli, (t_zappy_multiplexer * const)data);
}

static void	zappy_multiplexer_clients(int32_t const server_sock,
					  t_zappy_admin * const admin,
					  t_zappy_client_list_manager *
					  const clients,
					  t_zappy_multiplexer * const data)
{
  FD_SET(server_sock, &data->readfds);
  data->max_sock = server_sock;
  if (admin->sock.sock > 0)
    {
      FD_SET(admin->sock.sock, &data->readfds);
      data->max_sock = (data->max_sock > admin->sock.sock) ?
	data->max_sock : admin->sock.sock;
      if (admin->client.sock > 0)
	{
	  FD_SET(admin->client.sock, &data->readfds);
	  if (admin->can_write)
	    FD_SET(admin->client.sock, &data->writefds);
	  data->max_sock = (data->max_sock > admin->client.sock) ?
	    data->max_sock : admin->client.sock;
	}
    }
  zappy_for_each_client(clients, data, &zappy_multiplexer_add_client_wrap);
}

int32_t		zappy_multiplexer(int32_t const server_sock,
				  t_zappy_admin * const admin_sock,
				  t_zappy_client_list_manager * const clients,
				  t_zappy_multiplexer * const data)
{
  int32_t	rc;

  assert(server_sock != -1);
  errno = EINTR;
  rc = -1;
  while (rc == -1 && errno == EINTR)
    {
      FD_ZERO(&data->readfds);
      FD_ZERO(&data->writefds);
      FD_ZERO(&data->exceptfds);
      zappy_multiplexer_clients(server_sock, admin_sock, clients, data);
      memcpy(&data->tv, &data->tv_ref, sizeof(data->tv));
      rc = select(data->max_sock + 1, &data->readfds, &data->writefds,
		  &data->exceptfds,
		  (data->tv.tv_sec > 0 || data->tv.tv_usec > 0) ?
		  &data->tv : NULL);
    }
  return (rc);
}
