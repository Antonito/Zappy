/*
** zappy_broadcast.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Wed Jun 28 02:09:39 2017 Antoine Baché
** Last update Thu Jun 29 11:55:50 2017 Antoine Baché
*/

#ifndef ZAPPY_BROADCAST_H_
#define ZAPPY_BROADCAST_H_

#include <stdint.h>
#include "zappy_math.h"

/*
** Forward declaration of t_zappy
*/
typedef struct		s_zappy			t_zappy;

/*
** Forward declaration of t_zappy_client
*/
typedef struct		s_zappy_client		t_zappy_client;

typedef struct		s_zappy_broadcast
{
  t_zappy		*data;
  t_zappy_client	*cli;
  char const		*arg;
}			t_zappy_broadcast;

int32_t		zappy_broadcast_calc(t_zappy_client const * const from,
				     t_zappy_client const * const to,
				     int32_t const width,
				     int32_t const height);

#endif /* !ZAPPY_BROADCAST_H_ */
