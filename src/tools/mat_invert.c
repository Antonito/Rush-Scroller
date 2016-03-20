/*
** mat_invert.c for scroll in /gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 09:48:34 2016 Ludovic Petrenko
** Last update Sun Mar 20 10:08:01 2016 Ludovic Petrenko
*/

#include "tools/transform.h"

void		mat2Invert(t_mat2 *m)
{
  t_mat2	t;
  double	det;

  t = *m;
  det = t.m00 * t.m11 - t.m01 * t.m10;
  m->m00 = t.m11 / det;
  m->m01 = -t.m01 / det;
  m->m10 = -t.m10 / det;
  m->m11 = t.m00 / det;
}

void		mat3Invert(t_mat3 *m)
{
  t_mat3	t;
  double	det;

  t = *m;
  det = t.m00 * (t.m11 * t.m22 - t.m21 * t.m12) -
    t.m01 * (t.m10 * t.m22 - t.m20 * t.m12) +
    t.m02 * (t.m10 * t.m21 - t.m20 * t.m11);
  m->m00 = (t.m11 * t.m22 - t.m12 * t.m21) / det;
  m->m01 = (t.m21 * t.m02 - t.m01 * t.m22) / det;
  m->m02 = (t.m01 * t.m12 - t.m11 * t.m02) / det;
  m->m10 = (t.m12 * t.m20 - t.m10 * t.m22) / det;
  m->m11 = (t.m00 * t.m22 - t.m20 * t.m02) / det;
  m->m12 = (t.m10 * t.m02 - t.m00 * t.m12) / det;
  m->m20 = (t.m10 * t.m21 - t.m20 * t.m11) / det;
  m->m21 = (t.m20 * t.m01 - t.m00 * t.m21) / det;
  m->m22 = (t.m00 * t.m11 - t.m01 * t.m10) / det;
}
