/*
** capacity.c for zappy in PSU_2016_zappy/libs/cqueue/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 00:44:47 2017 Antoine Baché
** Last update Sat Jun 24 00:47:05 2017 Antoine Baché
*/

#include "cqueue.h"

size_t			cqueue_get_size(t_cqueue const * const self)
{
  t_cqueue const	*tmp;
  size_t		nb;

  tmp = self;
  nb = 0;
  while (tmp)
    {
      tmp = tmp->next;
      ++nb;
    }
  return (nb);
}

bool			cqueue_is_empty(t_cqueue const * const self)
{
  return (!self);
}
