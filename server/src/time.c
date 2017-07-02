/*
** time.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Thu Jun 29 00:31:46 2017 Antoine Baché
** Last update Sun Jul  2 20:37:51 2017 Antoine Baché
*/

#if defined(__linux__) || defined(__APPLE__)
#include <sys/time.h>
#else
#include <windows.h>
#endif
#include <string.h>
#include <errno.h>
#include "clogger.h"
#include "zappy_time.h"

#if defined(__linux__) || defined(__APPLE__)
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
#elif defined(_WIN32)
uint64_t		zappy_get_cur_time(void)
{
  LARGE_INTEGER		freq;
  LARGE_INTEGER		t;

  QueryPerformanceFrequency(&freq);
  QueryPerformanceFrequency(&t);
  return ((uint64_t)(1000000 * t.QuadPart) / freq.QuadPart);
}
#else
#error "Unsupported plateform"
#endif
