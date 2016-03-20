/*
** matext.c for scroll in /gfx_scroller/src
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 13:40:37 2016 Ludovic Petrenko
** Last update Sun Mar 20 15:17:40 2016 Ludovic Petrenko
*/

#include "matext.h"
#include "tools/common.h"

static void	tekbigpixel(t_bunny_pixelarray *pix, t_ivec2 pos, t_color c)
{
  t_ivec2	p[4];

  p[0] = addiVec2(pos, ivec2(-1, 0));
  p[1] = addiVec2(pos, ivec2(1, 0));
  p[2] = addiVec2(pos, ivec2(0, -1));
  p[3] = addiVec2(pos, ivec2(0, 1));
  tekpixel(pix, &pos, &c);
  c.argb[3] >>= 4;
  tekpixel(pix, p, &c);
  tekpixel(pix, p + 1, &c);
  tekpixel(pix, p + 2, &c);
  tekpixel(pix, p + 3, &c);
}

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
	  tekbigpixel(pix, pos, color);
	}
    }

}

void	moveMatext(t_matext *m)
{
  m->rot.x += 2.4;
  m->rot.y -= 5;
  m->rot.z += 0.2;
}
