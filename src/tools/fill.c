/*
** fill.c for gfx_scroller in /gfx_scroller/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 00:50:06 2016 Antoine Baché
** Last update Sat Mar 19 02:11:39 2016 Antoine Baché
*/

#include "tools/common.h"
#include "tools/transform.h"

void		fillColor(t_bunny_pixelarray *pix, t_color *color,
			  double transp)
{
  int		i;
  int		j;
  t_ivec2	pos;

  i = 0;
  while (i < pix->clipable.clip_height)
    {
      j = 0;
      while (j < pix->clipable.clip_width)
	{
	  pos.x = j;
	  pos.y = i;
	  tekpixelTransp(pix, &pos, color, transp);
	  ++j;
	}
      ++i;
    }
}

void		clearColor(t_bunny_pixelarray *pix, unsigned int color)
{
  int		i;
  int		size;
  t_color	*colors;

  i = 0;
  size = pix->clipable.clip_width * pix->clipable.clip_height;
  colors = pix->pixels;
  while (i < size)
    {
      colors[i].full = color;
      ++i;
    }
}
