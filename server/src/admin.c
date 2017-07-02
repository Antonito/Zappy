/*
** admin.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 19:36:44 2017 Antoine Baché
** Last update Sun Jul  2 22:47:54 2017 Antoine Baché
*/

#include <assert.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_color.h"
#include "zappy_admin_cmd.h"

ZAPPY_PRINT_ARG
int32_t		zappy_adm_send(t_zappy *data, char const * fmt, ...)
{
  int32_t	ret;
  va_list	ap;

  va_start(ap, fmt);
#if defined(__linux__) || defined(__APPLE__)
  ret = vdprintf(data->admin.client.sock, fmt, ap);
#else
  ret = vfprintf(data->admin.sock_stream, fmt, ap);
#endif
  va_end(ap);
  return (ret);
}

void			zappy_admin_disconnect(t_zappy_admin * const adm)
{
  assert(adm);
  if (adm->client.sock >= 0)
    {
      closesocket(adm->client.sock);
    }
  adm->client.sock = -1;
  adm->sock_stream = NULL;
  LOG(LOG_INFO, CYAN_BOLD_INTENS"Administrator disconnected"CLEAR);
}

static void		zappy_admin_stream(t_zappy * const data)
{
  if (data->admin.client.sock != -1)
    {
      data->admin.sock_stream = fdopen(data->admin.client.sock, "w");
      if (!data->admin.sock_stream)
	{
	  LOG(LOG_WARNING, "Cannot create sock stream");
	  closesocket(data->admin.client.sock);
	  data->admin.client.sock = -1;
	}
    }
}

void			zappy_admin_accept(t_zappy * const data)
{
  t_zappy_socket	*sock;
  socklen_t		len;
  int32_t		rc;

  assert(data);
  sock = &data->admin.client;
  errno = EINTR;
  rc = -1;
  while (rc == -1 && errno == EINTR)
    {
      memset(&sock->addr, 0, sizeof(sock->addr));
      len = sizeof(sock->addr);
      rc = accept(data->admin.sock.sock,
		  (t_sockaddr *)&sock->addr, &len);
    }
  if (sock->sock == -1 && rc >= 0)
    {
      sock->sock = rc;
      LOG(LOG_INFO, CYAN_BOLD_INTENS"Administrator connected !"CLEAR);
      data->admin.can_write = false;
      data->admin.authenticated = false;
    }
  else if (sock->sock != -1)
    closesocket(rc);
  zappy_admin_stream(data);
}

int32_t			zappy_start_admin(t_zappy * const data)
{
  int32_t		rc;

  assert(data);
  rc = zappy_create_socket(data->conf.port + 1, &data->admin.sock);
  if (rc)
    {
      LOG(LOG_ERROR, "Cannot create administration socket");
    }
  data->admin.sock_stream = NULL;
  data->admin.client.sock = -1;
  return (0);
}
