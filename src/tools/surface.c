/*
** surface.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 04:36:53 2016 Ludovic Petrenko
** Last update Sat Mar 19 17:59:33 2016 Ludovic Petrenko
*/

#include <math.h>
#include <stdlib.h>
#include "tools/transform.h"

double		surfaceTriangle(t_ivec2 a, t_ivec2 b, t_ivec2 c)
{
  t_ivec2	u;
  t_ivec2	v;

  u = subiVec2(b, a);
  v = subiVec2(c, a);
  return ((u.x * v.y - u.y * v.x) / 2.0);
}

double		surfaceQuad(t_ivec2 a, t_ivec2 b, t_ivec2 c, t_ivec2 d)
{
  return ((abs((a.x - c.x) * (b.y - d.y)) +
	  abs((b.x - d.x) * (a.y - c.y))) / 2.0);
}
