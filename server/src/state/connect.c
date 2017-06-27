/*
** connect.c for zappy in PSU_2016_zappy/server/src/state
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 00:46:54 2017 Antoine Baché
** Last update Tue Jun 27 22:23:06 2017 Antoine Baché
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

#if defined __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-nonliteral"
#endif

static t_zappy_client_cmd const	zappy_client_commands[] =
  {
    { &zappy_client_cmd_connect_nbr, "Connect_nbr", 0,
      sizeof("Connect_nbr") - 1},
    { &zappy_client_cmd_inventory, "Inventory", 1, sizeof("Inventory") },
    { &zappy_client_cmd_forward, "Forward", 7, sizeof("Forward") },
    { &zappy_client_cmd_broadcast, "Broadcast %[^\n]", 7,
      sizeof("Broadcast ") - 1 },
    { &zappy_client_cmd_look, "Look", 7, sizeof("Look") },
    { &zappy_client_cmd_right, "Right", 7, sizeof("Right") },
    { &zappy_client_cmd_left, "Left", 7, sizeof("Left") },
    { &zappy_client_cmd_take, "Take %s", 7, sizeof("Take ") - 1 },
    { &zappy_client_cmd_set, "Set %s", 7, sizeof("Set ") - 1 },
    { &zappy_client_cmd_eject, "Eject", 7, sizeof("Eject") },
    { &zappy_client_cmd_fork, "Fork", 42, sizeof("Fork") },
    { &zappy_client_cmd_incantation, "Incantation", 300,
      sizeof("Incantation") },
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
		  (size_t)zappy_client_commands[i].len) ||
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

static void		zappy_cli_state_conn_w_fail(t_zappy_client * const cli,
						    t_zappy_message * const
						    data,
						    t_zappy_config * const
						    conf)
{
  char			buff[512];

  assert(cli && data && conf);
  if (cli->graphical)
    {
      // TODO: send graphical protocol
      data->len = snprintf(buff, sizeof(buff), "msz %d %d\n",
			   conf->world_width, conf->world_height);
      if (data->len != -1)
	data->msg = strdup(buff);
      if (data->msg)
	return ;
    }
  data->len = sizeof("ko\n") - 1;
  data->msg = strdup("ko\n");
  cli->connected = false;
}

static void		zappy_cli_state_conn_w_(t_zappy_client * const cli,
						t_zappy * const data,
						t_zappy_message *cur,
						char const *buff)
{
  cur->msg = strdup(buff);
}

void			zappy_cli_state_conn_w(t_zappy_client * const cli,
					       t_zappy * const data)
{
  t_zappy_message	*cur;
  char			buff[512];
  int32_t		ret;

  if ((cur = zappy_alloc_message()))
    {
      ret = zappy_team_manager_add_client(cli->game.team_name, cli,
					  &data->conf.teams);
      if (!cli->graphical && ret != -1)
	{
	  cur->len = snprintf(buff, sizeof(buff) - 1, "%d\n%d %d\n", ret,
			      data->conf.world_width, data->conf.world_height);
	  zappy_cli_state_conn_w_(cli, data, cur, buff);
	}
      else
	zappy_cli_state_conn_w_fail(cli, cur, &data->conf);
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

#if defined __clang__
#pragma clang diagnostic pop
#endif
