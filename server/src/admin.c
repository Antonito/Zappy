/*
** admin.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Mon Jun 26 19:36:44 2017 Antoine Baché
** Last update Mon Jun 26 22:01:58 2017 Antoine Baché
*/

#include <assert.h>
#include <errno.h>
#include <string.h>
#include "clogger.h"
#include "zappy.h"
#include "zappy_color.h"

void			zappy_admin_disconnect(t_zappy_admin * const adm)
{
  assert(adm);
  if (adm->client.sock >= 0)
    {
      closesocket(adm->client.sock);
    }
  adm->client.sock = -1;
  LOG(LOG_INFO, CYAN_BOLD_INTENS"Administrator disconnected"CLEAR);
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
    }
  else if (sock->sock != -1)
    closesocket(rc);
}

int32_t		zappy_start_admin(t_zappy * const data)
{
  int32_t	rc;

  assert(data);
  rc = zappy_create_socket(data->conf.port + 1, &data->admin.sock);
  if (rc)
    {
      LOG(LOG_ERROR, "Cannot create administration socket");
    }
  data->admin.client.sock = -1;
  return (0);
}
