/*
** broadcast.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:29:34 2017 Antoine Baché
** Last update Tue Jun 27 23:03:57 2017 Antoine Baché
*/

#include "clogger.h"
#include "zappy.h"
#include "zappy_client.h"
#include "zappy_client_cmd.h"
#include "zappy_graphic.h"

void			zappy_client_cmd_broadcast(t_zappy_client * const cli,
						   t_zappy * const data,
						   char const * const arg)
{
  t_zappy_graph_arg	g;

  LOG(LOG_DEBUG, "Treating broadcast \'%s\' command", arg);
  (void)cli, (void)data, (void)arg;
  g = (t_zappy_graph_arg){ cli, 0, 0 };
  zappy_graph_send(&g, data, arg, &zappy_graph_pbc);
}
