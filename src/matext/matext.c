/*
** matext.c for scroll in /gfx_scroller/src
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 13:40:37 2016 Ludovic Petrenko
** Last update Sun Mar 20 16:29:59 2016 Antoine Baché
*/

#include "matext.h"
#include "tools/common.h"

void		drawMatext(t_bunny_pixelarray *pix, t_matext *m)
{
  t_mat3	matrix;
  t_vec3	tmp;
  t_ivec2	incr;
  t_ivec2	pos;
  t_ivec2	center;
  t_color	color;

  matrix = mat3();
  rotate3D(&matrix, m->rot);
  center = ivec2(WIN_X / 2, WIN_Y / 2);
  incr.y = -1;
  while (++incr.y < m->img->clipable.clip_height)
    {
      incr.x = -1;
      while (++incr.x < m->img->clipable.clip_width)
	{
	  color.full = getPixel(m->img, incr);
	  tmp = multMatVec3(&matrix, vec3(incr.x - m->decal.x,
					  incr.y - m->decal.y, 0));
	  pos = addiVec2(to_ivec2(vec2(tmp.x, tmp.y)), center);
	  if (color.full != 0xFF000000)
	    tekpixel(pix, &pos, &color);
	}
    }
}

void	moveMatext(t_matext *m)
{
  m->rot.x += 0.4;
  m->rot.y -= 0.9;
  m->rot.z += 0.2;
}
