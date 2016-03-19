/*
** vec_normalize.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 02:23:31 2016 Ludovic Petrenko
** Last update Sat Mar 19 14:50:03 2016 Ludovic Petrenko
*/

#include "tools/transform.h"

t_vec2		vec2Normalize(t_vec2 v)
{
  double	len;

  len = vec2Len(v);
  if (v == 0.0)
    return (vec2(0, 0));
  v.x /= len;
  v.y /= len;
  return (v);
}

t_vec3		vec3Normalize(t_vec3 v)
{
  double	len;

  len = vec3Len(v);
  if (v == 0.0)
    return (vec3(0, 0));
  v.x /= len;
  v.y /= len;
  v.z /= len;
  return (v);
}

t_vec4		vec4Normalize(t_vec4 v)
{
  double	len;

  len = vec4Len(v);
  if (v == 0.0)
    return (vec4(0, 0, 0, v.w));
  v.x /= len;
  v.y /= len;
  v.z /= len;
  return (v);
}
