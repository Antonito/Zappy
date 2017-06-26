/*
** zappy_team_manager.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 19:41:24 2017 Antoine Baché
** Last update Mon Jun 26 09:49:45 2017 Antoine Baché
*/

#ifndef ZAPPY_TEAM_MANAGER_H_
#define ZAPPY_TEAM_MANAGER_H_

#include <stdint.h>

/*
** Forward declaration of t_zappy_team
*/
typedef struct		s_zappy_team	t_zappy_team;

/*
** Forward declaration of t_zappy_client
*/
typedef struct		s_zappy_client	t_zappy_client;

typedef struct		s_zappy_team_manager
{
  t_zappy_team		*team;
  int32_t		nb_teams;
  int32_t		nb_client_per_team;
}			t_zappy_team_manager;

t_zappy_team	*zappy_team_manager_get_team_by_name(char const *
						     const name,
						     t_zappy_team_manager *
						     const man);
int32_t			zappy_team_manager_add_team(char const * const name,
						    t_zappy_team_manager *
						    const man);
int32_t			zappy_team_manager_add_client(char const * const team,
						      t_zappy_client *
						      const cli,
						      t_zappy_team_manager *
						      const man);
int32_t			zappy_team_manager_get_space(int32_t const ndx,
						     t_zappy_team_manager
						     const * const man);

#endif /* !ZAPPY_TEAM_MANAGER */
