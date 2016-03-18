/*
** my_blit.c for gfx_scroller in /gfx_scroller/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 00:09:43 2016 Antoine Baché
** Last update Sat Mar 19 00:44:38 2016 Antoine Baché
*/

#include "tools/common.h"

void		myBlit(const t_bunny_pixelarray *src,
		       t_bunny_pixelarray *dest, double transp, t_ivec2 pos)
{
  t_color	*colorSrc;
  t_color	*colorDest;
  int		i;
  int		j;
  int		size;
  t_ivec2	newPos;

  colorSrc = src->pixels;
  colorDest = dest->pixels;
  i = 0;
  while (i < src->clipable.clip_height)
    {
      j = 0;
      while (j < src->clipable.clip_width)
	{
	  newPos.x = pos.x + j;
	  newPos.y = pos.y + i;
	  tekpixelTransp(dest, &newPos,
			 colorSrc[i * src->clipable.clip_height + j].full,
			 transp);
	  ++j;
	}
      ++i;
    }
}
