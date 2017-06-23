/*
** parse.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 14:46:00 2017 Antoine Baché
** Last update Fri Jun 23 16:24:53 2017 Lucas Troncy
*/

#include "zappy.h"
#include "zappy_argv.h"
#include <string.h>

static const t_argv argvs[] = {
    {"-p", "--port", NULL},
    {"-w", "--width", NULL},
    {"-h", "--height", NULL},
    {"-n", "--name", NULL},
    {"-c", "--clientsNb", NULL},
    {"-f", "--freq", NULL},
};

int32_t			check_help(int const ac,
				   char const * const * const av)
{
  int32_t		i = 0;
  int32_t		j = 0;

  while (i < ac)
    {
      j = 0;
      while (j < NB_ARGVS)
	{
	  if (strcmp(av[i], argvs[j].small) == 0 ||
	      strcmp(av[i], argvs[j].fat) == 0)
	    {
	      argvs[j].f(i, av);
	    }
	}
    }
}

int32_t			zappy_parse_args(int const ac,
					 char const * const * const av,
					 t_zappy_config * const data)
{
  if (check_help(ac, av))
    return (0);
  return (0);
}
