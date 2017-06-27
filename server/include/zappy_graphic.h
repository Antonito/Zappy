/*
** zappy_graphic.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 20:16:39 2017 Antoine Baché
** Last update Tue Jun 27 21:31:24 2017 Antoine Baché
*/

#ifndef ZAPPY_GRAPHIC_H_
#define ZAPPY_GRAPHIC_H_

#include <stdbool.h>
#include "zappy_resource.h"

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

void	zappy_graph_bct(t_zappy_client * const cli,
			t_zappy_map_case const * const c, t_zappy *data,
			char const * const arg);
void	zappy_graph_ebo(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_edi(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_eht(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_enw(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_msz(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_pbc(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_pdi(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_pdr(t_zappy_client * const cli,
			t_zappy_resource const res,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_pex(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_pfk(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_pgt(t_zappy_client * const cli,
			t_zappy_resource const res,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_pic(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_pie(t_zappy_client * const cli,
			bool const success,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_pin(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_plv(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_pnw(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_ppo(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_sbp(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_seg(t_zappy_client * const cli,
			t_zappy_team const * const t,
			t_zappy *data,
			char const * const arg);
void	zappy_graph_sgt(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_smg(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_suc(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);
void	zappy_graph_tna(t_zappy_client * const cli, t_zappy *data,
			char const * const arg);

#endif /* !ZAPPY_GRAPHIC_H_ */
