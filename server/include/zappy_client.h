/*
** zappy_client.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 16:58:03 2017 Antoine Baché
** Last update Sat Jun 24 12:37:07 2017 Antoine Baché
*/

#ifndef ZAPPY_CLIENT_H_
#define ZAPPY_CLIENT_H_

#include <stdbool.h>
#include "cqueue.h"
#include "zappy_socket.h"

/*
** Forward declaration of t_zappy
*/
typedef struct s_zappy	t_zappy;

/*
** State that can define a client
** Those state also define the client's behavior
*/
typedef enum		e_zappy_client_state
  {
    CLI_AUTHENTICATING	= 0,
    NB_CLI_STATE
  }			t_zappy_client_state;

/*
** Datas that define a client
** net          -> connection informations
** can_write    -> can we monitor write ?
** connected    -> is the client still connected ?
** state        -> the client's state
** input_queue  -> data received from the server
** output_queue -> data to be sent to the server
** id           -> client identifier
*/
typedef struct		s_zappy_client
{
  t_zappy_socket	net;
  bool			can_write;
  bool			connected;
  t_zappy_client_state	state;
  t_cqueue		*input_queue;
  t_cqueue		*output_queue;
  int32_t		id;
}			t_zappy_client;

/*
** Initialize a client
*/
void			zappy_client_fill(t_zappy_client * const cli,
					  t_sock const sock,
					  t_sockaddr_in *const addr,
					  socklen_t const len);

/*
** Display client informations
*/
void			zappy_client_print(t_zappy_client const * const  cli,
					   char const * const msg);

/*
** Handler for read / write / except events
*/
void			zappy_client_read(t_zappy_client * const cli,
					  t_zappy * const data);
void			zappy_client_write(t_zappy_client * const cli,
					   t_zappy * const data);
void			zappy_client_except(t_zappy_client * const cli,
					    t_zappy * const data);

#endif /* !ZAPPY_CLIENT_H_ */
