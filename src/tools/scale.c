/*
** scale.c for scroll in /home/petren_l/rendu/tek1/semestre_02/gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 15:02:30 2016 Ludovic Petrenko
** Last update Sat Mar 19 15:58:02 2016 Ludovic Petrenko
*/

#include "tools/transform.h"

void		scale2D(t_mat2 *m, t_vec2 s)
{
  t_mat2	scale;

  scale = mat2();
  scale.m00 = s.x;
  scale.m11 = s.y;
  multMat2(&scale, m);
}

void		scale3D(t_mat3 *m, t_vec3 s)
{
  t_mat3	scale;

  scale = mat3();
  scale.m00 = s.x;
  scale.m11 = s.y;
  scale.m22 = s.z;
  multMat3(&scale, m);
}

void		scale4D(t_mat4 *m, t_vec3 s)
{
  t_mat4	scale;

  scale = mat4();
  scale.m00 = s.x;
  scale.m11 = s.y;
  scale.m22 = s.z;
  multMat4(&scale, m);
}
