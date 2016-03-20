/*
** rotozoom.c for scroll in /gfx_scroller/src/rotozoom
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 04:35:46 2016 Ludovic Petrenko
** Last update Sun Mar 20 05:58:44 2016 Ludovic Petrenko
*/

#include <lapin.h>
#include "tools/transform.h"
#include "rotozoom.h"

void	changeZoomRotate(t_roto *roto)
{
  int	s;

  s = (rand() % 2) ? -1 : 1;
  roto->zoomSpeed += (rand() % 10) * s / 10.0;
  s = (rand() % 2) ? -1 : 1;
  roto->rotSpeed += (rand() % 10) * s / 10.0;
  if (fabs(roto->zoomSpeed) > 1.1)
    roto->zoomSpeed = 1.1 * fabs(roto->zoomSpeed) / roto->zoomSpeed;
  if (fabs(roto->rotSpeed) > 1.1)
    roto->rotSpeed = 1.1 * fabs(roto->rotSpeed) / roto->rotSpeed;
  roto->zoom *= roto->zoomSpeed;
  roto->rot *= roto->rotSpeed;
  if (fabs(roto->zoom) > 3)
    roto->zoom = 3 * fabs(roto->zoom) / roto->zoom;
  if (fabs(roto->rot) > 10)
    roto->rot = 10 * fabs(roto->rot) / roto->rot;
}

void	repeatImage(t_bunny_pixelarray *src,
		    t_bunny_pixelarray *dest, double z)
{
  t_vec2	o;
  t_ivec2	incr;

  o = vec2((dest->clipable.clip_width - src->clipable.clip_width * z) / 2,
	    (dest->clipable.clip_height - src->clipable.clip_height * z) / 2);
  while ((o.x > 0.0) ? (o.x -= src->clipable.clip_width * z) : 0);
  while ((o.y > 0.0) ? (o.y -= src->clipable.clip_height * z) : 0);
  incr.y = (int)o.y;
  while (incr.y < dest->clipable.clip_height)
    {
      incr.x = (int)o.x;
      while (incr.x < dest->clipable.clip_width)
	{
	  drawResized(src, dest, vec2(z, z), incr);
	  incr.x += (int)(src->clipable.clip_width * z);
	}
      incr.y += (int)(src->clipable.clip_height * z);
    }
}
