/*
** zappy_config.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 14:52:46 2017 Antoine Baché
** Last update Sat Jun 24 00:29:57 2017 Antoine Baché
*/

#ifndef ZAPPY_CONFIG_H_
#define ZAPPY_CONFIG_H_

#include <stdint.h>

/*
** Basic configuration informations
*/
typedef struct		s_zappy_config
{
  uint16_t		port;
  int32_t		world_width;
  int32_t		world_height;
  int32_t		nb_client_per_team;
  int32_t		freq;
}			t_zappy_config;

#endif /* !ZAPPY_CONFIG_H_ */
