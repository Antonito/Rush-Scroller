/*
** starfield.c for scroll in /gfx_scroller/src/starfield
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 19:31:12 2016 Ludovic Petrenko
** Last update Sat Mar 19 20:05:25 2016 Ludovic Petrenko
*/

#include <lapin.h>
#include "starfield.h"

void			drawStar(t_bunny_pixelarray *pix, t_star *s)
{
  static const t_ivec2	screenCenter = ivec2(WIN_X / 2, WIN_Y / 2);
  double		dist;
  t_ivec2		line[2];
  unsigned int		color[2];

  color = {0xFFFFFFFF, 0xFFFFFFFF};
  dist = ivec2Len(subiVec2(s->pos, screenCenter)) / 50.0;
  line[0] = s->pos;
  line[1] = addiVec2(s->pos, multiVec2(s->dir, dist));
  bunny_set_line(&pix->clipable.buffer, line, color);
}

void	moveStar(t_star *s)
{
  double	dist;

  dist = ivec2Len(subiVec2(s->pos, screenCenter)) / 100.0;
  s->pos = addiVec2(s->pos, multiVec2(s->dir, dist));
}
