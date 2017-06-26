/*
** cmempool_priv.c for zappy in PSU_2016_zappy/libs/cmempool/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 17:30:07 2017 Antoine Baché
** Last update Sat Jun 24 18:00:17 2017 Antoine Baché
*/

#include <stddef.h>
#include <string.h>
#include "cmempool_private.h"

static uint32_t	cmempool_get_ndx(t_cmempool_priv const * const self,
				 uint8_t const * const addr)
{
  return ((uint32_t)(addr - self->begin) / self->block_size);
}

static uint32_t	*cmempool_get_addr(t_cmempool_priv const * const self,
				   uint32_t const ndx)
{
  return ((uint32_t *)((uintptr_t)self->begin + (ndx * self->block_size)));
}

void		*cmempool_calloc(t_cmempool_priv * const self)
{
  void		*ret;

  ret = cmempool_malloc(self);
  if (ret)
    {
      memset(ret, 0, self->block_size);
    }
  return (ret);
}

void		*cmempool_malloc(t_cmempool_priv * const self)
{
  uint32_t	*p;
  void		*ret;

  if (self->init_block_nb < self->block_nb)
    {
      p = cmempool_get_addr(self, self->init_block_nb);
      ++self->init_block_nb;
      *p = self->init_block_nb;
    }
  ret = NULL;
  if (self->free_block_nb > 0)
    {
      ret = (void *)self->next;
      if (--self->free_block_nb)
	{
	  self->next =
	    (uint8_t *)cmempool_get_addr(self, *(uint32_t *)(uintptr_t)self->next);
	}
      else
	{
	  self->next = NULL;
	}
    }
  return (ret);
}

void		cmempool_free(t_cmempool_priv * const self,
			      void * const ptr)
{
  if ((uint8_t *)ptr < self->begin ||
      (uint8_t *)ptr > self->begin + self->size)
    {
      return ;
    }
  if (self->next)
    {
      *(uint32_t *)ptr = cmempool_get_ndx(self, self->next);
    }
  else
    {
      *(uint32_t *)ptr = self->block_nb;
    }
  self->next = (uint8_t *)ptr;
  ++self->free_block_nb;
}
