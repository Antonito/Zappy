/*
** graphic_cmd.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 21:48:00 2017 Antoine Baché
** Last update Tue Jun 27 22:57:01 2017 Antoine Baché
*/

#include "zappy.h"
#include "zappy_client_list.h"
#include "zappy_graphic.h"

static void			zappy_graph_exec(t_zappy_client * const cur,
						 void *_data)
{
  t_zappy_graph_callback	*call;

  call = _data;
  if (cur->graphical)
    {
      call->handle(cur, call->g, call->data, call->arg);
    }
}

void				zappy_graph_send(t_zappy_graph_arg *g,
						 t_zappy *data,
						 char const * const arg,
						 t_zappy_graphic_handle handle)
{
  t_zappy_graph_callback	call;

  call.g = g;
  call.data = data;
  call.arg = arg;
  call.handle = handle;
  _zappy_for_each_client(&data->clients, &call, &zappy_graph_exec);
}
