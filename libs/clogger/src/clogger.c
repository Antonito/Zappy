/*
** clogger.c for zappy in PSU_2016_zappy/libs/clogger/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 18:08:11 2017 Antoine Baché
** Last update Fri Jun 23 19:46:57 2017 Antoine Baché
*/

#include <assert.h>
#include <stdarg.h>
#include <time.h>
#include "clogger.h"

static char const *	level_str[] =
  {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR"
  };

static int32_t	clogger_print_msg(FILE * const stream,
				  t_clogger_level const level,
				  char const * const fmt,
				  va_list ap)
{
  int32_t	ret;
  time_t	curtime;
  struct tm	*loctime;
  char		buffer[80];

  assert(stream);
  ret = 0;
  curtime = time(NULL);
  loctime = localtime(&curtime);
  if (!loctime)
    {
      perror("localtime");
    }
  else
    {
      strftime(buffer, 80, "%x - %I:%M%p", loctime);
      ret = fprintf(stream, "{ %s | %s } - ",
		    buffer, level_str[level]);
      ret += vfprintf(stream, fmt, ap);
      ret += fprintf(stream, "\n");
    }
  return (ret);
}

static int32_t	clogger_log(t_logger * const self,
			    t_clogger_level const lvl,
			    char const * const fmt, ...)
{
  va_list	ap;
  int32_t	ret;

  assert(self && fmt);
  assert(self->level < NB_CLOGGER_LEVEL);
  ret = 0;
  if (lvl >= self->level)
    {
      va_start(ap, fmt);
      ret = clogger_print_msg(self->stream, lvl, fmt, ap);
      va_end(ap);
    }
  return (ret);
}

static void	clogger_set_loglevel(t_logger * const self,
				     t_clogger_level const lvl)
{
  assert(lvl < NB_CLOGGER_LEVEL);
  self->level = lvl;
}

static void	clogger_set_stream(t_logger * const self,
				   FILE *stream)
{
  assert(stream);
  self->stream = stream;
}

void		clogger_init(t_logger * const self)
{
  assert(self);
  self->log = &clogger_log;
  self->set_level = &clogger_set_loglevel;
  self->set_stream = &clogger_set_stream;
  self->stream = stderr;
  self->level = LOG_DEBUG;
}
