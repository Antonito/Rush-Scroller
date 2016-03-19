/*
** div_vec.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 03:49:59 2016 Ludovic Petrenko
** Last update Sat Mar 19 03:50:33 2016 Ludovic Petrenko
*/

#include "tools/transform.h"

t_vec2	divVec2(t_vec2 v, double n)
{
  v.x /= n;
  v.y /= n;
  return (v);
}

t_vec3	divVec3(t_vec3 v, double n)
{
  v.x /= n;
  v.y /= n;
  v.z /= n;
  return (v);
}

t_vec4	divVec4(t_vec4 v, double n)
{
  v.x /= n;
  v.y /= n;
  v.z /= n;
  return (v);
}
