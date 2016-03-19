/*
** cast.c for scroll in /home/petren_l/rendu/tek1/semestre_02/gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 15:24:14 2016 Ludovic Petrenko
** Last update Sat Mar 19 15:30:10 2016 Ludovic Petrenko
*/

#include "tools/transform.h"

t_ivec2		to_ivec2(t_vec2 v)
{
  t_ivec2	c;

  c.x = (int)v.x;
  c.y = (int)v.y;
  return (c);
}

t_vec2		to_vec2(t_ivec2 v)
{
  t_vec2	c;

  c.x = v.x;
  c.y = v.y;
  return (c);
}

t_vec4		to_vec4(t_vec3 v, double w)
{
  t_vec4	c;

  c.x = v.x;
  c.y = v.y;
  c.z = v.z;
  c.w = w;
  return (c);
}

t_mat4		to_mat4(t_mat3 m)
{
  t_mat4	n;

  n = mat4();
  n.m00 = m.m00;
  n.m01 = m.m01;
  n.m02 = m.m02;
  n.m10 = m.m10;
  n.m11 = m.m11;
  n.m12 = m.m12;
  n.m20 = m.m20;
  n.m21 = m.m21;
  n.m22 = m.m22;
  return (n);
}
