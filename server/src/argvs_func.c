/*
** args_func.c for zappy in PSU_2016_zappy/server/src
**
** Made by Lucas Troncy
** Login   <lucas.troncy@epitech.eu>
**
** Started on  Fri Jun 23 16:30:51 2017 Lucas Troncy
** Last update Tue Jun 27 15:00:21 2017 Antoine Baché
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_team_manager.h"
#include "zappy_argv.h"

int32_t		argv_port(int32_t i, char const * const * const av,
			  t_zappy_config * const data)
{
  int32_t	tmp;

  LOG(LOG_DEBUG, "Parsing port");
  if (!av[i + 1] || av[i + 1][0] == '-')
    {
      printf("Port option : please enter valid port\n\n");
      argv_help(i, av, data);
      return (1);
    }
  tmp = (int32_t)strtol(av[i + 1], NULL, 10);
  if (tmp < 0 || tmp > UINT16_MAX || (data->port == 0 && errno == EINVAL))
    {
      LOG(LOG_ERROR, "Invalid port.");
      return (1);
    }
  data->port = (uint16_t)tmp;
  LOG(LOG_DEBUG, "Found %d", data->port);
  return (0);
}

int32_t		argv_width(int32_t i, char const * const * const av,
			   t_zappy_config * const data)
{
  LOG(LOG_DEBUG, "Parsing width");
  if (!av[i + 1] || av[i + 1][0] == '-')
    {
      printf("Width option : please enter valid width\n\n");
      argv_help(i, av, data);
      return (1);
    }
  data->world_width = (int32_t)strtol(av[i + 1], NULL, 10);
  if (data->world_width <= 0)
    {
      LOG(LOG_ERROR, "Invalid width");
      return (1);
    }
  LOG(LOG_DEBUG, "Found %d", data->world_width);
  return (0);
}

int32_t		argv_height(int32_t i, char const * const * const av,
			    t_zappy_config * const data)
{
  LOG(LOG_DEBUG, "Parsing height");
  if (!av[i + 1] || av[i + 1][0] == '-')
    {
      printf("Height option : please enter valid height\n\n");
      argv_help(i, av, data);
      return (1);
    }
  data->world_height = (int32_t)strtol(av[i + 1], NULL, 10);
  if (data->world_height <= 0)
    {
      LOG(LOG_ERROR, "Invalid height");
      return (1);
    }
  LOG(LOG_DEBUG, "Found %d", data->world_height);
  return (0);
}

int32_t		argv_name(int32_t i, char const * const * const av,
			  t_zappy_config * const data)
{
  LOG(LOG_DEBUG, "Parsing team names");
  while (av[++i] && av[i][0] != '-')
    {
      LOG(LOG_DEBUG, "Found %s", av[i]);
      if (!memcmp("GRAPHIC", av[i], sizeof("GRAPHIC")))
	{
	  LOG(LOG_ERROR, "Cannot have a team named GRAPHIC");
	  return (1);
	}
      if (zappy_team_manager_add_team(av[i], &data->teams))
	return (1);
    }
  return (0);
}

int32_t		argv_clientsNb(int32_t i, char const * const * const av,
			       t_zappy_config * const data)
{
  LOG(LOG_DEBUG, "Parsing client per team");
  if (!av[i + 1] || av[i + 1][0] == '-')
    {
      printf("ClientsNb option : please enter valid number of client\n\n");
      argv_help(i, av, data);
      return (1);
    }
  data->teams.nb_client_per_team = (int32_t)strtol(av[i + 1], NULL, 10);
  if (data->teams.nb_client_per_team <= 0)
    {
      LOG(LOG_ERROR, "Invalid number of client per team.");
      return (1);
    }
  LOG(LOG_DEBUG, "Found %d", data->teams.nb_client_per_team);
  return (0);
}
