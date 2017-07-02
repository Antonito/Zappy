/*
** zappy_network_gen.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Fri Jun 23 15:12:38 2017 Antoine Baché
** Last update Sun Jul  2 18:13:24 2017 Antoine Baché
*/

#ifndef ZAPPY_NETWORK_GEN_H_
#define ZAPPY_NETWORK_GEN_H_

/*
** This file provides abstraction that allows
** network to work on MacOS (BSD), Linux and Windows.
*/
#include <stddef.h>
#include <stdint.h>

#if defined(__linux__) || defined(__APPLE__)

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#define closesocket(s) close(s)

/*
** Uniform type declarations
*/
typedef int32_t			t_sock;
typedef struct sockaddr_in	t_sockaddr_in;
typedef struct sockaddr		t_sockaddr;
typedef struct in_addr		t_in_addr;
typedef struct addrinfo		t_addrinfo;
typedef ssize_t			t_ssize;

#elif defined(_WIN32)

/*
** Prevent inclusion of winsock.h in windows.h
*/
#ifndef _WINSOCKAPI_
#define _WINSOCKAPI_
#endif

#include <winsock2.h>
#include <windows.h>
#include <Ws2tcpip.h>
#include <io.h>
#include "zappy_windows.h"

/*
** Link with ws2_32.lib
*/
#pragma comment(lib, "ws2_32.lib")

/*
** Uniform type declarations
*/
typedef SOCKET			t_sock;
typedef SOCKADDR_IN		t_sockaddr_in;
typedef SOCKADDR		t_sockaddr;
typedef IN_ADDR			t_in_addr;
typedef SSIZE_T			t_ssize;
typedef struct	addrinfo	t_addrinfo;

#else

#error "Network is not supported for this plateform"

#endif

#endif /* !ZAPPY_NETWORK_GEN_H_ */
