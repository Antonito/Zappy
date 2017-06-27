/*
** zappy_client.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 16:58:03 2017 Antoine Baché
** Last update Mon Jun 26 15:17:30 2017 Antoine Baché
*/

#ifndef ZAPPY_CLIENT_H_
#define ZAPPY_CLIENT_H_

#include <stdbool.h>
#include "cqueue.h"
#include "zappy_client_game.h"
#include "zappy_socket.h"
#include "zappy_ring_buffer.h"

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
    CLI_CONNECTED,
    CLI_RESPONSE,
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
** buff         -> ring buffer
*/
typedef struct		s_zappy_client	t_zappy_client;

struct			s_zappy_client
{
  t_cqueue		*input_queue;
  t_cqueue		*output_queue;
  t_zappy_ring_buffer	buff;
  t_zappy_client_game	game;
  t_zappy_socket	net;
  int32_t		id;
  t_zappy_client_state	state;
  bool			can_write;
  bool			connected;
  bool			graphical;
  uint8_t		padding[1];
};

/*
** Initialize a client
*/
void			zappy_client_fill(t_zappy_client * const cli,
					  t_zappy * const data,
					  t_sockaddr_in *const addr,
					  socklen_t const len);

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
