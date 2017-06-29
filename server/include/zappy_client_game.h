/*
** zappy_client_game.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 23:47:31 2017 Antoine Baché
** Last update Thu Jun 29 17:52:40 2017 Antoine Baché
*/

#ifndef ZAPPY_CLIENT_GAME_H_
#define ZAPPY_CLIENT_GAME_H_

#include <stdint.h>
#include "zappy_resource.h"

#define ZAPPY_CLIENT_GAME_DEFAULT_LEVEL		(1)
#define ZAPPY_CLIENT_GAME_DEFAULT_VISION	(1)
#define ZAPPY_CLIENT_GAME_DEFAULT_FOOD		(10)

/*
** Forward declaration of t_zappy
*/
typedef struct			s_zappy		t_zappy;

/*
** Forward declaration of t_zappy_config
*/
typedef struct			s_zappy_config	t_zappy_config;

/*
** Forward declaration of t_zappy_client
*/
typedef struct			s_zappy_client	t_zappy_client;

/*
** Forward declaration of t_zappy_map
*/
typedef struct			s_zappy_map	t_zappy_map;

typedef enum			e_zappy_client_orientation
  {
    CLI_NORTH			= 0,
    CLI_EAST,
    CLI_SOUTH,
    CLI_WEST,
    NB_ORIENTATION
  }				t_zappy_client_orientation;

typedef struct			s_zappy_client_game
{
  uint64_t			food_time;
  char				*team_name;
  int32_t			inv[NB_RESOURCE];
  int32_t			team_id;
  int32_t			x;
  int32_t			y;
  int32_t			level;
  int32_t			vision;
  t_zappy_client_orientation	orientation;
  uint8_t			padding[4];
}				t_zappy_client_game;

void				zappy_client_game_init(t_zappy * const,
						       t_zappy_client *
						       const cli);
void				zappy_client_rotate_left(t_zappy_client_game *
							 const);
void				zappy_client_rotate_right(t_zappy_client_game *
							  const);
void				zappy_client_forward(t_zappy_client_game *
						     const cli,
						     int32_t const id,
						     t_zappy_map * const map);
void				zappy_has_player(t_zappy * const data);
int32_t				zappy_get_max_player_c(t_zappy_config const *
						       const data);
int32_t				zappy_get_max_player(t_zappy const *
						     const data);
void				zappy_player_level_up(t_zappy_client_game *
						      const cli,
						      t_zappy * const data);

#endif /* !ZAPPY_CLIENT_GAME_H_ */
