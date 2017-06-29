/*
** sort.c for zappy in PSU_2016_zappy/libs/cqueue/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Wed Jun 28 16:22:11 2017 Antoine Baché
** Last update Wed Jun 28 17:50:24 2017 Antoine Baché
*/

#include <assert.h>
#include "cqueue.h"

bool			cqueue_is_sorted(t_cqueue const *self,
					 t_cqueue_cmp cmp)
{
  assert(self && cmp);
  while (self)
    {
      if (self->next && !cmp(self, self->next))
	{
	  return (false);
	}
      self = self->next;
    }
  return (true);
}

static void		cqueue_swap(t_cqueue *s1, t_cqueue *s2)
{
  void			*tmp;

  tmp = s1->data;
  s1->data = s2->data;
  s2->data = tmp;
}

void			cqueue_sort(t_cqueue **self, t_cqueue_cmp cmp)
{
  t_cqueue		*cur;
  t_cqueue		*tmp;

  assert(self && cmp);
  cur = *self;
  while (cur->next)
    {
      tmp = *self;
      while (tmp->next)
	{
	  if (!cmp(tmp, tmp->next))
	    {
	      cqueue_swap(tmp, tmp->next);
	    }
	  tmp = tmp->next;
	}
      cur = cur->next;
    }
}
