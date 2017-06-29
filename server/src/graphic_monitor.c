/*
** graphic_monitor.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 23:18:36 2017 Antoine Baché
** Last update Wed Jun 28 00:25:30 2017 Antoine Baché
*/

#include <assert.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_graphic.h"

static void		zappy_graph_co_client(t_zappy_client *cli,
					      t_zappy *data)
{
  int32_t		i;
  t_zappy_client_list	*cur;
  t_zappy_graph_arg	g;

  i = 0;
  cur = data->clients.list;
  while (i < data->clients.nb_clients)
    {
      g = (t_zappy_graph_arg){ &cur->data, 0, 0 };
      zappy_graph_pnw(cli, &g, data, NULL);
      cur = cur->next;
      ++i;
    }
}

static void		zappy_graph_co_map(t_zappy_client *cli,
					   t_zappy *data)
{
  int32_t		x;
  int32_t		y;
  t_zappy_graph_arg	g;

  y = 0;
  while (y < data->map.height)
    {
      x = 0;
      while (x < data->map.width)
	{
	  g = (t_zappy_graph_arg){ &data->map.data[y][x], 0, 0 };
	  zappy_graph_bct(cli, &g, data, NULL);
	  ++x;
	}
      ++y;
    }
}

void			zappy_graph_connect(t_zappy_client *cli,
					    t_zappy * data)
{
  assert(cli && data && cli->graphical == true);
  LOG(LOG_INFO, "Connecting GRAPHICAL client");
  zappy_graph_msz(cli, data, NULL);
  zappy_graph_sgt(cli, data, NULL);
  zappy_graph_co_map(cli, data);
  zappy_graph_tna(cli, data, NULL);
  zappy_graph_co_client(cli, data);
  // TODO: send eggs (enw)
}
