/*
** epur_space.c for epur_space in /info/gfx_scroller/src/tools
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Fri Mar 18 23:49:22 2016 Arthur ARNAUD
** Last update Sat Mar 19 04:54:51 2016 Arthur ARNAUD
*/

#include "tools/font.h"

int	strlenSpace(char *str)
{
  int	i;
  int	j;

  i = -1;
  j= -1;
  while (str[++i] != 0)
    {
      if (str[i] != ' ')
	++j
    }
  return (j);
}
