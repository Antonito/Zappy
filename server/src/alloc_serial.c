/*
** alloc_serial.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 16:41:54 2017 Antoine Baché
** Last update Sun Jun 25 16:45:25 2017 Antoine Baché
*/

#include <assert.h>
#include <string.h>
#include <errno.h>
#include "clogger.h"
#include "cmempool.h"
#include "zappy_alloc.h"
#include "zappy_client_serial.h"

static t_cmempool	*serial_mempool = NULL;

void			*zappy_alloc_serial(void)
{
  assert(serial_mempool);
  return (serial_mempool->calloc(serial_mempool));
}

void			zappy_free_serial(t_zappy_client_serial *ptr)
{
  assert(serial_mempool);
  serial_mempool->free(serial_mempool, ptr);
}

void			zappy_alloc_set_serial_pool(t_cmempool *pool)
{
  assert(pool);
  serial_mempool = pool;
}
