/*
** main.c for zapy in PSU_2016_zappy/libs/cqueue/test
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Wed Jun 28 16:36:21 2017 Antoine Baché
** Last update Sun Jul  2 15:16:19 2017 Antoine Baché
*/

#include <stdlib.h>
#include <stdio.h>
#include "cqueue.h"

bool		cmp_min(t_cqueue const *s1, t_cqueue const *s2)
{
  int		a;
  int		b;

  a = (int)s1->data;
  b = (int)s2->data;
  return (a <= b);
}

void		print_list(t_cqueue *s)
{
  printf("-> %d\n", (int)s->data);
}

int		main()
{
  t_cqueue	*list;
  t_cqueue	*tmp;

  list = NULL;
  cqueue_push(&list , (void *)7);
  cqueue_push(&list , (void *)1);
  cqueue_push(&list , (void *)1);
  cqueue_push(&list , (void *)23);
  cqueue_push(&list , (void *)-99);
  cqueue_push(&list , (void *)-98);
  cqueue_push(&list , (void *)1238);
  cqueue_push(&list , (void *)0);
  cqueue_push(&list , (void *)-2);
  printf("Is list sorted -> %d\n", cqueue_is_sorted(list, &cmp_min));
  printf("Sorting list...");
  cqueue_sort(&list, &cmp_min);
  printf("Is list sorted -> %d\n", cqueue_is_sorted(list, &cmp_min));
  cqueue_for_each(list, print_list);
  while (!cqueue_is_empty(list))
    {
      tmp = cqueue_get_front(list);
      cqueue_pop(&list);
      free(tmp);
    }
  return (EXIT_SUCCESS);
}
