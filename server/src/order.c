/*
** order.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Thu Jun 29 00:46:05 2017 Antoine Baché
** Last update Fri Jun 30 19:33:27 2017 Antoine Baché
*/

#include <assert.h>
#include <stdbool.h>
#include "cqueue.h"
#include "zappy_client_serial.h"

static bool	zappy_client_sort_cmp(t_cqueue const *s1, t_cqueue const *s2)
{
  uint64_t	t1;
  uint64_t	t2;

  t1 = ((t_zappy_client_serial const *)s1->data)->exec_time;
  t2 = ((t_zappy_client_serial const *)s2->data)->exec_time;
  return (t1 <= t2);
}

void		zappy_client_serial_sort(t_cqueue **queue)
{
  assert(queue);
  if (*queue)
    {
      if (!cqueue_is_sorted(*queue, &zappy_client_sort_cmp))
	{
	  cqueue_sort(queue, &zappy_client_sort_cmp);
	}
      assert(cqueue_is_sorted(*queue, &zappy_client_sort_cmp));
    }
}
