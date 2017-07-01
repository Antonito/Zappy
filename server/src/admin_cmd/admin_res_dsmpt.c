/*
** admin_res_dsmpt.c for zappy in PSU_2016_zappy/server/src/admin_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jul  1 20:53:10 2017 Antoine Baché
** Last update Sat Jul  1 20:53:42 2017 Antoine Baché
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

void			zappy_admin_cmd_res_deraumere(t_zappy * const data)
{
  int32_t		res;

  res = RES_DERAUMERE;
  zappy_admin_cmd_res(data, res);
}

void			zappy_admin_cmd_res_sibur(t_zappy * const data)
{
  int32_t		res;

  res = RES_SIBUR;
  zappy_admin_cmd_res(data, res);
}

void			zappy_admin_cmd_res_mendiane(t_zappy * const data)
{
  int32_t		res;

  res = RES_MENDIANE;
  zappy_admin_cmd_res(data, res);
}

void			zappy_admin_cmd_res_phiras(t_zappy * const data)
{
  int32_t		res;

  res = RES_PHIRAS;
  zappy_admin_cmd_res(data, res);
}

void			zappy_admin_cmd_res_thystame(t_zappy * const data)
{
  int32_t		res;

  res = RES_THYSTAME;
  zappy_admin_cmd_res(data, res);
}
