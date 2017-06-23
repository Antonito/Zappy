/*
** client.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 22:05:34 2017 Antoine Baché
** Last update Sat Jun 24 00:19:10 2017 Antoine Baché
*/

#include <assert.h>
#include <string.h>
#include "zappy_client.h"
#include "zappy_client_state.h"

static t_zappy_client_state_handle const zappy_state_hand[] =
  {
    { &zappy_cli_state_auth_r, &zappy_cli_state_auth_w }
  };

#if (__STDC_VERSION >= 201112L) && defined static_assert
_Static_assert(sizeof(zappy_state_hand) / sizeof(zappy_state_hand[0]) ==
	       NB_CLI_STATE, "Invalid number of client state");
#endif

void		zappy_client_fill(t_zappy_client * const cli,
				  t_sock const sock,
				  t_sockaddr_in * const addr,
				  socklen_t const len)
{
  socklen_t	min_len;

  assert(cli);
  memset(cli, 0, sizeof(*cli));
  cli->net.sock = sock;
  min_len = (socklen_t)sizeof(cli->net.addr);
  if (min_len > len)
    min_len = len;
  memcpy(&cli->net.addr, addr, min_len);
  cli->can_write = true;
  cli->connected = true;
  cli->state = CLI_AUTHENTICATING;
}

void		zappy_client_read(t_zappy_client * const cli,
				  t_zappy * const data)
{
  assert(cli->state < NB_CLI_STATE);
  zappy_state_hand[cli->state].read(cli, data);
}

void		zappy_client_write(t_zappy_client * const cli,
				   t_zappy * const data)
{
  assert(cli->state < NB_CLI_STATE);
  zappy_state_hand[cli->state].write(cli, data);
}

void		zappy_client_except(t_zappy_client * const cli,
				    t_zappy * const data)
{
  (void)cli, (void)data;
}
