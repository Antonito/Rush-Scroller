/*
** draw_transformed.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 16:03:21 2016 Ludovic Petrenko
** Last update Sun Mar 20 19:27:17 2016 Arthur ARNAUD
*/

#include <stdbool.h>
#include "tools/transform.h"
#include "tools/common.h"

static	int sign(t_ivec2 pt1, t_ivec2 pt2, t_ivec2 pt3)
{
  int	s;

  s = (pt1.x - pt3.x) * (pt2.y - pt3.y) -
    (pt2.x - pt3.x) * (pt1.y - pt3.y);
  return (s);
}

static bool	isInTriangle(t_ivec2 pt, t_ivec2 t[3])
{
  bool	b[3];

  b[0] = sign(pt, t[0], t[1]) < 0;
  b[1] = sign(pt, t[1], t[2]) < 0;
  b[2] = sign(pt, t[0], t[2]) < 0;
  return ((b[0] == b[1]) && (b[1] == b[2]));
}

void	drawTransformedTriangle(t_bunny_pixelarray *src,
				t_bunny_pixelarray *dest,
				t_ivec2 corners[3],
				t_ivec2 texCoords[3])
{
  t_ivec2	pt;
  t_ivec2	interpolated;
  t_color	color;

  pt.y = -1;
  while (++pt.y < dest->clipable.clip_height)
    {
      pt.x = -1;
      while (++pt.x < dest->clipable.clip_height)
	{
	  if (isInTriangle(pt, corners))
	    {
	      interpolated = interpolate3iVec2(corners, pt, texCoords);
	      color.full = getPixel(src, interpolated);
	      tekpixel(dest, &pt, &color);
	    }
	}
    }
}

void	drawTransformed(t_bunny_pixelarray *src, t_bunny_pixelarray *dest,
			t_mat2 *transform)
{
  t_ivec2	t1[3];
  t_ivec2	t2[3];
  t_ivec2	texCoords1[3];
  t_ivec2	texCoords2[3];

  texCoords1[0] = texCoords2[0] = ivec2(0, 0);
  texCoords1[1] = ivec2(0, src->clipable.clip_height);
  texCoords1[2] = texCoords2[1] = ivec2(src->clipable.clip_width,
					src->clipable.clip_height);
  texCoords2[2] = ivec2(src->clipable.clip_width, 0);
  t1[0] = t2[0] = multMatiVec2(transform, texCoords1[0]);
  t1[1] = multMatiVec2(transform, texCoords1[1]);
  t1[2] = t2[1] = multMatiVec2(transform, texCoords1[2]);
  t2[2] = multMatiVec2(transform, texCoords2[2]);
  drawTransformedTriangle(src, dest, t1, texCoords1);
  drawTransformedTriangle(src, dest, t2, texCoords2);
}

void	drawResized(t_bunny_pixelarray *src, t_bunny_pixelarray *dest,
		    t_vec2 scale, t_ivec2 pos)
{
  t_ivec2	incr;
  t_ivec2	tmp;
  t_color	color;
  t_ivec2	finalPos;

  incr.y = -1;
  while (++incr.y < dest->clipable.clip_height)
    {
      incr.x = -1;
      while (++incr.x < dest->clipable.clip_width)
	{
	  tmp.x = incr.x / scale.x;
	  tmp.y = incr.y / scale.y;
	  if (scale.x < 0.0)
	    tmp.x += src->clipable.clip_width;
	  if (scale.y < 0.0)
	    tmp.y += src->clipable.clip_height;
	  color.full = getPixel(src, tmp);
	  finalPos = addiVec2(incr, pos);
	  tekpixel(dest, &finalPos, &color);
	}
    }
}
