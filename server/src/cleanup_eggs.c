/*
** cleanup_eggs.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 30 16:32:46 2017 Antoine Baché
** Last update Fri Jun 30 16:45:36 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "zappy_cleanup.h"

void			zappy_cleanup_eggs(t_zappy_egg_manager * const man)
{
  int32_t		i;
  t_zappy_egg		*cur;
  t_zappy_egg		*tmp;

  assert(man);
  i = 0;
  cur = man->eggs;
  while (i < man->nb_eggs)
    {
      tmp = cur;
      cur = cur->next;
      free(tmp);
      ++i;
    }
}
