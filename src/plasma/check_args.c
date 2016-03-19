/*
** check_args.c for scroll in /gfx_scroller/src
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 03:41:34 2016 Ludovic Petrenko
** Last update Sat Mar 19 15:47:21 2016 Antoine Baché
*/

#include "plasma.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (write(1, str + i, 1) == -1)
	return (1);
      i++;
    }
  return (0);
}
