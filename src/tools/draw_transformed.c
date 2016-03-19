/*
** draw_transformed.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 16:03:21 2016 Ludovic Petrenko
** Last update Sat Mar 19 16:13:32 2016 Ludovic Petrenko
*/

#include "tools/transform.h"

void	drawTransformed(t_bunny_pixelarray *src, t_bunny_pixelarray *dest,
			t_mat2 *transform)
{
  t_ivec2	t1[3];
  t_ivec2	t2[3];

  t1[0] = t2[0] = ivec2(0, 0);
  t1[1] = ivec2(0, src->clipable.clip_height);
  t1[2] = t2[1] = ivec2(scr->clipable.clip_width, src->clipable.clip_height);
  t2[2] = ivec2(src->clipable.clip_width, 0);
  multMatVec2(transform, t1);
  multMatVec2(transform, t1 + 1);
  multMatVec2(transform, t1 + 2);
  multMatVec2(transform, t2);
  multMatVec2(transform, t2 + 1);
  multMatVec2(transform, t2 + 2);
  drawTransformedTriangle(src, dest
}
