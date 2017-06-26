/*
** getters.c for zappy in PSU_2016_zappy/libs/cqueue/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 00:41:00 2017 Antoine Baché
** Last update Sun Jun 25 16:38:27 2017 Antoine Baché
*/

#include <assert.h>
#include "cqueue.h"

t_cqueue	*cqueue_get_front(t_cqueue * const self)
{
  t_cqueue	*cur;

  if (!self)
    return (self);
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

  if (!self)
    return (self);
  cur = self;
  while (cur->next)
    {
      cur = cur->next;
    }
  return (cur);
}
