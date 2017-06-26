/*
** client_rotate.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 13:47:53 2017 Antoine Baché
** Last update Mon Jun 26 13:56:16 2017 Antoine Baché
*/

#include <assert.h>
#include "zappy_client_game.h"

#if (__STDC_VERSION__ >= 201112L) && defined static_assert
_Static_assert(CLI_NORTH + 1 == CLI_EAST &&
	       CLI_EAST + 1 == CLI_SOUTH &&
	       CLI_SOUTH + 1 == CLI_WEST,
	       "Invalid client orientation");
#endif

void		zappy_client_rotate_right(t_zappy_client_game * const cli)
{
  assert(cli);
  if (cli->orientation == CLI_WEST)
    cli->orientation = CLI_NORTH;
  else
    ++cli->orientation;
}

void		zappy_client_rotate_left(t_zappy_client_game * const cli)
{
  assert(cli);
  if (cli->orientation == CLI_NORTH)
    cli->orientation = CLI_WEST;
  else
    --cli->orientation;
}
