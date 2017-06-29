/*
** zappy_logic.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 22:36:03 2017 Antoine Baché
** Last update Thu Jun 29 16:49:57 2017 Antoine Baché
*/

#ifndef ZAPPY_LOGIC_H_
#define ZAPPY_LOGIC_H_

#include <stdbool.h>
#include <stdint.h>

/*
** Forward declaration of t_zappy
*/
typedef struct s_zappy		t_zappy;

bool		zappy_logic(t_zappy * const data);
bool		zappy_has_winner(t_zappy * const data);

#endif /* !ZAPPY_LOGIC_H_ */
