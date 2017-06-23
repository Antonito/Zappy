/*
** main.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 14:22:18 2017 Antoine Baché
** Last update Fri Jun 23 17:26:02 2017 Lucas Troncy
** Last update Fri Jun 23 17:26:02 2017 Lucas Troncy
*/

#include "zappy.h"

static int32_t	zappy(t_zappy * const data)
{
  (void)data;
  // Setup client
  // Create socket
  // Start server
  return (0);
}

int		main(int ac, char **av)
{
  int		ret;
  t_zappy	zap = {};

  ret = 0;
  if (zappy_parse_args(ac,
		       (char const * const *)av, &zap.conf))
    {
      ret = zappy(&zap);
    }
  return (ret);
}
