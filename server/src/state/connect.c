/*
** connect.c for zappy in PSU_2016_zappy/server/src/state
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 00:46:54 2017 Antoine Baché
** Last update Sun Jun 25 18:29:50 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_client_state.h"
#include "zappy_client_serial.h"
#include "zappy_client_cmd.h"
#include "zappy_color.h"
#include "zappy_message.h"

static t_zappy_client_cmd const	zappy_client_commands[] =
  {
    { &zappy_client_cmd_inventory, "inventory", 1, sizeof("inventory") },
    { &zappy_client_cmd_forward, "forward", 7, sizeof("forward") },
    { &zappy_client_cmd_broadcast, "broadcast %[^\n]", 7,
      sizeof("broadcast ") - 1 },
    { &zappy_client_cmd_look, "look", 7, sizeof("look") },
    { &zappy_client_cmd_right, "right", 7, sizeof("right") },
    { &zappy_client_cmd_left, "left", 7, sizeof("left") },
    { &zappy_client_cmd_take, "take %s", 7, sizeof("take ") - 1 },
    { &zappy_client_cmd_set, "set %s", 7, sizeof("set ") - 1 },
    { &zappy_client_cmd_eject, "eject", 7, sizeof("eject") },
    { &zappy_client_cmd_fork, "fork", 42, sizeof("fork") },
    { &zappy_client_cmd_incantation, "incantation", 300,
      sizeof("incantation") },
    { &zappy_client_cmd_err, NULL, 0, 0 }
  };

#if (__STDC_VERSION__ >= 201112L) && defined static_assert
_Static_assert(sizeof(zappy_client_commands) / sizeof(zappy_client_commands[0])
	       == NB_CLIENT_CMD, "Invalid number of client commands");
#endif

static void		zappy_conn_treat_cmd(t_zappy_client * const cli,
					     t_zappy * const data,
					     char const * const buff,
					     t_zappy_client_serial * const res)
{
  int32_t		i;

  LOG(LOG_DEBUG, "Treating message: "CYAN_BOLD_INTENS"%s"CLEAR, buff);
  (void)data;
  i = 0;
  res->callback = zappy_client_commands[CMD_ERR].handle;
  res->remaining_time = zappy_client_commands[CMD_ERR].time_limit;
  while (i < CMD_ERR)
    {
      if (!memcmp(buff, zappy_client_commands[i].cmd,
		  zappy_client_commands[i].len) ||
	  sscanf(buff, zappy_client_commands[i].cmd, res->buff))
	{
	  res->callback = zappy_client_commands[i].handle;
	  res->remaining_time = zappy_client_commands[i].time_limit;
	  break;
	}
      ++i;
    }
  cqueue_push(&cli->input_queue, res);
  assert(cqueue_get_size(cli->input_queue) <= 10);
}

void			zappy_cli_state_conn_r(t_zappy_client * const cli,
					       t_zappy * const data,
					       char const * const buff)
{
  t_zappy_client_serial	*resp;
  size_t		nb_requ;

  if (!cli->graphical)
    {
      nb_requ = cqueue_get_size(cli->input_queue);
      if (nb_requ >= 10)
	{
	  LOG(LOG_WARNING, RED_BOLD_INTENS
	      "Already has 10 request from client %d"CLEAR, cli->id);
	  return ;
	}
      resp = zappy_alloc_serial();
      if (resp)
	zappy_conn_treat_cmd(cli, data, buff, resp);
    }
}

void			zappy_cli_state_conn_w(t_zappy_client * const cli,
					       t_zappy * const data)
{
  t_zappy_message	*cur;
  char			buff[1024];

  cur = zappy_alloc_message();
  if (cur)
    {
      // TODO
      cur->len = snprintf(buff, sizeof(buff) - 1, "%d\n%d %d\n", 0,
			  data->conf.world_width, data->conf.world_height);
      cur->msg = strdup(buff);
      if (cur->msg && cqueue_push(&cli->output_queue, cur))
	{
	  cli->can_write = false;
	  return ;
	}
      free(cur->msg);
      zappy_free_message(cur);
    }
  cli->connected = false;
}
