/*
** resp.c for zappy in PSU_2016_zappy/server/src/state
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 13:06:19 2017 Antoine Baché
** Last update Sun Jun 25 16:26:32 2017 Antoine Baché
*/

#include <assert.h>
#include "zappy_client.h"
#include "zappy_client_state.h"
#include "zappy.h"

void		zappy_cli_state_resp_r(t_zappy_client * const cli,
				       t_zappy * const data,
				       char const * const buff)
{
  assert(0 && "Should never reach this");
  (void)cli, (void)data, (void)buff;
}

void		zappy_cli_state_resp_w(t_zappy_client * const cli,
				       t_zappy * const data)
{
  assert(cli && data);
  //cli->resp_handle(cli, data, cli->resp_buff);
  //cli->resp_handle = NULL;
  cli->can_write = false;
  cli->state = CLI_CONNECTED;
}
