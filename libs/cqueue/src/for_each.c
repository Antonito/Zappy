/*
** for_each.c for zappy in PSU_2016_zappy/libs/cqueue/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Wed Jun 28 16:42:44 2017 Antoine Baché
** Last update Wed Jun 28 16:44:02 2017 Antoine Baché
*/

#include "cqueue.h"

void		cqueue_for_each(t_cqueue *self, t_cqueue_for callback)
{
  while (self)
    {
      callback(self);
      self = self->next;
    }
}
