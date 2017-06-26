/*
** modifier.c for zappy in PSU_2016_zappy/libs/cqueue/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 00:47:23 2017 Antoine Baché
** Last update Sat Jun 24 18:19:28 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "cqueue.h"

static void	*(*alloc)(size_t count, size_t size) = &calloc;

void		cqueue_set_allocator(void *(*calloc_func)(size_t count,
							  size_t size))
{
  assert(calloc_func);
  alloc = calloc_func;
}

t_cqueue		*cqueue_push(t_cqueue **self, void * const data)
{
  t_cqueue		*elem;

  assert(self);
  elem = alloc(1, sizeof(*elem));
  if (elem)
    {
      elem->data = data;
      if (!*self)
	{
	  *self = elem;
	}
      else
	{
	  elem->prev = cqueue_get_back(*self);
	  elem->prev->next = elem;
	}
    }
  return (elem);
}

t_cqueue		*cqueue_pop(t_cqueue **self)
{
  assert(self);
  if (*self)
    {
      *self = (*self)->next;
      if (*self)
	(*self)->prev = NULL;
    }
  return (*self);
}
