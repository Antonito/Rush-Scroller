/*
** translate.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 02:20:36 2016 Ludovic Petrenko
** Last update Sun Mar 20 22:37:49 2016 Antoine Baché
*/

#include "tools/transform.h"

void		translate3(t_mat3 *mat, t_vec2 t)
{
  t_mat3	n;

  n = mat3();
  n.m02 += t.x;
  n.m12 += t.y;
  multMat3(&n, mat);
}

void		translate4(t_mat4 *mat, t_vec3 t)
{
  t_mat4	n;

  n = mat4();
  n.m03 += t.x;
  n.m13 += t.y;
  n.m23 += t.z;
  multMat4(&n, mat);
}
