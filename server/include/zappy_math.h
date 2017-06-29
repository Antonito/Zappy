/*
** zappy_math.h for zappy in PSU_2016_zappy/server/include
**
** Made by Antoine Baché
** Login   <antoine.bache@epitech.net>
**
** Started on  Thu Jun 29 11:54:42 2017 Antoine Baché
** Last update Thu Jun 29 11:56:02 2017 Antoine Baché
*/

#ifndef ZAPPY_MATH_H_
#define ZAPPY_MATH_H_

#define ZAPPY_ABS(a)	(((a) >= 0) ? (a) : -(a))
#define ZAPPY_MIN(a, b)	((a > b) ? (b) : (a))
#define ZAPPY_MAX(a, b)	((a < b) ? (b) : (a))
#define ZAPPY_LEN(a, b)	(((a) * (a)) + ((b) * (b)))

#endif /* !ZAPPY_MATH_H_ */
