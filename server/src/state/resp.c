/*
** resp.c for zappy in PSU_2016_zappy/server/src/state
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 13:06:19 2017 Antoine Baché
** Last update Fri Jun 30 13:24:06 2017 Antoine Baché
*/

#include <assert.h>
#include "zappy_client.h"
#include "zappy_client_state.h"
#include "zappy.h"

void		zappy_cli_state_resp_r(t_zappy_client * const cli,
				       t_zappy * const data,
				       char const * const buff)
{
  (void)cli;
  (void)data;
  (void)buff;
}

void		zappy_cli_state_resp_w(t_zappy_client * const cli,
				       t_zappy * const data)
{
  assert(cli && data);
  (void)data;
  cli->can_write = false;
  cli->state = CLI_CONNECTED;
}
