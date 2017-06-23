/*
** io.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 17:40:19 2017 Antoine Baché
** Last update Fri Jun 23 21:41:01 2017 Antoine Baché
*/

#include "clogger.h"
#include "zappy.h"
#include "zappy_server.h"
#include "zappy_multiplexer.h"

void		zappy_io_client(t_zappy_client const * const cli,
				void *_data)
{
  t_zappy	*data;

  data = _data;
  if (cli->connected && FD_ISSET(cli->net.sock, &data->multiplex.readfds))
    {
    }
  if (cli->connected && FD_ISSET(cli->net.sock, &data->multiplex.writefds))
    {
    }
  if (cli->connected && FD_ISSET(cli->net.sock, &data->multiplex.exceptfds))
    {
    }
}

void		zappy_io(t_zappy * const data)
{
  if (FD_ISSET(data->net.sock, &data->multiplex.readfds))
    {
      zappy_server_accept(data);
    }
  zappy_for_each_client(&data->clients, data, &zappy_io_client);
  zappy_client_purify_list(&data->clients);
}
