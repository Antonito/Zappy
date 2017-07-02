/*
** cleanup_eggs.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 30 16:32:46 2017 Antoine Baché
** Last update Sat Jul  1 02:56:31 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "clogger.h"
#include "cqueue.h"
#include "zappy_alloc.h"
#include "zappy_cleanup.h"

void			zappy_cleanup_eggs(t_zappy_egg_manager * const man)
{
  t_cqueue		*cur;

  assert(man);
  LOG(LOG_DEBUG, "Cleaning eggs");
  while (!cqueue_is_empty(man->eggs))
    {
      cur = cqueue_get_front(man->eggs);
      cqueue_pop(&man->eggs);
      free(cur->data);
      zappy_free_cqueue(cur);
    }
  while (!cqueue_is_empty(man->hatched))
    {
      cur = cqueue_get_front(man->hatched);
      cqueue_pop(&man->hatched);
      free(cur->data);
      zappy_free_cqueue(cur);
    }
}
