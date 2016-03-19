/*
** set_palette.c for scroll in /gfx_scroller/src
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 03:43:48 2016 Ludovic Petrenko
** Last update Sat Mar 19 03:44:00 2016 Ludovic Petrenko
*/

#include "plasma.h"

void		set_palette(unsigned int *palette)
{
  int		i;
  t_color	*color;

  i = -1;
  color = (t_color *)palette;
  while (i++ < 41)
    {
      (color[i]).full = 0xFF0000FF;
      (color[i]).argb[0] = ROUND(255 - (double)(i * 255) / 42);
      (color[i]).argb[1] = ROUND((double)(i * 255) / 42);
    }
  i--;
  while (i++ < 84)
    {
      (color[i]).full = 0xFF00FF00;
      (color[i]).argb[1] = ROUND((255 - (double)(i - 42) * 255 / 43));
      (color[i]).argb[2] = ROUND(((double)(i - 42) * 255 / 43));
    }
  i--;
  while (i++ < 127)
    {
      (color[i]).full = 0xFFFF0000;
      (color[i]).argb[2] = ROUND((255 - (double)(i - 85) * 255 / 43));
      (color[i]).argb[0] = ROUND((double)(i - 85) * 255 / 43);
    }
}
