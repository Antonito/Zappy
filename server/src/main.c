/*
** main.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 14:22:18 2017 Antoine Baché
** Last update Fri Jun 23 16:44:18 2017 Antoine Baché
*/

#include "zappy_server.h"
#include "zappy.h"

static int32_t	zappy(t_zappy * const data)
{
  int32_t	rc;

  rc = zappy_create_socket(data->conf.port, &data->net);
  if (rc)
    {
      return (84);
    }
  rc = zappy_server(data);
  return (rc);
}

int		main(int ac, char **av)
{
  int		ret;
  t_zappy	zap = {};

  ret = 0;
  if (zappy_parse_args(ac - 1,
		       (char const * const *)av + 1, &zap.conf))
    {
      ret = zappy(&zap);
    }
  return (ret);
}
