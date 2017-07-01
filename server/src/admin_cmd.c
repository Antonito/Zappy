/*
** admin_cmd.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 22:35:04 2017 Antoine Baché
** Last update Sat Jul  1 23:39:17 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_color.h"
#include "zappy_admin_cmd.h"
#include "zappy_network.h"
#include "zappy_graphic.h"

static char const	*zappy_admin_help_str =
  "Available commands:\n"
  "-> help:              display this help\n"
  "-> info:              display server's informations\n"
  "-> stop:              shutdown the server\n"
  "-> inc:               increase server frequency\n"
  "-> dec:               decrease server frequency\n"
  "-> reset:             restarts the server, starting a new game\n"
  "-> spawn rand:        spwans a random resource on a random case.\n"
  "                      The following spawns are available: rand, food\n"
  "                      , linemate, deraumere, sibur, mendiane, phiras\n"
  "                      , thystame, egg\n"
  "-> broadcast nb msg:  broadcast a message to all players, \n"
  "                      coming from nb case\n"
  "-> map add X Y res:   add an element of res type to map case X Y\n"
  "-> map rm X Y res:    remove an element of res type from map case X Y\n";

static size_t const	zappy_admin_help_len =
  sizeof("Available commands:\n"
	 "-> help:              display this help\n"
	 "-> info:              display server's informations\n"
	 "-> stop:              shutdown the server\n"
	 "-> inc:               increase server frequency\n"
	 "-> dec:               decrease server frequency\n"
	 "-> reset:             restarts the server, starting a new game\n"
	 "-> spawn rand:        spwans a random resource on a random case.\n"
	 "                      The following spawns are available: rand, "
	 "food\n"
	 "                      , linemate, deraumere, sibur, mendiane, "
	 "phiras\n"
	 "                      , thystame, egg\n"
	 "-> broadcast nb msg:  broadcast a message to all players, \n"
	 "                      coming from nb case\n"
	 "-> map add X Y res:   add an element of res type to map case X Y\n"
	 "-> map rm X Y res:    remove an element of res type from map "
	 "case X Y\n") - 1;

void	zappy_admin_cmd_help(t_zappy * const data,
			     char const * cmd)
{
  assert(data && data->admin.authenticated == true);
  (void)cmd;
  LOG(LOG_DEBUG, "Treating Admin command help");
  zappy_network_write(&data->admin.client, zappy_admin_help_str,
		      zappy_admin_help_len);
}

ZAPPY_NORETURN
void	zappy_admin_cmd_stop(t_zappy * const data,
			     char const * cmd)
{
  assert(data && data->admin.authenticated == true);
  (void)cmd;
  (void)data;
  LOG(LOG_DEBUG, "Treating Admin command stop");
  LOG(LOG_INFO, RED_BOLD_INTENS"Administrator requested system shutdown"CLEAR);
  exit(0);
}

void	zappy_admin_cmd_reset(t_zappy * const data,
			      char const * cmd)
{
  (void)cmd;
  assert(data && data->admin.authenticated == true);
  LOG(LOG_DEBUG, "Treating Admin command reset");
  data->should_reset = true;
}

void	zappy_admin_cmd_inc_freq(t_zappy * const data,
				 char const * cmd)
{
  (void)cmd;
  assert(data && data->admin.authenticated == true);
  LOG(LOG_DEBUG, "Treating Admin command inc");
  data->conf.freq += 10;
  if (data->conf.freq > 10000)
    data->conf.freq = 10000;
  zappy_network_write(&data->admin.client, "OK\n", sizeof("OK\n") - 1);
}

void	zappy_admin_cmd_dec_freq(t_zappy * const data,
				 char const * cmd)
{
  (void)cmd;
  assert(data && data->admin.authenticated == true);
  LOG(LOG_DEBUG, "Treating Admin command dec");
  data->conf.freq -= 10;
  if (data->conf.freq <= 0)
    data->conf.freq = 1;
  zappy_network_write(&data->admin.client, "OK\n", sizeof("OK\n") - 1);
}
