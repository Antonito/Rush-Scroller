/*
** display_fire.c for gfx_scroller in /gfx_scroller/src/fire
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 02:07:06 2016 Antoine Baché
** Last update Sat Mar 19 02:07:12 2016 Antoine Baché
*/

#include "fire.h"

void		display_fire(t_bunny_pixelarray *pix,
			     short *colors, unsigned int *palette)
{
  int		i;
  t_color	*color;
  int		size;
  int		tmp;

  i = -1;
  color = pix->pixels;
  size = WIN_X * WIN_Y;
  tmp = WIN_Y / 2;
  while (++i < size)
    {
      if (i < tmp)
	color[i].full = BLACK;
      else if (colors[i] < 89)
	color[i].full = BLACK_COLOR;
      else
	color[i].full = palette[(int)colors[i]];
    }
}
