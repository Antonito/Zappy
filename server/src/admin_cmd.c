/*
** admin_cmd.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 22:35:04 2017 Antoine Baché
** Last update Mon Jun 26 23:19:41 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_color.h"
#include "zappy_admin_cmd.h"
#include "zappy_network.h"

static char const	*zappy_admin_help_str =
  "Available commands:\n"
  "-> help: display this help\n"
  "-> info: display server's informations\n"
  "-> stop: shutdown the server\n";
static size_t const	zappy_admin_help_len =
  sizeof("Available commands:\n"
	 "-> help: display this help\n"
	 "-> info: display server's informations\n"
	 "-> stop: shutdown the server\n") - 1;

void	zappy_admin_cmd_help(t_zappy * const data)
{
  assert(data);
  LOG(LOG_DEBUG, "Treating Admin command help");
  zappy_network_write(&data->admin.client, zappy_admin_help_str,
		      zappy_admin_help_len);
}

ZAPPY_NORETURN
void	zappy_admin_cmd_stop(t_zappy * const data)
{
  assert(data);
  (void)data;
  LOG(LOG_DEBUG, "Treating Admin command stop");
  LOG(LOG_INFO, RED_BOLD_INTENS"Administrator requested system shutdown"CLEAR);
  exit(0);
}

void	zappy_admin_cmd_info(t_zappy * const data)
{
  assert(data);
  LOG(LOG_DEBUG, "Treating Admin command info");
  dprintf(data->admin.client.sock,
	  "Port:      %d\n"
	  "Freq:      %d\n"
	  "Dimension: %dx%d\n"
	  "%d clients.\n",
	  data->conf.port, data->conf.freq,
	  data->conf.world_width, data->conf.world_height,
	  data->clients.nb_clients);
}
