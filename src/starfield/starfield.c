/*
** starfield.c for scroll in /gfx_scroller/src/starfield
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 19:31:12 2016 Ludovic Petrenko
** Last update Sun Mar 20 20:38:02 2016 Antoine Baché
*/

#include <lapin.h>
#include "starfield.h"

void			drawStar(t_bunny_pixelarray *pix, t_star *s)
{
  t_ivec2		screenCenter;
  double		dist;
  t_ivec2		line[2];

  screenCenter = ivec2(WIN_X / 2, WIN_Y / 2);
  dist = ivec2Len(subiVec2(s->pos, screenCenter)) / 50.0;
  line[0] = s->pos;
  line[1] = addiVec2(s->pos, multiVec2(s->dir, dist));
  tekline(pix, line, s->col);
}

void		moveStar(t_star *s)
{
  double	dist;
  t_ivec2	screenCenter;
  t_mat2	rot;

  rot = mat2();
  rotate2D(&rot, 4);
  s->dir = multiVec2(multMatiVec2(&rot, s->dir), 1.1);
  screenCenter = ivec2(WIN_X / 2, WIN_Y / 2);
  dist = ivec2Len(subiVec2(s->pos, screenCenter)) / 300.0;
  s->pos = addiVec2(s->pos, multiVec2(s->dir, dist));
}
