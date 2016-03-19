/*
** vec_construct.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 02:20:48 2016 Ludovic Petrenko
** Last update Sat Mar 19 02:22:08 2016 Ludovic Petrenko
*/

#include "tools/transform.h"

t_vec2		vec2(double x, double y)
{
  t_vec2	new;

  new.x = x;
  new.y = y;
  return (new);
}

t_vec3		vec3(double x, double y, double z)
{
  t_vec3	new;

  new.x = x;
  new.y = y;
  new.z = z;
  return (new);
}

t_vec4		vec4(double x, double y, double z, double w)
{
  t_vec4	new;

  new.x = x;
  new.y = y;
  new.z = z;
  new.w = w;
  return (new);
}

t_ivec2		ivec2(int x, int y)
{
  t_ivec2	new;

  new.x = x;
  new.y = y;
  return (new);
}

t_ivec2		to_ivec2(t_vec2 v)
{
  t_ivec2	i;

  i.x = (int)v.x;
  i.y = (int)v.y;
  return (i);
}
