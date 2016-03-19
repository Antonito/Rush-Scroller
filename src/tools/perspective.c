/*
** perspective.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 15:10:03 2016 Ludovic Petrenko
** Last update Sat Mar 19 15:21:09 2016 Ludovic Petrenko
*/

#include <math.h>
#include "tools/transform.h"

t_mat4		perspective(double fov, double ratio, double zNear, double zFar)
{
  t_mat4	m;

  m = mat4();
  m.m00 = atan(fov / 2.0);
  m.m11 = atan(fov / ratio / 2.0);
  m.m22 = (zNear + zFar) / (zNear - zFar);
  m.m23 = 2 * zNear * zFar / (zNear - zFar);
  m.m32 = -1;
  return (m);
}
