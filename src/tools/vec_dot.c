/*
** vec_dot.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 02:21:20 2016 Ludovic Petrenko
** Last update Sat Mar 19 19:00:10 2016 Ludovic Petrenko
*/

#include "tools/transform.h"

int	dotiVec2(t_ivec2 u, t_ivec2 v)
{
  return (u.x * v.x + u.y * v.y);
}

double	dotVec2(t_vec2 u, t_vec2 v)
{
  return (u.x * v.x + u.y * v.y);
}

double	dotVec3(t_vec3 u, t_vec3 v)
{
  return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double	dotVec4(t_vec4 u, t_vec4 v)
{
  return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec3		cross(t_vec3 u, t_vec3 v)
{
  t_vec3	w;

  w.x = u.y * v.z - u.z * v.y;
  w.y = u.z * v.x - u.x * v.z;
  w.z = u.x * v.y - u.y * v.x;
  return (w);
}
