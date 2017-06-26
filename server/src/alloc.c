/*
** alloc.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 18:20:16 2017 Antoine Baché
** Last update Sun Jun 25 16:44:32 2017 Antoine Baché
*/

#include <assert.h>
#include <string.h>
#include <errno.h>
#include "clogger.h"
#include "cmempool.h"
#include "cqueue.h"
#include "zappy_alloc.h"
#include "zappy_message.h"
#include "zappy_client_serial.h"

static t_cmempool	*cqueue_mempool = NULL;
static t_cmempool	*message_mempool = NULL;
static t_cmempool	*serial_mempool = NULL;

int32_t			zappy_alloc_init(void)
{
  cqueue_mempool = cmempool_create(sizeof(t_cqueue), 10000);
  message_mempool = cmempool_create(sizeof(t_zappy_message), 10000);
  serial_mempool = cmempool_create(sizeof(t_zappy_client_serial), 10000);
  if (!cqueue_mempool || !message_mempool || !serial_mempool)
    {
      LOG(LOG_ERROR, "Cannot initialize memory pool : %s", strerror(errno));
      return (1);
    }
  zappy_alloc_set_cqueue_pool(cqueue_mempool);
  zappy_alloc_set_message_pool(message_mempool);
  zappy_alloc_set_serial_pool(serial_mempool);
  LOG(LOG_DEBUG, "Memory pool correctly initialized");
  return (0);
}

void			zappy_alloc_deinit(void)
{
  assert(cqueue_mempool && message_mempool && serial_mempool);
  cmempool_destroy(&cqueue_mempool);
  cmempool_destroy(&message_mempool);
  cmempool_destroy(&serial_mempool);
}
