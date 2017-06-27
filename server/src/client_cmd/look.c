/*
** look.c for zappy in PSU_2016_zappy/server/src/client_cmd
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:29:34 2017 Antoine Baché
** Last update Mon Jun 26 19:12:21 2017 Antoine Baché
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

static void		zappy_client_look_build(t_zappy_message * const msg,
						t_zappy_client_vision
						const * const vision)
{
  int32_t		i;
  int32_t		max;
  char			buff[4096];
  char const		*res;
  size_t		len;
  int			j;

  assert(msg && vision);
  memset(buff, 0, sizeof(buff));
  max = ZAPPY_VISION_GET_SIZE(vision->nb_lines);
  i = 0;
  // TODO: Code, strcat
  while (i < max)
    {
      j = 0;
      while (j < NB_RESOURCE)
	{
	  res = zappy_get_resource_by_id(vision->map[i].res[j]);
	  len = strlen(res);
	  strncat(buff, res, len);
	  ++j;
	}
      ++i;
    }
  (void)msg;
  // TODO: Analyze vision's data
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
