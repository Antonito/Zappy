/*
** zappy_client_serial.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 16:10:08 2017 Antoine Baché
** Last update Thu Jun 29 00:51:52 2017 Antoine Baché
*/

#ifndef ZAPPY_CLIENT_SERIAL_H_
#define ZAPPY_CLIENT_SERIAL_H_

#include <stdint.h>

/*
** Forward declaration of t_cqueue
*/
typedef struct	s_cqueue	t_cqueue;

/*
** Forward declaration of t_zappy
*/
typedef struct	s_zappy		t_zappy;

/*
** Forward declaration of t_zappy_client
*/
typedef struct	s_zappy_client	t_zappy_client;

typedef struct		s_zappy_client_serial
{
  char			buff[4096];
  uint64_t		exec_time;
  void			(*callback)(t_zappy_client * const cli,
				    t_zappy * const data,
				    char const * const arg);
  int32_t		remaining_time;
  int8_t		padding[4];
}			t_zappy_client_serial;

void		zappy_client_serial_sort(t_cqueue **queue);

#endif /* !ZAPPY_CLIENT_SERIAL */
