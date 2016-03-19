/*
** mult_mat.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 02:17:53 2016 Ludovic Petrenko
** Last update Sat Mar 19 02:18:00 2016 Ludovic Petrenko
*/

#include "tools/transform->h"

void		multMat2(t_mat2 *m2, t_mat2 *m)
{
  t_mat2	t;
  t_mat2	n;

  t = *m;
  n = *m2;
  m->m00 = t.m00 * n.m00 + t.m01 * n.m10;
  m->m01 = t.m00 * n.m01 + t.m01 * n.m11;
  m->m10 = t.m10 * n.m00 + t.m11 * n.m10;
  m->m11 = t.m10 * n.m01 + t.m11 * n.m11;
}

void		multMat3(t_mat3 *m2, t_mat3 *m)
{
  t_mat3	t;
  t_mat3	n;

  t = *m;
  n = *m2;
  m->m00 = t.m00 * n.m00 + t.m01 * n.m10 + t.m02 * n.m20;
  m->m01 = t.m00 * n.m01 + t.m01 * n.m11 + t.m02 * n.m21;
  m->m02 = t.m00 * n.m02 + t.m01 * n.m12 + t.m02 * n.m22;
  m->m10 = t.m10 * n.m00 + t.m11 * n.m10 + t.m12 * n.m20;
  m->m11 = t.m10 * n.m01 + t.m11 * n.m11 + t.m12 * n.m21;
  m->m12 = t.m10 * n.m02 + t.m11 * n.m12 + t.m12 * n.m22;
  m->m20 = t.m20 * n.m00 + t.m21 * n.m10 + t.m22 * n.m20;
  m->m21 = t.m20 * n.m01 + t.m21 * n.m11 + t.m22 * n.m21;
  m->m22 = t.m20 * n.m02 + t.m21 * n.m12 + t.m22 * n.m22;
}

void		multMat4(t_mat4 *m2, t_mat4 m)
{
  t_mat4	t;
  t_mat4	n;

  t = *m;
  n = *m2;
  m->m00 = t.m00 * n.m00 + t.m01 * n.m10 + t.m02 * n.m20 + t.m03 * n.m30;
  m->m01 = t.m00 * n.m01 + t.m01 * n.m11 + t.m02 * n.m21 + t.m03 * n.m31;
  m->m02 = t.m00 * n.m02 + t.m01 * n.m12 + t.m02 * n.m22 + t.m03 * n.m32;
  m->m03 = t.m00 * n.m03 + t.m01 * n.m13 + t.m02 * n.m23 + t.m03 * n.m33;
  m->m10 = t.m10 * n.m00 + t.m11 * n.m10 + t.m12 * n.m20 + t.m13 * n.m30;
  m->m11 = t.m10 * n.m01 + t.m11 * n.m11 + t.m12 * n.m21 + t.m13 * n.m31;
  m->m12 = t.m10 * n.m02 + t.m11 * n.m12 + t.m12 * n.m22 + t.m13 * n.m32;
  m->m13 = t.m10 * n.m03 + t.m11 * n.m13 + t.m12 * n.m23 + t.m13 * n.m33;
  m->m20 = t.m20 * n.m00 + t.m21 * n.m10 + t.m22 * n.m20 + t.m23 * n.m30;
  m->m21 = t.m20 * n.m01 + t.m21 * n.m11 + t.m22 * n.m21 + t.m23 * n.m31;
  m->m22 = t.m20 * n.m02 + t.m21 * n.m12 + t.m22 * n.m22 + t.m23 * n.m32;
  m->m23 = t.m20 * n.m03 + t.m21 * n.m13 + t.m22 * n.m23 + t.m23 * n.m33;
  m->m30 = t.m30 * n.m00 + t.m31 * n.m10 + t.m32 * n.m20 + t.m33 * n.m30;
  m->m31 = t.m30 * n.m01 + t.m31 * n.m11 + t.m32 * n.m21 + t.m33 * n.m31;
  m->m32 = t.m30 * n.m02 + t.m31 * n.m12 + t.m32 * n.m22 + t.m33 * n.m32;
  m->m33 = t.m30 * n.m03 + t.m31 * n.m13 + t.m32 * n.m23 + t.m33 * n.m33;
}
