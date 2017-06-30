/*
** zappy_client_cmd.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sun Jun 25 12:13:06 2017 Antoine Baché
** Last update Fri Jun 30 12:16:39 2017 Antoine Baché
*/

#ifndef ZAPPY_CLIENT_CMD_H_
#define ZAPPY_CLIENT_CMD_H_

#include <stdint.h>

/*
** Forward declaration of t_zappy
*/
typedef struct	s_zappy		t_zappy;

/*
** Forward declaration of t_zappy_client;
*/
typedef struct	s_zappy_client	t_zappy_client;

/*
** All the possible commands
*/
typedef enum			e_zappy_client_cmd_list
  {
    CMD_CONNECT_NBR		= 0,
    CMD_INVENTORY,
    CMD_FORWARD,
    CMD_BROADCAST,
    CMD_LOOK,
    CMD_RIGHT,
    CMD_LEFT,
    CMD_TAKE,
    CMD_SET,
    CMD_EJECT,
    CMD_FORK,
    CMD_INCANTATION,
    CMD_ERR,
    NB_CLIENT_CMD
  }				t_zappy_client_cmd_list;

/*
** handle      -> command callback
** cmd         -> the string to parse with scanf
** time_limit  -> time_limit / freq
*/
typedef struct			s_zappy_client_cmd
{
  void				(*handle)(t_zappy_client * const cli,
					  t_zappy * const data,
					  char const * const arg);
  void				(*on_rec)(t_zappy_client * const cli,
					  t_zappy * const data);
  char const			*cmd;
  int32_t			time_limit;
  int32_t			len;
}				t_zappy_client_cmd;

/*
** on_rec callbacks
*/
void	zappy_client_pre_fork(t_zappy_client * const cli,
			      t_zappy * const data);
void	zappy_client_pre_incantation(t_zappy_client * const cli,
				     t_zappy * const data);

/*
** Callbacks prototypes
*/
void	zappy_client_cmd_broadcast(t_zappy_client * const cli,
				   t_zappy * const data,
				   char const * const arg);
void	zappy_client_cmd_eject(t_zappy_client * const cli,
			       t_zappy * const data,
			       char const * const arg);
void	zappy_client_cmd_fork(t_zappy_client * const cli,
			      t_zappy * const data,
			      char const * const arg);
void	zappy_client_cmd_forward(t_zappy_client * const cli,
				 t_zappy * const data,
				 char const * const arg);
void	zappy_client_cmd_incantation(t_zappy_client * const cli,
				     t_zappy * const data,
				     char const * const arg);
void	zappy_client_cmd_inventory(t_zappy_client * const cli,
				   t_zappy * const data,
				   char const * const arg);
void	zappy_client_cmd_left(t_zappy_client * const cli,
			      t_zappy * const data,
			      char const * const arg);
void	zappy_client_cmd_look(t_zappy_client * const cli,
			      t_zappy * const data,
			      char const * const arg);
void	zappy_client_cmd_right(t_zappy_client * const cli,
			       t_zappy * const data,
			       char const * const arg);
void	zappy_client_cmd_set(t_zappy_client * const cli,
			     t_zappy * const data,
			     char const * const arg);
void	zappy_client_cmd_take(t_zappy_client * const cli,
			      t_zappy * const data,
			      char const * const arg);
void	zappy_client_cmd_err(t_zappy_client * const cli,
			     t_zappy * const data,
			     char const * const arg);
void	zappy_client_cmd_connect_nbr(t_zappy_client * const cli,
				     t_zappy * const data,
				     char const * const arg);
void	zappy_client_cmd_dead(t_zappy_client * const cli,
			      t_zappy * const data,
			      char const * const arg);

#endif /* !ZAPPY_CLIENT_CMD_H_ */
