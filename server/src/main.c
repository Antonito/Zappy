/*
** main.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 14:22:18 2017 Antoine Baché
** Last update Fri Jun 23 14:58:06 2017 Antoine Baché
*/

#include "zappy.h"

static int32_t	zappy()
{
  return (0);
}

int		main(int ac, char **av)
{
  int		ret;
  t_zappy	zap = {};

  ret = 0;
  if (zappy_parse_args(ac - 1,
		       (char const * const *)av + 1, &zap.conf))
    {
      ret = zappy();
    }
  return (ret);
}