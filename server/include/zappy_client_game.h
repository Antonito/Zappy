/*
** zappy_client_game.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 23:47:31 2017 Antoine Baché
** Last update Sun Jun 25 16:46:10 2017 Antoine Baché
*/

#ifndef ZAPPY_CLIENT_GAME_H_
#define ZAPPY_CLIENT_GAME_H_

#include <stdint.h>

typedef struct			s_zappy_client_inventory
{
  int32_t			linemate;
  int32_t			deraumere;
  int32_t			sibur;
  int32_t			mendiane;
  int32_t			phiras;
  int32_t			thystame;
}				t_zappy_client_inventory;

typedef struct			s_zappy_client_game
{
  char				*team_name;
  t_zappy_client_inventory	inv;
  int32_t			x;
  int32_t			y;
  int32_t			level;
  uint8_t			padding[4];
}				t_zappy_client_game;

#endif /* !ZAPPY_CLIENT_GAME_H_ */
