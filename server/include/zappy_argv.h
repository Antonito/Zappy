/*
** zappy_argv.h for zappy in PSU_2016_zappy/server/include
**
** Made by Lucas Troncy
** Login   <lucas.troncy@epitech.eu>
**
** Started on  Fri Jun 23 16:10:50 2017 Lucas Troncy
** Last update Sun Jul  2 17:57:47 2017 Antoine Baché
*/

#ifndef ZAPPY_ARGV_H_
# define ZAPPY_ARGV_H_

# include <stdint.h>
# include <stdlib.h>
# include "zappy.h"

# define NB_ARGVS 7

typedef struct		s_zappy_argv
{
  char			*arg_s;
  char			*arg_l;
  int			(*f)(int32_t ndx,
			     char const * const * const av,
			     t_zappy_config * const data);
}			t_zappy_argv;

int32_t		argv_port(int32_t i, char const * const * const av,
			  t_zappy_config * const data);
int32_t		argv_width(int32_t i, char const * const * const av,
			   t_zappy_config * const data);
int32_t		argv_height(int32_t i, char const * const * const av,
			    t_zappy_config * const data);
int32_t		argv_name(int32_t i, char const * const * const av,
			  t_zappy_config * const data);
int32_t		argv_clientsNb(int32_t i, char const * const * const av,
			       t_zappy_config * const data);
int32_t		argv_freq(int32_t i, char const * const * const av,
			  t_zappy_config * const data);
int32_t		argv_help(int32_t i, char const * const * const av,
			  t_zappy_config * const data);

#endif /* !ZAPPY_ARGV_H_ */
