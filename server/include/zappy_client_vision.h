/*
** zappy_client_vision.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 15:43:09 2017 Antoine Baché
** Last update Mon Jun 26 17:35:37 2017 Antoine Baché
*/

#ifndef ZAPPY_CLIENT_VISION_H_
#define ZAPPY_CLIENT_VISION_H_

#include <stdint.h>
#include "zappy_resource.h"

#define ZAPPY_VISION_GET_SIZE(n)	((n + 1) * (n + 1))

/*
** Forward declaration of t_zappy_client
*/
typedef struct	s_zappy_client		t_zappy_client;

typedef struct				s_zappy_vision_content
{
  int32_t				res[NB_RESOURCE];
  int32_t				players;
}					t_zappy_vision_content;

typedef struct				s_zappy_client_vision
{
  t_zappy_vision_content		map[ZAPPY_VISION_GET_SIZE(8)];
  int32_t				nb_lines;
}					t_zappy_client_vision;

void		zappy_vision_exec(t_zappy_map const * const map,
				  t_zappy_client const * const cli,
				  t_zappy_client_vision * const vis);

#endif /* !ZAPPY_CLIENT_VISION_H_ */
