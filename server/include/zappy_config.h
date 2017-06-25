/*
** zappy_config.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 14:52:46 2017 Antoine Baché
** Last update Sun Jun 25 21:03:13 2017 Antoine Baché
*/

#ifndef ZAPPY_CONFIG_H_
#define ZAPPY_CONFIG_H_

#include <stdint.h>
#include "zappy_team_manager.h"

/*
** Basic configuration informations
*/
typedef struct		s_zappy_config
{
  t_zappy_team_manager	teams;
  int32_t		world_width;
  int32_t		world_height;
  int32_t		freq;
  uint16_t		port;
  uint8_t		padding[6];
}			t_zappy_config;

#endif /* !ZAPPY_CONFIG_H_ */
