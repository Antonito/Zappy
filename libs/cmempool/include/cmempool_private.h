/*
** cmempool_private.h for zappy in PSU_2016_zappy/libs/cmempool/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 17:15:12 2017 Antoine Baché
** Last update Sat Jun 24 17:50:29 2017 Antoine Baché
*/

#ifndef CMEMPOOL_PRIVATE_H_
#define CMEMPOOL_PRIVATE_H_

#include "cmempool.h"

typedef struct	s_cmempool_priv
{
  t_cmempool	pub;
  uint8_t	*begin;
  uint8_t	*next;
  uint32_t	size;
  uint32_t	block_size;
  uint32_t	block_nb;
  uint32_t	free_block_nb;
  uint32_t	init_block_nb;
  uint8_t	padding[4];
}		t_cmempool_priv;

void		cmempool_free(t_cmempool_priv * const self, void * const ptr);
void		*cmempool_malloc(t_cmempool_priv * const self);
void		*cmempool_calloc(t_cmempool_priv * const self);

#endif /* !CMEMPOOL_PRIVATE_H_ */
