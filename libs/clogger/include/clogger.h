/*
** clogger.h for zappy in PSU_2016_zappy/libs/clogger/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 18:02:48 2017 Antoine Baché
** Last update Sat Jun 24 15:13:55 2017 Antoine Baché
*/

#ifndef CLOGGER_H_
#define CLOGGER_H_

#include <stdio.h>
#include <stdint.h>

#if defined __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu-zero-variadic-macro-arguments"
#endif

#define LOG(lvl, fmt, ...) g_log.log(&g_log, lvl, fmt, ##__VA_ARGS__)

#if defined __clang__
#pragma clang diagnostic pop
#endif

typedef struct s_logger	t_logger;

typedef enum		e_clogger_level
  {
    LOG_DEBUG		= 0,
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    NB_CLOGGER_LEVEL
  }			t_clogger_level;

struct			s_logger
{
  int32_t		(*log)(t_logger * const self,
			       t_clogger_level const lvl,
			       char const * const fmt, ...);
  void			(*set_level)(t_logger * const self,
				     t_clogger_level const level);
  void			(*set_stream)(t_logger * const self,
				      FILE *stream);
  FILE			*stream;
  t_clogger_level	level;
  uint8_t		padding[4];
};

void			clogger_init(t_logger * const self);

extern t_logger		g_log;

#endif /* !CLOGGER_H_ */
