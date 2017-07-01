/*
** zappy_team.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 19:38:53 2017 Antoine Baché
** Last update Thu Jun 29 17:41:34 2017 Antoine Baché
*/

#ifndef ZAPPY_TEAM_H_
#define ZAPPY_TEAM_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct		s_zappy_team
{
  char const		*name;
  int32_t		id;
  int32_t		nb_players;
  int32_t		nb_players_max;
  int32_t		nb_player_lvl_max;
}			t_zappy_team;

#endif /* !ZAPPY_TEAM_H_ */
