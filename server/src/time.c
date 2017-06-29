/*
** time.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Thu Jun 29 00:31:46 2017 Antoine Baché
** Last update Thu Jun 29 00:39:09 2017 Antoine Baché
*/

#include <sys/time.h>
#include <string.h>
#include <errno.h>
#include "clogger.h"
#include "zappy_time.h"

uint64_t		zappy_get_cur_time(void)
{
  struct timeval	tv;

  tv = (struct timeval){ 0, 0 };
  if (gettimeofday(&tv, NULL) == -1)
    {
      LOG(LOG_WARNING, "Cannot get time : %s", strerror(errno));
      return (0);
    }
  return ((uint64_t)tv.tv_sec * 1000LL + (uint64_t)tv.tv_usec / 1000LL);
}
