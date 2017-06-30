/*
** egg_manager.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 30 16:03:29 2017 Antoine Baché
** Last update Fri Jun 30 16:28:05 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_egg_manager.h"

t_zappy_egg	*zappy_egg_add(t_zappy * const data,
			       int32_t const team_id,
			       uint64_t const now)
{
  t_zappy_egg	*egg;
  t_zappy_egg	*cur;

  assert(data);
  egg = calloc(1, sizeof(*egg));
  if (egg)
    {
      LOG(LOG_DEBUG, "Adding an egg to the list [%d]", team_id);
      egg->hatch_date = (uint64_t)((600 * 1000) / data->conf.freq) + now;
      egg->team_id = team_id;
      cur = data->egg_manager.eggs;
      while (cur && cur->next)
	cur = cur->next;
      if (!cur)
	data->egg_manager.eggs = egg;
      else
	{
	  cur->next = egg;
	  egg->prev = cur;
	}
      ++data->egg_manager.nb_eggs;
    }
  return (egg);
}

void		zappy_egg_remove(t_zappy_egg_manager * const man,
				 t_zappy_egg * const egg)
{
  assert(man && egg);
  LOG(LOG_DEBUG, "Removing an egg from the list");
  if (egg->prev)
    {
      assert(egg->prev->next == egg);
      egg->prev->next = egg->next;
    }
  else
    man->eggs = egg->next;
  if (egg->next)
    {
      assert(egg->next->prev == egg);
      egg->next->prev = egg->prev;
    }
  free(egg);
  --man->nb_eggs;
  assert(man->nb_eggs >= 0);
}

void		zappy_egg_foreach(t_zappy * const data,
				  void * const user_data,
				  t_zappy_egg_callback call)
{
  int32_t	i;
  t_zappy_egg	*cur;

  assert(data && user_data && call);
  i = 0;
  cur = data->egg_manager.eggs;
  while (i < data->egg_manager.nb_eggs)
    {
      call(cur, user_data);
      cur = cur->next;
      ++i;
    }
}
