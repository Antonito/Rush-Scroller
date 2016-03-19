/*
** translate.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 02:20:36 2016 Ludovic Petrenko
** Last update Sat Mar 19 14:50:01 2016 Ludovic Petrenko
*/

#include "tools/transform.h"

void	translate(t_mat4 *mat, t_vec3 t)
{
  mat->m03 += t.x;
  mat->m13 += t.y;
  mat->m23 += t.z;
}
