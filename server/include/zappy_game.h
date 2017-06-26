/*
** zappy_game.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 01:19:13 2017 Antoine Baché
** Last update Sun Jun 25 01:45:15 2017 Antoine Baché
*/

#ifndef ZAPPY_GAME_H_
#define ZAPPY_GAME_H_

#include "zappy_map.h"

typedef struct		s_zappy_game
{
  t_zappy_map_case	**map;
}			t_zappy_game;

t_zappy_map_case	**zappy_create_map(int32_t const x,
					   int32_t const y);

#endif /* !ZAPPY_GAME_H_ */
