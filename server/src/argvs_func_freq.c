/*
** argvs_func_freq.c for zappy in /Users/lokoum/prog/PSU_2016_zappy/server/src
** 
** Made by Lucas Troncy
** Login   <lucas.troncy@epitech.eu>
** 
** Started on  Fri Jun 23 16:49:08 2017 Lucas Troncy
** Last update Fri Jun 23 17:24:32 2017 Lucas Troncy
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "zappy.h"
#include "zappy_argv.h"


int32_t		argv_freq(int32_t i, char const * const * const av,
			  t_zappy_config * const data)
{
  printf("[log] freq\n");
  if (!av[i + 1] || av[i + 1][0] == '-')
    {
      printf("Freq option : please enter valid freq\n\n");
      argv_help(i, av, data);
      return (1);
    }
  data->freq = (uint16_t)atoi(av[i + 1]);
  return (0);
}

int32_t		argv_help(int32_t i, char const * const * const av,
			  t_zappy_config * const data)
{
  (void)i;
  (void)av;
  (void)data;
  printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ..."
	 " -c clientsNb -f freq\n"
	 "port        is the port number\n"
	 "width       is the width of the world\n"
	 "height      is the height of the world\n"
	 "nameX       is the name of the team X\n"
	 "clientsNb   is the number of authorized clients per team\n"
	 "freq        is the reciprocal of time unit for execution of actions\n"
	);
  return (0);
}
