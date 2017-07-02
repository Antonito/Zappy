/*
** main.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 14:22:18 2017 Antoine Baché
** Last update Sun Jul  2 21:05:59 2017 Antoine Baché
*/

#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include "clogger.h"
#include "zappy_server.h"
#include "zappy_cleanup.h"
#include "zappy_alloc.h"
#include "zappy.h"

t_logger	g_log;

static t_zappy	zap;

static void	zappy_exit_cleanup(void)
{
  LOG(LOG_INFO, "Cleaning up resources...");
  zappy_reset(&zap);
  zappy_alloc_deinit();
  LOG(LOG_INFO, "Leaving Zappy server");
}

ZAPPY_NORETURN
static void	zappy_signal_handler(int sig)
{
  (void)sig;
  exit(0);
}

static int32_t	zappy(t_zappy * const data)
{
  int32_t	rc;

  srand((unsigned int)time(NULL));
  if (zappy_create_map(&data->map, &data->conf) ||
      zappy_start_admin(data))
    return (84);
  rc = zappy_create_socket(data->conf.port, &data->net);
  data->multiplex.tv_ref.tv_sec = 5;
  if (rc)
    {
      LOG(LOG_ERROR, "Cannot create socket.");
      return (84);
    }
  LOG(LOG_INFO, "Socket %d created, starting server loop.",
      data->net.sock);
  rc = zappy_server(data);
  zappy_reset(data);
  return (rc);
}

static int32_t	zappy_setup(void)
{
  clogger_init(&g_log);
#if defined DEBUG
  g_log.set_level(&g_log, LOG_DEBUG);
#else
  g_log.set_level(&g_log, LOG_INFO);
#endif
  memset(&zap, 0, sizeof(zap));
  if (zappy_alloc_init() ||
      atexit(zappy_exit_cleanup) == -1 ||
#if defined(__linux__) || defined (__APPLE__)
      signal(SIGPIPE, SIG_IGN) == SIG_ERR ||
#elif defined(_WIN32)
      !zappy_winsock_init() ||
#endif
      signal(SIGINT, &zappy_signal_handler) == SIG_ERR)
    {
      return (84);
    }
  return (0);
}

int		main(int ac, char **av)
{
  int		ret;

  ret = 0;
  if (zappy_setup())
    {
      LOG(LOG_ERROR, "Cannot start Zappy server");
      return (84);
    }
  LOG(LOG_INFO, "Starting Zappy server");
  while (!ret && zappy_parse_args(ac, (char const * const *)av, &zap.conf))
    {
      LOG(LOG_DEBUG, "Argument parsed, starting network");
      ret = zappy(&zap);
    }
#if defined(_WIN32)
  system("pause");
  zappy_winsock_deinit();
#endif
  return (ret);
}
