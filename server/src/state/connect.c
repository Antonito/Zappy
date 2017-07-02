/*
** connect.c for zappy in PSU_2016_zappy/server/src/state
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 00:46:54 2017 Antoine Baché
** Last update Sun Jul  2 14:40:33 2017 Antoine Baché
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
#include "zappy_graphic.h"
#include "zappy_time.h"

#if defined __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-nonliteral"
#endif

static t_zappy_client_cmd const	zappy_client_commands[] =
  {
    { &zappy_client_cmd_connect_nbr, NULL, "Connect_nbr", 0,
      sizeof("Connect_nbr") - 1},
    { &zappy_client_cmd_inventory, NULL,
      "Inventory", 1, sizeof("Inventory") },
    { &zappy_client_cmd_forward, NULL, "Forward", 7, sizeof("Forward") },
    { &zappy_client_cmd_broadcast, NULL, "Broadcast %[^\n]", 7,
      sizeof("Broadcast ") - 1 },
    { &zappy_client_cmd_look, NULL, "Look", 7, sizeof("Look") },
    { &zappy_client_cmd_right, NULL, "Right", 7, sizeof("Right") },
    { &zappy_client_cmd_left, NULL, "Left", 7, sizeof("Left") },
    { &zappy_client_cmd_take, NULL, "Take %s", 7, sizeof("Take ") - 1 },
    { &zappy_client_cmd_set, NULL, "Set %s", 7, sizeof("Set ") - 1 },
    { &zappy_client_cmd_eject, NULL, "Eject", 7, sizeof("Eject") },
    { &zappy_client_cmd_fork, &zappy_client_pre_fork,
      "Fork", 42, sizeof("Fork") },
    { &zappy_client_cmd_incantation, &zappy_client_pre_incantation,
      "Incantation", 300,
      sizeof("Incantation") },
    { &zappy_client_cmd_err, NULL, NULL, 0, 0 }
  };

#if (__STDC_VERSION__ >= 201112L) && defined static_assert
_Static_assert(sizeof(zappy_client_commands) /
	       sizeof(zappy_client_commands[0])
	       == NB_CLIENT_CMD, "Invalid number of client commands");
#endif

static void		zappy_conn_treat_cmd(t_zappy_client * const cli,
					     t_zappy * const data,
					     char const * const buff,
					     t_zappy_client_serial *
					     const res)
{
  int32_t		i;

  LOG(LOG_DEBUG, "Treating message: "CYAN_BOLD_INTENS"%s"CLEAR, buff);
  i = -1;
  while (++i < CMD_ERR)
    {
      if (!memcmp(buff, zappy_client_commands[i].cmd,
		  (size_t)zappy_client_commands[i].len) ||
	  sscanf(buff, zappy_client_commands[i].cmd, res->buff))
	{
	  if (zappy_client_commands[i].on_rec)
	    zappy_client_commands[i].on_rec(cli, data);
	  memcpy(res->buff, buff + zappy_client_commands[i].len,
		 strlen(buff + zappy_client_commands[i].len));
	  res->callback = zappy_client_commands[i].handle;
	  res->remaining_time = zappy_client_commands[i].time_limit;
	  res->exec_time =
	    (uint64_t)(((double)res->remaining_time * 1000) /
		       data->conf.freq) + zappy_get_cur_time();
	  break;
	}
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
	{
	  resp->callback = zappy_client_commands[CMD_ERR].handle;
	  resp->remaining_time = zappy_client_commands[CMD_ERR].time_limit;
	  zappy_conn_treat_cmd(cli, data, buff, resp);
	}
    }
}

#if defined __clang__
#pragma clang diagnostic pop
#endif
