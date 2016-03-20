/*
** tekpixel.c for scroll in /gfx_scroller/src
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 03:42:39 2016 Ludovic Petrenko
** Last update Sun Mar 20 20:39:55 2016 Antoine Baché
*/

#include "plasma.h"

void		tekpixel2(t_bunny_pixelarray *pix,
			  int x, int y,
			  unsigned int color)
{
  unsigned int	*col;

  if (x > pix->clipable.clip_width || x < 0 ||
      y > pix->clipable.clip_height || y < 0)
    return ;
  col = (unsigned int*)pix->pixels + y * pix->clipable.clip_width + x;
  *col = color;
}
