/*
** io.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 17:40:19 2017 Antoine Baché
** Last update Mon Jun 26 21:44:50 2017 Antoine Baché
*/

#include <assert.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_server.h"
#include "zappy_multiplexer.h"

static void     zappy_io_client(t_zappy_client * const cli,
				void *_data)
{
  t_zappy	*data;

  assert(cli && _data);
  LOG(LOG_DEBUG, "Checking I/O of client #%d", cli->id);
  data = _data;
  if (cli->connected && FD_ISSET(cli->net.sock, &data->multiplex.readfds))
    {
      zappy_client_read(cli, data);
    }
  if (cli->connected && FD_ISSET(cli->net.sock, &data->multiplex.writefds))
    {
      zappy_client_write(cli, data);
    }
  if (cli->connected && FD_ISSET(cli->net.sock, &data->multiplex.exceptfds))
    {
      zappy_client_except(cli, data);
    }
}

void		zappy_io(t_zappy * const data)
{
  if (FD_ISSET(data->net.sock, &data->multiplex.readfds))
    {
      zappy_server_accept(data);
    }
  if (FD_ISSET(data->admin.sock.sock, &data->multiplex.readfds))
    {
      zappy_admin_accept(data);
    }
  if (data->admin.client.sock != -1)
    {
      if (FD_ISSET(data->admin.client.sock, &data->multiplex.readfds))
	{
	  zappy_admin_read(data);
	}
      if (FD_ISSET(data->admin.client.sock, &data->multiplex.writefds))
	{
	  zappy_admin_write(data);
	}
    }
  _zappy_for_each_client(&data->clients, data, &zappy_io_client);
}
