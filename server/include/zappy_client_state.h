/*
** zappy_client_state.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 23:57:00 2017 Antoine Baché
** Last update Sun Jun 25 16:23:04 2017 Antoine Baché
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
				t_zappy * const data, char const * const);
  void			(*write)(t_zappy_client * const cli,
				 t_zappy * const data);
}			t_zappy_client_state_handle;

/*
** State handler declaration
*/

void	zappy_cli_state_auth_r(t_zappy_client * const cli,
			       t_zappy * const data,
			       char const * const msg);
void	zappy_cli_state_auth_w(t_zappy_client * const cli,
			       t_zappy * const data);
void	zappy_cli_state_conn_r(t_zappy_client * const cli,
			       t_zappy * const data,
			       char const * const msg);
void	zappy_cli_state_conn_w(t_zappy_client * const cli,
			       t_zappy * const data);
void	zappy_cli_state_resp_r(t_zappy_client * const cli,
			       t_zappy * const data,
			       char const * const msg);
void	zappy_cli_state_resp_w(t_zappy_client * const cli,
			       t_zappy * const data);

#endif /* !ZAPPY_CLIENT_STATE_H_ */
