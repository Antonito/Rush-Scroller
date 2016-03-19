/*
** check_args.c for scroll in /gfx_scroller/src
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 03:41:34 2016 Ludovic Petrenko
** Last update Sat Mar 19 03:41:46 2016 Ludovic Petrenko
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

int	check_args(char **av)
{
  if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0)
    {
      if (my_putstr("Usage: ") || my_putstr(av[0]) ||
	  my_putstr(" [-h]\n\nKeys:\nP : Increase SIZE\n"     \
		    "M : Decrease SIZE\nO : Increase SPEED\n" \
		    "L : Decrease SPEED\nI : Increase COEFF\n" \
		    "K : Decrease COEFF\n"))
	return (1);
    }
  return (0);
}
