/*
** main.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 14:22:18 2017 Antoine Baché
** Last update Fri Jun 23 22:23:07 2017 Antoine Baché
*/

#include <stdlib.h>
#include <signal.h>
#include "clogger.h"
#include "zappy_server.h"
#include "zappy_cleanup.h"
#include "zappy.h"

t_logger	g_log;

static t_zappy	zap = {};

static void	zappy_exit_cleanup(void)
{
  LOG(LOG_INFO, "Cleaning up resources...");
  zappy_cleanup_config(&zap.conf);
  zappy_cleanup_socket(&zap.net);
  zappy_cleanup_multiplexer(&zap.multiplex);
  zappy_cleanup_clients(&zap.clients);
  LOG(LOG_INFO, "Leaving Zappy server");
}

static void	zappy_signal_handler(int sig)
{
  (void)sig;
  exit(0);
}

static int32_t	zappy(t_zappy * const data)
{
  int32_t	rc;

  rc = zappy_create_socket(data->conf.port, &data->net);
  data->multiplex.tv_ref.tv_sec = 5;
  if (rc)
    {
      LOG(LOG_ERROR, "Cannot create socket.");
      return (84);
    }
  LOG(LOG_INFO, "Socket %d created, starting server loop.", data->net.sock);
  rc = zappy_server(data);
  return (rc);
}

int		main(int ac, char **av)
{
  int		ret;

  ret = 0;
  clogger_init(&g_log);
#if defined DEBUG
  g_log.set_level(&g_log, LOG_DEBUG);
#else
  g_log.set_level(&g_log, LOG_INFO);
#endif
  LOG(LOG_INFO, "Starting Zappy server");
  if (atexit(zappy_exit_cleanup) == -1 ||
      signal(SIGINT, &zappy_signal_handler) == SIG_ERR)
    {
      return (84);
    }
  if (zappy_parse_args(ac,
		       (char const * const *)av, &zap.conf))
    {
      LOG(LOG_DEBUG, "Argument parsed, starting network");
      ret = zappy(&zap);
    }
  return (ret);
}
