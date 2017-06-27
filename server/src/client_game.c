/*
** client_game.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 21:47:05 2017 Antoine Baché
** Last update Wed Jun 28 00:54:25 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_client.h"
#include "zappy_client_game.h"

void		zappy_client_game_init(t_zappy * const data,
				       t_zappy_client * const cli)
{
  assert(cli);
  cli->game.x = rand() % data->map.width;
  cli->game.y = rand() % data->map.height;
  cli->game.level = ZAPPY_CLIENT_GAME_DEFAULT_LEVEL;
  cli->game.vision = ZAPPY_CLIENT_GAME_DEFAULT_VISION;
  cli->game.inv[RES_FOOD] = ZAPPY_CLIENT_GAME_DEFAULT_FOOD;
  cli->game.orientation = rand() % NB_ORIENTATION;
}
