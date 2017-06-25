/*
** cmempool.h for zappy in PSU_2016_zappy/libs/cmempool/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 17:09:41 2017 Antoine Baché
** Last update Sat Jun 24 18:49:14 2017 Antoine Baché
*/

#ifndef CMEMPOOL_H_
#define CMEMPOOL_H_

#include <stdint.h>

typedef struct	s_cmempool	t_cmempool;

struct		s_cmempool
{
  void		(*free)(t_cmempool * const self, void * const ptr);
  void		*(*malloc)(t_cmempool * const self);
  void		*(*calloc)(t_cmempool * const self);
};

t_cmempool	*cmempool_create(uint32_t const block_size,
				 uint32_t const block_nb);
void		cmempool_destroy(t_cmempool **pool);

#endif /* !CMEMPOOL_H_ */
