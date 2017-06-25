/*
** zappy_client_game.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 23:47:31 2017 Antoine Baché
** Last update Mon Jun 26 00:03:19 2017 Antoine Baché
*/

#ifndef ZAPPY_CLIENT_GAME_H_
#define ZAPPY_CLIENT_GAME_H_

#include <stdint.h>

/*
** Forward declaration of t_zappy_client
*/
typedef struct			s_zappy_client	t_zappy_client;

typedef struct			s_zappy_client_inventory
{
  int32_t			linemate;
  int32_t			deraumere;
  int32_t			sibur;
  int32_t			mendiane;
  int32_t			phiras;
  int32_t			thystame;
  int32_t			food;
}				t_zappy_client_inventory;

typedef struct			s_zappy_client_game
{
  char				*team_name;
  t_zappy_client_inventory	inv;
  int32_t			team_id;
  int32_t			x;
  int32_t			y;
  int32_t			level;
  int32_t			vision;
}				t_zappy_client_game;

void				zappy_client_game_init(t_zappy_client *
						       const cli);

#endif /* !ZAPPY_CLIENT_GAME_H_ */
