/*
** cqueue.h for zappy in PSU_2016_zappy/libs/cqueue/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 00:34:37 2017 Antoine Baché
** Last update Sat Jun 24 18:18:11 2017 Antoine Baché
*/

#ifndef CQUEUE_H_
#define CQUEUE_H_

#include <stddef.h>
#include <stdbool.h>

typedef struct	s_cqueue	t_cqueue;

/*
** Generic queue in C
*/
struct		s_cqueue
{
  void		*data;
  t_cqueue	*next;
  t_cqueue	*prev;
};

/*
** Getters
*/
t_cqueue	*cqueue_get_front(t_cqueue * const self);
t_cqueue	*cqueue_get_back(t_cqueue * const self);

/*
** Capacity
*/
size_t		cqueue_get_size(t_cqueue const * const self);
bool		cqueue_is_empty(t_cqueue const * const self);

/*
** Modifier
*/
t_cqueue	*cqueue_push(t_cqueue **self, void * const data);
t_cqueue	*cqueue_pop(t_cqueue **self);

void		cqueue_set_allocator(void *(*calloc)(size_t count,
						     size_t size));

#endif /* !CQUEUE_H_ */
