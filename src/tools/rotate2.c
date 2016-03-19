/*
** rotate2.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 15:00:02 2016 Ludovic Petrenko
** Last update Sat Mar 19 15:58:59 2016 Ludovic Petrenko
*/

#include <math.h>
#include "tools/common.h"
#include "tools/transform.h"

static void	rotateX(t_mat4 *m, double deg)
{
  t_mat4	rot;
  double	rad;
  double	s;
  double	c;

  rot = mat4();
  rad = RADIAN(deg);
  s = sin(rad);
  c = cos(rad);
  rot.m11 = c;
  rot.m21 = s;
  rot.m12 = -s;
  rot.m22 = c;
  multMat4(&rot, m);
}

static void	rotateY(t_mat4 *m, double deg)
{
  t_mat4	rot;
  double	rad;
  double	s;
  double	c;

  rot = mat4();
  rad = RADIAN(deg);
  s = sin(rad);
  c = cos(rad);
  rot.m00 = c;
  rot.m02 = s;
  rot.m20 = -s;
  rot.m22 = c;
  multMat4(&rot, m);
}

static void	rotateZ(t_mat4 *m, double deg)
{
  t_mat4	rot;
  double	rad;
  double	s;
  double	c;

  rot = mat4();
  rad = RADIAN(deg);
  s = sin(rad);
  c = cos(rad);
  rot.m00 = c;
  rot.m10 = s;
  rot.m01 = -s;
  rot.m11 = c;
  multMat4(&rot, m);
}
void		rotate4D(t_mat4 *m, t_vec3 deg)
{
  if (deg.z != 0.0)
    rotateZ(m, deg.z);
  if (deg.y != 0.0)
    rotateY(m, deg.y);
  if (deg.x != 0.0)
    rotateX(m, deg.x);
}
