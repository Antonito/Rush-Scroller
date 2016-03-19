/*
** mult_vec_mat.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 02:18:31 2016 Ludovic Petrenko
** Last update Sat Mar 19 15:35:41 2016 Ludovic Petrenko
*/

#include "tools/transform.h"

t_vec2		multMatVec2(t_mat2 *m, t_vec2 v)
{
  t_vec2	res;
  t_mat2	t;

  t = *m;
  res.x = v.x * t.m00 + v.y * t.m01;
  res.y = v.x * t.m10 + v.y * t.m11;
  return (res);
}

t_vec3		multMatVec3(t_mat3 *m, t_vec3 v)
{
  t_vec3	res;
  t_mat3	t;

  t = *m;
  res.x = v.x * t.m00 + v.y * t.m01 + v.z * t.m02;
  res.y = v.x * t.m10 + v.y * t.m11 + v.z * t.m12;
  res.z = v.x * t.m20 + v.y * t.m21 + v.z * t.m22;
  return (res);
}

t_vec4		multMatVec4(t_mat4 *m, t_vec4 v)
{
  t_vec4	res;
  t_mat4	t;

  t = *m;
  res.x = v.x * t.m00 + v.y * t.m01 + v.z * t.m02 + v.w * t.m03;
  res.y = v.x * t.m10 + v.y * t.m11 + v.z * t.m12 + v.w * t.m13;
  res.z = v.x * t.m20 + v.y * t.m21 + v.z * t.m22 + v.w * t.m23;
  res.w = v.x * t.m20 + v.y * t.m21 + v.z * t.m22 + v.w * t.m33;
  return (res);
}
