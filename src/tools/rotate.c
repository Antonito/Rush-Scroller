/*
** rotate.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 02:16:38 2016 Ludovic Petrenko
** Last update Sun Mar 20 10:26:43 2016 Ludovic Petrenko
*/

#include <math.h>
#include "tools/common.h"
#include "tools/transform.h"

void		rotate2D(t_mat2 *m, double deg)
{
  t_mat2	rot;
  double	rad;
  double	s;
  double	c;

  rot = mat2();
  rad = RADIAN(deg);
  s = sin(rad);
  c = cos(rad);
  rot.m00 = c;
  rot.m10 = s;
  rot.m01 = -s;
  rot.m11 = c;
  multMat2(&rot, m);
}

static void	rotateX(t_mat3 *m, double deg)
{
  t_mat3	rot;
  double	rad;
  double	s;
  double	c;

  rot = mat3();
  rad = RADIAN(deg);
  s = sin(rad);
  c = cos(rad);
  rot.m11 = c;
  rot.m21 = s;
  rot.m12 = -s;
  rot.m22 = c;
  multMat3(&rot, m);
}

static void	rotateY(t_mat3 *m, double deg)
{
  t_mat3	rot;
  double	rad;
  double	s;
  double	c;

  rot = mat3();
  rad = RADIAN(deg);
  s = sin(rad);
  c = cos(rad);
  rot.m00 = c;
  rot.m02 = s;
  rot.m20 = -s;
  rot.m22 = c;
  multMat3(&rot, m);
}

static void	rotateZ(t_mat3 *m, double deg)
{
  t_mat3	rot;
  double	rad;
  double	s;
  double	c;

  rot = mat3();
  rad = RADIAN(deg);
  s = sin(rad);
  c = cos(rad);
  rot.m00 = c;
  rot.m10 = s;
  rot.m01 = -s;
  rot.m11 = c;
  multMat3(&rot, m);
}
void		rotate3D(t_mat3 *m, t_vec3 deg)
{
  if (deg.z != 0.0)
    rotateZ(m, deg.z);
  if (deg.y != 0.0)
    rotateY(m, deg.y);
  if (deg.x != 0.0)
    rotateX(m, deg.x);
}
