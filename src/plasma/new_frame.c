/*
** new_frame.c for scroll in /gfx_scroller/src
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 03:44:13 2016 Ludovic Petrenko
** Last update Sat Mar 19 03:57:47 2016 Antoine Baché
*/

#include "plasma.h"

void		new_frame(t_plasma *plasma)
{
  int		i;
  int		j;
  double	incr;
  int		pal;
  unsigned int	color;

  i = 0;
  while (i < plasma->pix->clipable.clip_height)
    {
      j = 0;
      while (j < plasma->pix->clipable.clip_width)
	{
	  incr = (double)(plasma->origin) * plasma->speed / 10;
	  pal = ((int)(127 * plasma->coeff *
	  	       (cos(RAD(i / plasma->size) - incr) +
	  		sin(RAD(j / plasma->size) - incr)) -
	  	       plasma->origin +
	  	       cos(i / 10.0f + j / 100.0f))) % 128;
	  color = plasma->palette[pal < 0 ? pal + 128 : pal];
	  tekpixel2(plasma->pix, j, i, color);
	  j++;
	}
      i++;
    }
}
