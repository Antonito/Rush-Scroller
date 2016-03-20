/*
** morph.c for gfx_scroller in /gfx_scroller/src/transition
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 05:05:23 2016 Antoine Baché
** Last update Sun Mar 20 17:35:55 2016 Antoine Baché
*/

#include "demo.h"
#include "transition.h"

bool		isImg(t_color *colorPix, t_color *colorPix2)
{
  int		i;
  int		size;

  i = 0;
  size = WIN_X * WIN_Y;
  while (i < size)
    {
      if (colorPix[i].full != colorPix2[i].full)
	return (false);
      ++i;
    }
  return (true);
}

int			transitionMorph(t_bunny_pixelarray *pix,
					t_bunny_pixelarray *pix2,
					t_bunny_window *win)
{
  int			i;
  int			size;
  t_color		*colorPix;
  t_color		*colorPix2;
  t_bunny_pixelarray	*final;

  if (colorPix = pix->pixels, colorPix2 = pix2->pixels, size = WIN_X * WIN_Y,
      !(final = bunny_new_pixelarray(WIN_X, WIN_Y)))
    return (1);
  while (!isImg(colorPix, colorPix2) && (i = -1))
    {
      while (++i < size)
	if (colorPix2[i].full > colorPix[i].full)
	  (colorPix[i].full + 0x01010101 > colorPix2[i].full) ?
	    (colorPix[i].full = colorPix2[i].full) :
	    (colorPix[i].full += 0x01010101);
	else if (colorPix2[i].full < colorPix[i].full)
	  (colorPix[i].full - 0x01010101 < colorPix2[i].full) ?
	    (colorPix[i].full = colorPix2[i].full) :
	    (colorPix[i].full -= 0x01010101);
      bunny_blit(&win->buffer, &pix->clipable, 0);
      bunny_display(win);
    }
  return (0);
}
