/*
** egg_manager.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 30 16:03:29 2017 Antoine Baché
** Last update Sat Jul  1 11:06:37 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "clogger.h"
#include "cqueue.h"
#include "cqueue.h"
#include "zappy.h"
#include "zappy_alloc.h"
#include "zappy_egg_manager.h"

void		zappy_remove_egg(t_zappy * const data,
				 t_zappy_egg * const egg)
{
  t_cqueue	*cur;
  int32_t	i;

  i = 0;
  cur = data->egg_manager.hatched;
  while (i < data->egg_manager.nb_hatched_eggs)
    {
      if (cur->data == egg)
	{
	  free(cur->data);
	  cur->data = NULL;
	  cqueue_remove(&data->egg_manager.hatched, cur);
	  zappy_free_cqueue(cur);
	  break ;
	}
      cur = cur->next;
      ++i;
    }
}

t_zappy_egg	*zappy_get_egg_from_team(t_zappy * const data,
					 int32_t const team_id)
{
  int32_t	i;
  t_cqueue	*cur;

  i = 0;
  cur = data->egg_manager.hatched;
  while (i < data->egg_manager.nb_hatched_eggs)
    {
      if (((t_zappy_egg *)cur->data)->team_id == team_id)
	{
	  return (cur->data);
	}
      cur = cur->next;
      ++i;
    }
  return (NULL);
}

int32_t	        zappy_get_number_hatched_eggs(t_zappy * const data,
					      int32_t const team_id)
{
  int32_t	count;
  int32_t	i;
  t_cqueue	*cur;

  count = 0;
  i = 0;
  cur = data->egg_manager.hatched;
  while (i < data->egg_manager.nb_hatched_eggs)
    {
      if (((t_zappy_egg *)cur->data)->team_id == team_id)
	{
	  ++count;
	}
      cur = cur->next;
      ++i;
    }
  return (count);
}

t_zappy_egg	*zappy_egg_add(t_zappy * const data,
			       int32_t const team_id,
			       uint64_t const now)
{
  t_zappy_egg	*egg;

  assert(data);
  egg = calloc(1, sizeof(*egg));
  if (egg)
    {
      LOG(LOG_DEBUG, "Adding an egg to the list [%d][%d]",
	  team_id, data->egg_manager.nb_eggs);
      egg->hatch_date = (uint64_t)((600 * 1000) / data->conf.freq) + now;
      egg->team_id = team_id;
      egg->id = data->egg_manager.nb_eggs;
      if (!cqueue_push(&data->egg_manager.eggs, egg))
	{
	  free(egg);
	  return (NULL);
	}
      ++data->egg_manager.nb_eggs;
    }
  return (egg);
}
