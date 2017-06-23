/*
** zappy_argv.h for zappy in PSU_2016_zappy/server/include
**
** Made by Lucas Troncy
** Login   <lucas.troncy@epitech.eu>
**
** Started on  Fri Jun 23 16:10:50 2017 Lucas Troncy
** Last update Fri Jun 23 16:21:23 2017 Lucas Troncy
*/

#ifndef ZAPPY_ARGV_H_
# define ZAPPY_ARGV_H_
# define NB_ARGVS 6

# include <stdint.h>
# include <stdlib.h>

typedef struct		s_argv
{
  char			*small;
  char			*fat;
  int			(*f)(int32_t ndx, char const * const * const av);
}			t_argv;

#endif /* !ZAPPY_ARGV_H_ */
