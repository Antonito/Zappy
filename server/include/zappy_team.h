/*
** zappy_team.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 19:38:53 2017 Antoine Baché
** Last update Sun Jun 25 19:40:56 2017 Antoine Baché
*/

#ifndef ZAPPY_TEAM_H_
#define ZAPPY_TEAM_H_

#include <stdint.h>

typedef struct		s_zappy_team
{
  char const		*name;
  int32_t		id;
  int32_t		nb_players;
}			t_zappy_team;

#endif /* !ZAPPY_TEAM_H_ */
