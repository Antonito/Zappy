/*
** alloc_queue.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 18:20:16 2017 Antoine Baché
** Last update Sun Jul  2 22:13:03 2017 Antoine Baché
*/

#include <assert.h>
#include <string.h>
#include <errno.h>
#include "clogger.h"
#include "cmempool.h"
#include "cqueue.h"
#include "zappy_alloc.h"

static t_cmempool	*cqueue_mempool = NULL;

static void	*zappy_alloc_cqueue(size_t count, size_t size)
{
  assert(cqueue_mempool);
  assert(count == 1 && size == sizeof(t_cqueue));
  (void)count;
  (void)size;
  return (cqueue_mempool->calloc(cqueue_mempool));
}

void		zappy_free_cqueue(t_cqueue *ptr)
{
  assert(cqueue_mempool);
  cqueue_mempool->free(cqueue_mempool, ptr);
}

void		zappy_alloc_set_cqueue_pool(t_cmempool *pool)
{
  assert(pool);
  cqueue_mempool = pool;
  cqueue_set_allocator(&zappy_alloc_cqueue);
}
