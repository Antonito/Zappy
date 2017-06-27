/*
** admin_auth.c for zappy in PSU_2016_zappy/server/src
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Tue Jun 27 09:13:47 2017 Antoine Baché
** Last update Tue Jun 27 10:09:36 2017 Antoine Baché
*/

#include <assert.h>
#include <string.h>
#include "zappy.h"
#include "zappy_admin.h"
#include "zappy_network.h"

/*
** Hard-coded password, not safe at all.
** We should probably load it from a file at runtime.
*/
static char const	*zappy_admin_passwd = "aSuperWeakAndUnsafePassword";

void			zappy_admin_authenticate(t_zappy * const data,
						 char const * const pass)
{
  char const		*resp;

  assert(data->admin.authenticated == false && data && pass);
  resp = "Incorrect password\n";
  if (!memcmp(zappy_admin_passwd, pass, strlen(zappy_admin_passwd)))
    {
      resp = "Authentication successful\n";
      data->admin.authenticated = true;
    }
  zappy_network_write(&data->admin.client, resp, (int32_t)strlen(resp));
}
