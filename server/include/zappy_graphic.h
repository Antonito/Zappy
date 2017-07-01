/*
** zappy_graphic.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 20:16:39 2017 Antoine Baché
** Last update Sat Jul  1 10:27:53 2017 Antoine Baché
*/

#ifndef ZAPPY_GRAPHIC_H_
#define ZAPPY_GRAPHIC_H_

#include <stdbool.h>
#include "zappy_resource.h"

#if defined __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

/*
** Forward declaration of t_zappy
*/
typedef struct	s_zappy			t_zappy;

/*
** Forward declaration of t_zappy_team
*/
typedef struct	s_zappy_team		t_zappy_team;

/*
** Forward declaration of t_zappy
*/
typedef struct	s_zappy_map_case	t_zappy_map_case;

/*
** Forward declaration of t_zappy
*/
typedef struct	s_zappy_client		t_zappy_client;

typedef struct				s_zappy_graph_arg
{
  void					*ptr;
  t_zappy_resource			res;
  bool					success;
}					t_zappy_graph_arg;

typedef void (*t_zappy_graphic_handle)(t_zappy_client * const,
				       t_zappy_graph_arg *,
				       t_zappy *,
				       char const * const);

typedef struct				s_zappy_graph_callback
{
  t_zappy_graph_arg			*g;
  t_zappy				*data;
  char const				*arg;
  t_zappy_graphic_handle		handle;
}					t_zappy_graph_callback;

void	zappy_graph_edi(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_msz(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_pic(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_sbp(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_sgt(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_smg(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_suc(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_tna(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);

/*
** Eggs commands
*/
void	zappy_graph_ebo(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_enw(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_eht(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);

/*
** Client commands
*/
void	zappy_graph_pdi(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_pbc(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_pnw(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_ppo(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_plv(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_pex(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_pin(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_pfk(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_pie(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);

/*
** Resource commands
*/
void	zappy_graph_pdr(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_pgt(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);

/*
** Other commands
*/
void	zappy_graph_seg(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_bct(t_zappy_client * const cli,
			t_zappy_graph_arg *g,
			t_zappy *data,
			char const * const arg);

/*
** Management functions
*/
void	zappy_graph_connect(t_zappy_client *cli, t_zappy *data);
void	zappy_graph_send(t_zappy_graph_arg *g,
			 t_zappy * data,
			 char const * const arg,
			 t_zappy_graphic_handle handle);

#if defined __clang__
#pragma clang diagnostic pop
#endif

#endif /* !ZAPPY_GRAPHIC_H_ */
