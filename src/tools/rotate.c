#include "tools/transform.h"

void		rotate2D(t_mat2 *m, double deg)
{
  t_mat2	rot;
  double	rad;

  rad = RADIAN(deg);
  rot.m00 = cos(rad);
  rot.m10 = sin(rad);
  rot.m01 = -rot.m10;
  rot.m11 = rot.m00;
  multMat2(&rot, m);
}

void		rotate3D(t_mat2 *m, t_vec3 deg)
{
  t_mat3	rotX;
  t_mat3	rotY;
  t_mat3	rotZ;
  double	rad;

  rad = RADIAN(deg);
  rot.m00 = cos(rad);
  rot.m10 = sin(rad);
  rot.m01 = -rot.m10;
  rot.m11 = rot.m00;
  multMat2(&rot, m);
}
