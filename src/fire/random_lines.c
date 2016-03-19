/*
** random_lines.c for gfx_scroller in /gfx_scroller/src/fire
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 02:04:47 2016 Antoine Baché
** Last update Sat Mar 19 02:14:14 2016 Antoine Baché
*/

#include "fire.h"

void	random_lines(short *colors)
{
  int	i;
  int	j;

  i = WIN_X * WIN_Y - 1;
  j = WIN_X * (WIN_Y + 2);
  while (++i < j)
    colors[i] = 50 + (rand() % PALETTE_SIZE - 50);
}
