/*
** admin_io.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 21:50:09 2017 Antoine Baché
** Last update Sat Jul  1 23:19:56 2017 Antoine Baché
*/

#include <assert.h>
#include <string.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_network.h"
#include "zappy_admin_cmd.h"

static t_zappy_admin_cmd const	zappy_admin_commands[] =
  {
    { &zappy_admin_cmd_help,
      "help", sizeof("help") },
    { &zappy_admin_cmd_stop,
      "stop", sizeof("stop") },
    { &zappy_admin_cmd_info,
      "info", sizeof("info") },
    { &zappy_admin_cmd_inc_freq,
      "inc", sizeof("inc") },
    { &zappy_admin_cmd_dec_freq,
      "dec", sizeof("dec") },
    { &zappy_admin_cmd_reset,
      "reset", sizeof("reset") },
    { &zappy_admin_cmd_res_rand,
      "spawn rand", sizeof("spawn rand") },
    { &zappy_admin_cmd_res_food,
      "spawn food", sizeof("spawn food") },
    { &zappy_admin_cmd_res_linemate,
      "spawn linemate", sizeof("spawn linemate") },
    { &zappy_admin_cmd_res_deraumere,
      "spawn deraumere", sizeof("spawn deraumere") },
    { &zappy_admin_cmd_res_sibur,
      "spawn sibur", sizeof("spawn sibur") },
    { &zappy_admin_cmd_res_mendiane,
      "spawn mendiane", sizeof("spawn mendiane") },
    { &zappy_admin_cmd_res_phiras,
      "spawn phiras", sizeof("spawn phiras") },
    { &zappy_admin_cmd_res_thystame,
      "spawn thystame", sizeof("spawn thystame") },
    { &zappy_admin_cmd_egg,
      "spawn egg", sizeof("spawn egg") },
    { &zappy_admin_cmd_broadcast,
      "broadcast ", sizeof("broadcast ") - 1 },
    { &zappy_admin_add_tile,
      "map add ", sizeof("map add ") - 1},
    { &zappy_admin_rm_tile,
      "map rm ", sizeof("map rm ") - 1}
  };

#if (__STDC_VERSION__ >= 201112L) && defined static_assert
_Static_assert(sizeof(zappy_admin_commands) /
	       sizeof(zappy_admin_commands[0]) ==
	       NB_ADM_CMD, "Invalid number of administration commands");
#endif

void			zappy_admin_read(t_zappy * const data)
{
  char			buff[4096];
  int32_t		rc;

  assert(data && data->admin.client.sock >= 0);
  rc = zappy_network_read(&data->admin.client, buff, sizeof(buff));
  if (rc <= 0)
    {
      zappy_admin_disconnect(&data->admin);
      return ;
    }
  zappy_ring_buffer_write(&data->admin.buff, buff, rc);
  if (zappy_ring_buffer_has_cmd(&data->admin.buff))
    {
      data->admin.can_write = true;
    }
}

static void		zappy_admin_cmd(t_zappy * const data,
					char const * const cmd)
{
  int32_t		i;

  if (!data->admin.authenticated)
    {
      zappy_admin_authenticate(data, cmd);
      return ;
    }
  i = 0;
  while (i < NB_ADM_CMD)
    {
      if (!memcmp(cmd, zappy_admin_commands[i].cmd,
		  (size_t)zappy_admin_commands[i].len))
	{
	  zappy_admin_commands[i].callback(data,
					   cmd + zappy_admin_commands[i].len);
	  break;
	}
      ++i;
    }
}

void			zappy_admin_write(t_zappy * const data)
{
  int32_t		ret;
  char			buff[4096];

  assert(data && data->admin.client.sock >= 0);
  ret = zappy_ring_buffer_has_cmd(&data->admin.buff);
  if (ret > 0)
    {
      zappy_ring_buffer_read(&data->admin.buff, buff, ret);
      buff[ret - 1] = '\0';
      if (ret > 1 && buff[ret - 2] == '\r')
	buff[ret - 2] = '\0';
      LOG(LOG_DEBUG, "Administrator: \"%s\"", buff);
      zappy_admin_cmd(data, buff);
    }
  data->admin.can_write = false;
}
