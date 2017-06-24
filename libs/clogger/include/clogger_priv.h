/*
** clogger_priv.h for zappy in PSU_2016_zappy/libs/clogger/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Sat Jun 24 15:07:27 2017 Antoine Baché
** Last update Sat Jun 24 15:10:43 2017 Antoine Baché
*/

#ifndef CLOGGER_PRIV_H_
#define CLOGGER_PRIV_H_

/*
** This header should not be included.
*/
#if defined(__GNUC__)
#define CLOGGER_PRINT_ARG __attribute__((__format__ (__printf__, 3, 0)))
#else
#define CLOGGER_PRINT_ARG
#endif

#endif /* !CLOGGER_PRIV_H_ */
