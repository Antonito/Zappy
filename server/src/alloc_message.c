/*
** alloc_message.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 18:20:16 2017 Antoine Baché
** Last update Sun Jun 25 16:42:27 2017 Antoine Baché
*/

#include <assert.h>
#include <string.h>
#include <errno.h>
#include "clogger.h"
#include "cmempool.h"
#include "zappy_alloc.h"
#include "zappy_message.h"

static t_cmempool	*message_mempool = NULL;

void		*zappy_alloc_message(void)
{
  assert(message_mempool);
  return (message_mempool->calloc(message_mempool));
}

void		zappy_free_message(t_zappy_message *ptr)
{
  assert(message_mempool);
  message_mempool->free(message_mempool, ptr);
}

void		zappy_alloc_set_message_pool(t_cmempool *pool)
{
  assert(pool);
  message_mempool = pool;
}
