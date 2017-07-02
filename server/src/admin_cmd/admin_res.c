/*
** admin_info.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jul  1 18:32:27 2017 Antoine Baché
** Last update Sun Jul  2 23:14:41 2017 Antoine Baché
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_admin_cmd.h"
#include "zappy_graphic.h"
#include "zappy_team.h"
#include "zappy_resource.h"

void			zappy_admin_update_tile(int32_t const x,
						int32_t const y,
						t_zappy * const data)
{
  t_zappy_graph_arg	g;

  g = (t_zappy_graph_arg){ &data->map.data[y][x], 0, 0 };
  zappy_graph_send(&g, data, NULL, &zappy_graph_bct);
}

void			zappy_admin_cmd_res(t_zappy * const data,
					    int32_t const res)
{
  int32_t		x;
  int32_t		y;

  assert(data && data->admin.authenticated == true);
  LOG(LOG_DEBUG, "Treating Admin command resource");
  x = rand() % data->map.width;
  y = rand() % data->map.height;
  zappy_adm_send(data, "Spawned %s at %dx%d\n",
		 zappy_get_resource_by_id(res), x, y);
  ++data->map.data[y][x].content[res];
  zappy_admin_update_tile(x, y, data);
}

void			zappy_admin_cmd_res_rand(t_zappy * const data,
						 char const * cmd)
{
  int32_t		res;

  (void)cmd;
  res = rand() % NB_RESOURCE;
  zappy_admin_cmd_res(data, res);
}

void			zappy_admin_cmd_res_food(t_zappy * const data,
						 char const * cmd)
{
  int32_t		res;

  (void)cmd;
  res = RES_FOOD;
  zappy_admin_cmd_res(data, res);
}

void			zappy_admin_cmd_res_linemate(t_zappy * const data,
						     char const * cmd)
{
  int32_t		res;

  (void)cmd;
  res = RES_LINEMATE;
  zappy_admin_cmd_res(data, res);
}
