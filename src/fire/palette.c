/*
** palette.c for gfx_scroller in /gfx_scroller/src/fire
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 02:05:12 2016 Antoine Baché
** Last update Sat Mar 19 02:05:19 2016 Antoine Baché
*/

#include "fire.h"

unsigned int	check_gradient(int i)
{
  t_color	color;

  color.full = 0;
  if (i > 0 && i <= 64)
    color.argb[0] = ((i - 1) << 1);
  else if (i > 64 && i <= 128)
    {
      color.argb[0] = 255;
      color.argb[1] = ((i - 1) << 2) - 255;
    }
  else if (i > 128 && i < 192)
    {
      color.argb[0] = 255;
      color.argb[1] = 255;
      color.argb[2] = ((i - 1) << 2) - 510;
    }
  return (color.full);
}

void	palette_generator(unsigned int *palette)
{
  int	i;

  i = -1;
  while (++i < PALETTE_SIZE)
    {
      if (i == 0)
	palette[i] = BLACK_COLOR;
      else if (i > 192 && i < 256)
	palette[i] = WHITE_COLOR;
      else
	palette[i] = check_gradient(i);
    }
}
