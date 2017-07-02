/*
** admin_broadcast.c for zappy in PSU_2016_zappy/server/src/admin_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jul  1 22:33:09 2017 Antoine Baché
** Last update Sat Jul  1 22:55:25 2017 Antoine Baché
*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_admin_cmd.h"
#include "zappy_broadcast.h"
#include "zappy_client.h"
#include "zappy_message.h"

static void		zappy_adm_broadcast_msg(t_zappy_client * const cli,
						char const * const arg)
{
  t_zappy_message	*msg;
  char			buff[4096 * 2];

  msg = zappy_alloc_message();
  if (msg)
    {
      msg->len = snprintf(buff, sizeof(buff), "message %s\n", arg);
      if (msg->len != -1)
	msg->msg = strdup(buff);
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	  return ;
	}
      zappy_free_message(msg);
    }
}

static void		zappy_adm_broadcast(t_zappy_client * const cli,
					    void *_data)
{
  t_zappy_broadcast	*bd;

  bd = _data;
  if (cli->graphical || !cli->authenticated)
    return ;
  zappy_adm_broadcast_msg(cli, bd->arg);
}

void			zappy_admin_cmd_broadcast(t_zappy * const data,
						  char const * cmd)
{
  char			buff[4096 * 4];
  char			final_buff[4096];
  int32_t		from;
  t_zappy_broadcast	bd;

  assert(data && data->admin.authenticated == true);
  LOG(LOG_DEBUG, "Treating Admin command broadcast '%s'", cmd);
  if (sscanf(cmd, "%d %[^\n]", &from, buff) != -1)
    {
      LOG(LOG_INFO, "Administrator broadcasting %d %s", from, buff);
      bd = (t_zappy_broadcast){ data, NULL, final_buff };
      if (snprintf(final_buff, sizeof(final_buff) - 1,
		   "%d, %s", from, buff) != -1)
	{
	  _zappy_for_each_client(&data->clients, &bd, &zappy_adm_broadcast);
	}
    }
}
