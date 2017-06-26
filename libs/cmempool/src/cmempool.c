/*
** cmempool.c for zappy in PSU_2016_zappy/libs/cmempool/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 17:18:34 2017 Antoine Baché
** Last update Sat Jun 24 18:49:02 2017 Antoine Baché
*/

#include <assert.h>
#include <stdlib.h>
#include "cmempool_private.h"

static void		cmempool_free_wrap(t_cmempool * const self,
					   void * const ptr)
{
  t_cmempool_priv	*pool;

  assert(self);
  pool = (t_cmempool_priv *)self;
  cmempool_free(pool, ptr);
}

static void		*cmempool_malloc_wrap(t_cmempool * const self)
{
  t_cmempool_priv	*pool;

  assert(self);
  pool = (t_cmempool_priv *)self;
  return (cmempool_malloc(pool));
}

static void		*cmempool_calloc_wrap(t_cmempool * const self)
{
  t_cmempool_priv	*pool;

  assert(self);
  pool = (t_cmempool_priv *)self;
  return (cmempool_calloc(pool));
}

t_cmempool		*cmempool_create(uint32_t const block_size,
					 uint32_t const block_nb)
{
  t_cmempool_priv	*elem;

  elem = calloc(1, sizeof(*elem));
  if (!elem)
    return (NULL);
  elem->pub.free = &cmempool_free_wrap;
  elem->pub.malloc = &cmempool_malloc_wrap;
  elem->pub.calloc = &cmempool_calloc_wrap;
  elem->size = block_size * block_nb;
  elem->block_size = block_size;
  elem->block_nb = block_nb;
  elem->free_block_nb = block_nb;
  elem->begin = calloc(1, sizeof(uint8_t) * elem->size);
  elem->next = elem->begin;
  if (!elem->begin)
    {
      free(elem);
      return (NULL);
    }
  assert(elem == (t_cmempool_priv *)&elem->pub);
  return (&elem->pub);
}

void			cmempool_destroy(t_cmempool **pool)
{
  t_cmempool_priv	*elem;

  elem = (t_cmempool_priv *)*pool;
  free(elem->begin);
  free(elem);
  *pool = NULL;
}
