/*
** parse.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 14:46:00 2017 Antoine Baché
** Last update Fri Jun 23 17:21:32 2017 Lucas Troncy
*/

#include "zappy.h"
#include "zappy_argv.h"
#include <string.h>

static const t_argv argvs[] = {
    {"-p", "--port", &argv_port},
    {"-x", "--width", &argv_width},
    {"-y", "--height", &argv_height},
    {"-n", "--name", &argv_name},
    {"-c", "--clientsNb", &argv_clientsNb},
    {"-f", "--freq", &argv_freq},
    {"-h", "--help", &argv_help},
};

int32_t			check_argvs(int const ac,
				   char const * const * const av,
				   t_zappy_config * const data)
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
	      if (argvs[j].f(i, av, data))
		return (1);
	    }
	  ++j;
	}
      ++i;
    }
  return (0);
}

int32_t			zappy_parse_args(int const ac,
					 char const * const * const av,
					 t_zappy_config * const data)
{
  data->port = 4242;
  data->world_height = 15;
  data->world_width = 15;
  if (check_argvs(ac, av, data))
    return (0);
  return (0);
}
