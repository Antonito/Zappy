/*
** zappy_client_state.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 23:57:00 2017 Antoine Baché
** Last update Sat Jun 24 00:29:43 2017 Antoine Baché
*/

#ifndef ZAPPY_CLIENT_STATE_H_
#define ZAPPY_CLIENT_STATE_H_

/*
** Forward declaration of t_zappy
*/
typedef struct		s_zappy	t_zappy;

/*
** Forward declaration of t_zappy_client
*/
typedef struct		s_zappy_client	t_zappy_client;

/*
** Define a state's handler for read and write events
*/
typedef struct		s_zappy_client_state_handle
{
  void			(*read)(t_zappy_client * const cli,
				t_zappy * const data);
  void			(*write)(t_zappy_client * const cli,
				 t_zappy * const data);
}			t_zappy_client_state_handle;

/*
** State handler declaration
*/
#define DEC_STATE_ARGS	t_zappy_client *const cli, t_zappy * const data
#define DEC_STATE_R(n)	void	zappy_cli_state_##n##_r(DEC_STATE_ARGS)
#define DEC_STATE_W(n)	void	zappy_cli_state_##n##_w(DEC_STATE_ARGS)
#define DEC_STATE(n)	DEC_STATE_R(n); DEC_STATE_W(n)

DEC_STATE(auth);

#undef DEC_STATE_ARGS
#undef DEC_STATE_R
#undef DEC_STATE_W
#undef DEC_STATE

#endif /* !ZAPPY_CLIENT_STATE_H_ */
