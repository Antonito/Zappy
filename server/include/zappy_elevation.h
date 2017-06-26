/*
** zappy_elevation.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 17:21:14 2017 Antoine Baché
** Last update Sun Jun 25 17:24:58 2017 Antoine Baché
*/

#ifndef ZAPPY_ELEVATION_H_
#define ZAPPY_ELEVATION_H_

#include <stdint.h>
#include <stdbool.h>

/*
** Forward declaration of t_zappy
*/
typedef struct		s_zappy		t_zappy;

/*
** Forward declaration of t_zappy
*/
typedef struct		s_zappy_client	t_zappy_client;

typedef struct		s_zappy_elevation
{
  int32_t		nb_player;
  int32_t		linemate;
  int32_t		deraumere;
  int32_t		sibur;
  int32_t		mendiane;
  int32_t		phiras;
  int32_t		thystame;
}			t_zappy_elevation;

bool			zappy_elevation_check(t_zappy_client *cli,
					      t_zappy *data);

#endif /* !ZAPPY_ELEVATION_H_ */
