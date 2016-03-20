/*
** my_blit.c for gfx_scroller in /gfx_scroller/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 00:09:43 2016 Antoine Baché
** Last update Sun Mar 20 01:13:36 2016 Ludovic Petrenko
*/

#include "tools/common.h"
#include "tools/transform.h"

void		myBlit(const t_bunny_pixelarray *src,
		       t_bunny_pixelarray *dest, t_ivec2 pos)
{
  t_color	*colorSrc;
  int		i;
  int		j;
  t_ivec2	newPos;

  colorSrc = src->pixels;
  i = 0;
  while (i < src->clipable.clip_height)
    {
      j = 0;
      while (j < src->clipable.clip_width)
	{
	  newPos.x = pos.x + j;
	  newPos.y = pos.y + i;
	  tekpixel(dest, &newPos, &colorSrc[i * src->clipable.clip_width + j]);
	  ++j;
	}
      ++i;
    }
}
