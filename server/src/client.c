/*
** client.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 22:05:34 2017 Antoine Baché
** Last update Fri Jun 30 21:10:06 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "cqueue.h"
#include "clogger.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_client.h"
#include "zappy_color.h"
#include "zappy_message.h"
#include "zappy_client_state.h"

static t_zappy_client_state_handle const zappy_state_hand[] =
  {
    { &zappy_cli_state_auth_r, &zappy_cli_state_auth_w },
    { &zappy_cli_state_conn_r, &zappy_cli_state_conn_w },
    { &zappy_cli_state_resp_r, &zappy_cli_state_resp_w }
  };

#if (__STDC_VERSION__ >= 201112L) && defined static_assert
_Static_assert(sizeof(zappy_state_hand) / sizeof(zappy_state_hand[0]) ==
	       NB_CLI_STATE, "Invalid number of client state");
#endif

void		zappy_client_fill(t_zappy_client * const cli,
				  t_zappy * const data,
				  t_sockaddr_in * const addr,
				  socklen_t const len)
{
  socklen_t	min_len;

  assert(cli);
  min_len = (socklen_t)sizeof(cli->net.addr);
  if (min_len > len)
    min_len = len;
  memcpy(&cli->net.addr, addr, min_len);
  cli->can_write = true;
  cli->connected = true;
  cli->state = CLI_AUTHENTICATING;
  zappy_client_game_init(data, cli);
}

void		zappy_client_read(t_zappy_client * const cli,
				  t_zappy * const data)
{
  int32_t		msg_len;
  char			buff[4096];

  assert(cli->state < NB_CLI_STATE);
  if (zappy_message_read(&cli->net, &cli->buff) == MSG_SUCCESS)
    {
      msg_len = 1;
      while (msg_len)
	{
	  msg_len = zappy_ring_buffer_has_cmd(&cli->buff);
	  if (msg_len > 0 && (size_t)msg_len < sizeof(buff))
	    {
	      memset(buff, 0, sizeof(buff));
	      zappy_ring_buffer_read(&cli->buff, (uint8_t *)buff, msg_len);
	      buff[msg_len - 1] = '\0';
	      if (msg_len - 2 > 0 && buff[msg_len - 2] == '\r')
		buff[msg_len - 2] = '\0';
	      zappy_state_hand[cli->state].read(cli, data, buff);
	    }
	}
      return ;
    }
  cli->connected = false;
}

void		zappy_client_write(t_zappy_client * const cli,
				   t_zappy * const data)
{
  t_cqueue	*to_send;

  assert(cli->state < NB_CLI_STATE);
  assert(cli->can_write);
  zappy_state_hand[cli->state].write(cli, data);
  while (!cqueue_is_empty(cli->output_queue))
    {
      to_send = cqueue_get_front(cli->output_queue);
      LOG(LOG_DEBUG, "Got message %p from output_queue", to_send);
      zappy_message_write(&cli->net, to_send->data);
      cqueue_pop(&cli->output_queue);
      zappy_free_message(to_send->data);
      zappy_free_cqueue(to_send);
    }
}

void		zappy_client_except(t_zappy_client * const cli,
				    t_zappy * const data)
{
  (void)data;
  cli->connected = false;
  LOG(LOG_WARNING, RED_BOLD_INTENS"Client #%d got exception."CLEAR, cli->id);
}
