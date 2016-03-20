/*
** move_flag.c for gfx_scroller in /gfx_scroller/src/ondulation
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 04:48:18 2016 Antoine Baché
** Last update Sat Mar 19 23:55:04 2016 Antoine Baché
*/

#include "ondulation.h"

void		fill_column(t_ondulation *ondulation, int deb, int i)
{
  int		j;
  int		k;
  t_color	*color_old;
  t_color	*color_new;

  j = - 1;
  color_old = ondulation->flag->pixels;
  color_new = ondulation->pix->pixels;
  while (++j < ondulation->pix->clipable.buffer.height)
    {
      if (ondulation->inv == 0)
	k = (j - deb) * ondulation->width + i;
      else
	k = (j - deb) * ondulation->width + ondulation->width - i + 1;
      if (j >= deb && j < deb + ondulation->height)
	color_new[j * ondulation->width + i].full = color_old[k].full;
      else
	color_new[j * ondulation->width + i].full = BLACK;
    }
}

void		move_flag(t_ondulation *ondulation)
{
  int		i;
  float		deb;

  i = - 1;
  ondulation->var = ondulation->var + ondulation->dir;
  if (ondulation->var == END_WHILE)
    ondulation->dir = - 1;
  else if (ondulation->var == 0)
    ondulation->dir = 1;
  while (++i < ondulation->width)
    {
      deb = sin((float) i / ondulation->wind +
		(float) ondulation->var / ondulation->speed) * 10;
      deb = deb + ondulation->pix->clipable.buffer.height / 4 * RATIO;
      fill_column(ondulation, (int)deb, i);
    }
}
