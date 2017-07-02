/*
** broadcast.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoinebache@epitech.net>
**
** Started on  Wed Jun 28 02:38:56 2017 Antoine Baché
** Last update Sun Jul  2 14:57:33 2017 Antoine Baché
*/

#include <assert.h>
#include <math.h>
#include "clogger.h"
#include "zappy_client.h"
#include "zappy_broadcast.h"

static int32_t const	zappy_broadcast_map[3][3] =
  {
    {7, 0, 1},
    {6, -1, 2},
    {5, 4, 3}
  };

static int32_t	zappy_broadcast_get_shortest(int32_t const a,
					     int32_t const b, int32_t const c)
{
  int32_t	tmp;
  int32_t	min_tmp;
  int32_t	a1;
  int32_t	a2;

  tmp = a - b;
  a1 = tmp + c;
  a2 = tmp - c;
  min_tmp = tmp;
  if (ZAPPY_ABS(a1) < ZAPPY_ABS(min_tmp))
    min_tmp = a1;
  if (ZAPPY_ABS(a2) < ZAPPY_ABS(min_tmp))
    min_tmp = a2;
  return (min_tmp);
}

static int32_t	zappy_broadcast_tile(int32_t x, int32_t y,
				     t_zappy_client const * const to)
{
  int32_t	val;

  if (!x && !y)
    return (0);
  if (x > 2.99)
    x = 2;
  if (y > 2.99)
    y = 2;
  if (!x)
    val = (y > 0) ? 4 : 0;
  else if (!y)
    val = (x > 0) ? 2 : 6;
  else
    val = zappy_broadcast_map[y][x];
  val = ((uint32_t)val - (2 * to->game.orientation)) % 8 + 1;
  return (val);
}

int32_t		zappy_broadcast_calc(t_zappy_client const * const from,
				     t_zappy_client const * const to,
				     int32_t const width,
				     int32_t const height)
{
  int32_t	shortest[2];
  double	dir;
  double	u[2];
  double	r[2];
  double	v[2];

  shortest[0] = zappy_broadcast_get_shortest(from->game.x, to->game.x,
					     width);
  shortest[1] = zappy_broadcast_get_shortest(from->game.y, to->game.y,
					     height);
  LOG(LOG_DEBUG, "a: %d | b %d", shortest[0], shortest[1]);
  if (!shortest[0] || !shortest[1])
    return (zappy_broadcast_tile(shortest[0], shortest[1], to));
  dir = (double)shortest[1] / (double)shortest[0];
  u[0] = (shortest[0] > 0) ? 3.0 : 0.0;
  u[1] = (shortest[1] > 0) ? 3.0 : 0.0;
  LOG(LOG_DEBUG, "U: %f | V: %f", u[0], u[1]);
  r[0] = dir * u[0] + 1.5 * (1.0 - dir);
  r[1] = (u[1] - 1.5 * (1.0 - dir)) / dir;
  LOG(LOG_DEBUG, "R1: %f | R2: %f", r[0], r[1]);
  v[0] = sqrt(ZAPPY_LEN((u[0] - 1.5), (r[0] - 1.5)));
  v[1] = sqrt(ZAPPY_LEN((r[1] - 1.5), (u[1] - 1.5)));
  if (v[0] < v[1])
    return (zappy_broadcast_tile((int32_t)u[0], (int32_t)r[0], to));
  return (zappy_broadcast_tile((int32_t)r[1], (int32_t)u[1], to));
}
