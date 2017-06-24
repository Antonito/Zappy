/*
** getters.c for zappy in PSU_2016_zappy/libs/cqueue/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 00:41:00 2017 Antoine Baché
** Last update Sat Jun 24 00:44:16 2017 Antoine Baché
*/

#include <assert.h>
#include "cqueue.h"

t_cqueue	*cqueue_get_front(t_cqueue * const self)
{
  t_cqueue	*cur;

  assert(self);
  cur = self;
  while (cur->prev)
    {
      cur = cur->prev;
    }
  return (cur);
}

t_cqueue	*cqueue_get_back(t_cqueue * const self)
{
  t_cqueue	*cur;

  assert(self);
  cur = self;
  while (cur->next)
    {
      cur = cur->next;
    }
  return (cur);
}
