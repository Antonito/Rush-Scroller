/*
** interpolate.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 03:54:34 2016 Ludovic Petrenko
** Last update Sun Mar 20 22:34:44 2016 Antoine Baché
*/

#include <lapin.h>
#include "tools/transform.h"

double		interpolate3f(t_ivec2 corners[3], t_ivec2 pos, double val[3])
{
  double	a[3];
  double	res;

  a[0] = surfaceTriangle(pos, corners[1], corners[2]);
  a[1] = surfaceTriangle(corners[0], pos, corners[2]);
  a[2] = surfaceTriangle(corners[0], corners[1], pos);
  res = (a[0] * val[0] + a[1] * val[1] + a[2] * val[2]) /
    (a[0] + a[1] + a[2]);
  return (res);
}

t_vec2		interpolate3Vec2(t_ivec2 corners[3], t_ivec2 pos,
				 t_vec2 data[3])
{
  double	a[3];
  t_vec2	res;

  a[0] = surfaceTriangle(pos, corners[1], corners[2]);
  a[1] = surfaceTriangle(corners[0], pos, corners[2]);
  a[2] = surfaceTriangle(corners[0], corners[1], pos);
  res.x = (a[0] * data[0].x + a[1] * data[1].x + a[2] * data[2].x) /
    (a[0] + a[1] + a[2]);
  res.y = (a[0] * data[0].y + a[1] * data[1].y + a[2] * data[2].y) /
    (a[0] + a[1] + a[2]);
  return (res);
}

t_vec3		interpolate3Vec3(t_ivec2 corners[3], t_ivec2 pos,
				 t_vec3 data[3])
{
  double	a[3];
  t_vec3	res;

  a[0] = surfaceTriangle(pos, corners[1], corners[2]);
  a[1] = surfaceTriangle(corners[0], pos, corners[2]);
  a[2] = surfaceTriangle(corners[0], corners[1], pos);
  res.x = (a[0] * data[0].x + a[1] * data[1].x + a[2] * data[2].x) /
    (a[0] + a[1] + a[2]);
  res.y = (a[0] * data[0].y + a[1] * data[1].y + a[2] * data[2].y) /
    (a[0] + a[1] + a[2]);
  res.z = (a[0] * data[0].z + a[1] * data[1].z + a[2] * data[2].z) /
    (a[0] + a[1] + a[2]);
  return (res);
}

t_ivec2		interpolate3iVec2(t_ivec2 corners[3], t_ivec2 pos,
				  t_ivec2 data[3])
{
  double	a[3];
  t_ivec2	res;

  a[0] = surfaceTriangle(pos, corners[1], corners[2]);
  a[1] = surfaceTriangle(corners[0], pos, corners[2]);
  a[2] = surfaceTriangle(corners[0], corners[1], pos);
  res.x = (a[0] * data[0].x + a[1] * data[1].x + a[2] * data[2].x) /
    (a[0] + a[1] + a[2]);
  res.y = (a[0] * data[0].y + a[1] * data[1].y + a[2] * data[2].y) /
    (a[0] + a[1] + a[2]);
  return (res);
}
