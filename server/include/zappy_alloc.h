/*
** zappy_alloc.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 18:27:02 2017 Antoine Baché
** Last update Sun Jun 25 16:47:27 2017 Antoine Baché
*/

#ifndef ZAPPY_ALLOC_H_
#define ZAPPY_ALLOC_H_

#include <stdint.h>

/*
** Forward declaration of t_cmempool
*/
typedef struct	s_cmempool	t_cmempool;

/*
** Forward declaration of t_cqueue
*/
typedef struct	s_cqueue	t_cqueue;

/*
** Forward declaration of t_zappy_message
*/
typedef struct	s_zappy_message	t_zappy_message;

/*
** Forward declaration of t_zappy_client_serial
*/
typedef struct	s_zappy_client_serial	t_zappy_client_serial;

int32_t		zappy_alloc_init(void);
void		zappy_alloc_deinit(void);

void		zappy_free_cqueue(t_cqueue *ptr);
void		zappy_free_message(t_zappy_message *ptr);
void		zappy_free_serial(t_zappy_client_serial *ptr);
void		*zappy_alloc_message(void);
void		*zappy_alloc_serial(void);

void		zappy_alloc_set_cqueue_pool(t_cmempool *pool);
void		zappy_alloc_set_message_pool(t_cmempool *pool);
void		zappy_alloc_set_serial_pool(t_cmempool *pool);

#endif /* !ZAPPY_ALLOC_H_ */
