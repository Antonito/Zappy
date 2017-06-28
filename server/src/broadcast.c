/*
** broadcast.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoinebache@epitech.net>
**
** Started on  Wed Jun 28 02:38:56 2017 Antoine Baché
** Last update Wed Jun 28 03:12:44 2017 Antoine Baché
*/

#include <assert.h>
#include <math.h>
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

  tmp = b - a;
  min_tmp = ZAPPY_ABS(tmp);
  min_tmp = ZAPPY_MIN(min_tmp, ZAPPY_ABS(tmp + c));
  min_tmp = ZAPPY_MIN(min_tmp, ZAPPY_ABS(tmp - c));
  return (min_tmp);
}

static int32_t	zappy_broadcast_case(int32_t const x, int32_t const y,
				     t_zappy_client const * const to)
{
  int32_t	val;

  if (!x && !y)
    return (0);
  assert(y >= 0 && x >= 0);
  assert(y < 3 && x < 3);
  val = zappy_broadcast_map[y][x];
  val = ((uint32_t)val - (2 * (to->game.orientation + 1))) % 8 + 1;
  return (val);
}

int32_t		zappy_broadcast_calc(t_zappy_client const * const from,
				     t_zappy_client const * const to,
				     int32_t const width, int32_t const height)
{
  int32_t	shortest[2];
  double	dir;
  double	u[2];
  double        r[2];
  double	v[2];

  shortest[0] = zappy_broadcast_get_shortest(from->game.x, to->game.x, width);
  shortest[1] = zappy_broadcast_get_shortest(from->game.y, to->game.y, height);
  if (!shortest[0] || !shortest[1])
    return (zappy_broadcast_case(shortest[0], shortest[1], to));
  dir = shortest[1] / shortest[0];
  u[0] = (shortest[0] > 0) ? 3.0 : 0.0;
  u[1] = (shortest[1] > 0) ? 3.0 : 0.0;
  r[0] = dir * u[0] + 1.5 * (1.0 - dir);
  r[1] = (u[1] - 1.5 * (1.0 - dir)) / dir;
  v[0] = sqrt(ZAPPY_LEN((u[0] - 1.5), (r[0] - 1.5)));
  v[1] = sqrt(ZAPPY_LEN((r[1] - 1.5), (u[1] - 1.5)));
  if (v[0] < v[1])
    return (zappy_broadcast_case((int32_t)u[0], (int32_t)r[0], to));
  return (zappy_broadcast_case((int32_t)r[1], (int32_t)u[1], to));
}
