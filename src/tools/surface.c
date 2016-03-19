/*
** surface.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 04:36:53 2016 Ludovic Petrenko
** Last update Sat Mar 19 13:13:15 2016 Antoine Baché
*/

#include <math.h>
#include <stdlib.h>
#include "tools/transform.h"

double		surfaceTriangle(t_vec2 a, t_vec2 b, t_vec2 c)
{
  t_vec2	u;
  t_vec2	v;

  u = subVec2(b, a);
  v = subVec2(c, a);
  return ((u.x * v.y - u.y * v.x) / 2);
}

double		surfaceQuad(t_vec2 a, t_vec2 b, t_vec2 c, t_vec2 d)
{
  return (abs((a.x - c.x) * (b.y - d.y)) +
	  abs((b.x - d.x) * (a.y - c.y))) / 2);
}
