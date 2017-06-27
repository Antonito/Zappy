/*
** look.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:29:34 2017 Antoine Baché
** Last update Tue Jun 27 15:19:47 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_client_cmd.h"
#include "zappy_client_vision.h"
#include "zappy_message.h"

static void		zappy_client_look_add_res(t_zappy_client_vision
						  const * const vision,
						  int32_t const i,
						  char buff[4096])
{
  char const		*res;
  int32_t		j;
  int32_t		l;

  j = 0;
  while (j < NB_RESOURCE)
    {
      res = zappy_get_resource_by_id(j);
      l = 0;
      while (l < vision->map[i].res[j])
	{
	  strncat(buff, " ", (4096 * 3) - 1);
	  strncat(buff, res, (4096 * 3) - 1);
	  ++l;
	}
      ++j;
    }
}

static void		zappy_client_look_build(t_zappy_message * const msg,
						t_zappy_client_vision
						const * const vision)
{
  int32_t		i;
  int32_t		max;
  char			buff[4096 * 3];
  int32_t		j;

  assert(msg && vision && vision->nb_lines > 0);
  memset(buff, 0, sizeof(buff));
  max = ZAPPY_VISION_GET_SIZE(vision->nb_lines - 1);
  i = 0;
  strncat(buff, "[", sizeof(buff) - 1);
  while (i < max)
    {
      j = 0;
      if (i != 0)
	strncat(buff, ",", sizeof(buff) - 1);
      while (j < vision->map[i].players)
	{
	  strncat(buff, " player", sizeof(buff) - 1);
	  ++j;
	}
      zappy_client_look_add_res(vision, i, buff);
      ++i;
    }
  strncat(buff, "]\n", sizeof(buff) - 1);
  msg->len = (int32_t)strlen(buff);
  msg->msg = strdup(buff);
}

void			zappy_client_cmd_look(t_zappy_client * const cli,
					      t_zappy * const data,
					      char const * const arg)
{
  t_zappy_client_vision	vision;
  t_zappy_message	*msg;

  (void)arg;
  (void)data;
  LOG(LOG_DEBUG, "Treating look command");
  msg = zappy_alloc_message();
  if (msg)
    {
      zappy_vision_exec(&data->map, cli, &vision);
      zappy_client_look_build(msg, &vision);
      if (msg->msg && cqueue_push(&cli->output_queue, msg))
	{
	  cli->state = CLI_RESPONSE;
	  cli->can_write = true;
	  return ;
	}
      free(msg->msg);
      zappy_free_message(msg);
    }
}
