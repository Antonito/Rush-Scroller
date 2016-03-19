/*
** mult_vec.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 03:37:56 2016 Ludovic Petrenko
** Last update Sat Mar 19 03:49:35 2016 Ludovic Petrenko
*/

#include "tools/transform.h"

t_vec2	multVec2(t_vec2 v, double n)
{
  v.x *= n;
  v.y *= n;
  return (v);
}

t_vec3	multVec3(t_vec3 v, double n)
{
  v.x *= n;
  v.y *= n;
  v.z *= n;
  return (v);
}

t_vec4	multVec4(t_vec4 v, double n)
{
  v.x *= n;
  v.y *= n;
  v.z *= n;
  return (v);
}
