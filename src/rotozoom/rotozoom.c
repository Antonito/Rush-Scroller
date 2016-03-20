/*
** rotozoom.c for scroll in /gfx_scroller/src/rotozoom
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 04:35:46 2016 Ludovic Petrenko
** Last update Sun Mar 20 20:39:32 2016 Antoine Baché
*/

#include <lapin.h>
#include <math.h>
#include "tools/transform.h"
#include "tools/common.h"
#include "rotozoom.h"

void	changeZoomRotate(t_roto *roto)
{
  int	s;

  s = (rand() % 2) ? -1 : 1;
  roto->zoomSpeed += rand() % 10 / (rand() % 95 + 5.0) * s / 2.0;
  s = (rand() % 2) ? -1 : 1;
  roto->rotSpeed += rand() % 10 * s;
  if (roto->zoomSpeed < 0.1)
    roto->zoomSpeed = 0.1;
  if (roto->rotSpeed > 360)
    roto->rotSpeed -= 360;
  if (roto->rotSpeed < 0)
    roto->rotSpeed += 360;
}

void		repeatImage(t_bunny_pixelarray *src,
			    t_bunny_pixelarray *dest, double z)
{
  t_ivec2	o;
  t_ivec2	incr;
  t_ivec2	dim;
  t_color	color;
  t_ivec2	pos;

  o = ivec2((dest->clipable.clip_width -
	     (int)(src->clipable.clip_width * z)) / 2,
	    (dest->clipable.clip_height -
	     (int)(src->clipable.clip_height * z)) / 2);
  dim = ivec2(src->clipable.clip_width, src->clipable.clip_height);
  dim = multiVec2(dim, z);
  while ((o.x > 0) ? (o.x -= dim.x) : 0);
  while ((o.y > 0) ? (o.y -= dim.y) : 0);
  incr.y = -1;
  while (++incr.y < dest->clipable.clip_height && (incr.x = -1))
    while (++incr.x < dest->clipable.clip_width)
      {
	pos = ivec2((int)((incr.x - o.x) % dim.x / z),
		    (int)((incr.y - o.y) % dim.y / z));
	color.full = getPixel(src, pos);
	tekpixel(dest, &incr, &color);
      }
}

void		rotateImage(t_bunny_pixelarray *s,
			    t_bunny_pixelarray *d, double r)
{
  t_mat3	m;
  t_ivec2	incr;
  t_color	color;
  t_ivec2	v[3];
  t_vec3	tmp;

  v[0] = ivec2(d->clipable.clip_width / 2, d->clipable.clip_height / 2);
  v[2] = subiVec2(v[0], ivec2(s->clipable.clip_width / 2.0,
			      s->clipable.clip_height / 2.0));
  m = mat3();
  translate3(&m, to_vec2(v[0]));
  rotate3D(&m, vec3(0, 0, -r));
  translate3(&m, vec2(-v[0].x, -v[0].y));
  incr.y = -1;
  while (++incr.y < d->clipable.clip_height)
    {
      incr.x = -1;
      while (++incr.x < d->clipable.clip_width)
	{
	  tmp = multMatVec3(&m, vec3(incr.x, incr.y, 1));
	  v[1] = to_ivec2(vec2(tmp.x, tmp.y));
	  color.full = getPixel(s, subiVec2(v[1], v[2]));
	  tekpixel(d, &incr, &color);
	}
    }
}
