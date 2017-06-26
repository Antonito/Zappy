/*
** zappy_client_game.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 23:47:31 2017 Antoine Baché
** Last update Mon Jun 26 13:13:58 2017 Antoine Baché
*/

#ifndef ZAPPY_CLIENT_GAME_H_
#define ZAPPY_CLIENT_GAME_H_

#include <stdint.h>
#include "zappy_resource.h"

#define ZAPPY_CLIENT_GAME_DEFAULT_LEVEL		(1)
#define ZAPPY_CLIENT_GAME_DEFAULT_VISION	(1)
#define ZAPPY_CLIENT_GAME_DEFAULT_FOOD		(10)

/*
** Forward declaration of t_zappy_client
*/
typedef struct			s_zappy_client	t_zappy_client;

typedef struct			s_zappy_client_game
{
  char				*team_name;
  int32_t			inv[NB_RESOURCE];
  int32_t			team_id;
  int32_t			x;
  int32_t			y;
  int32_t			level;
  int32_t			vision;
}				t_zappy_client_game;

void				zappy_client_game_init(t_zappy_client *
						       const cli);

#endif /* !ZAPPY_CLIENT_GAME_H_ */
