/*
** add_vec.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 02:17:02 2016 Ludovic Petrenko
** Last update Sat Mar 19 03:37:01 2016 Ludovic Petrenko
*/

#include "tools/transform.h"

t_vec2		addVec2(t_vec2 u, t_vec2 v)
{
  u.x += v.x;
  u.y += v.y;
  return (u);
}

t_vec3		addVec3(t_vec3 u, t_vec3 v)
{
  u.x += v.x;
  u.y += v.y;
  u.z += v.z;
  return (u);
}

t_vec4		addVec4(t_vec4 u, t_vec4 v)
{
  u.x += v.x;
  u.y += v.y;
  u.z += v.z;
  return (u);
}

t_ivec2		addiVec2(t_ivec2 u, t_ivec2 v)
{
  u.x += v.x;
  u.y += v.y;
  return (u);
}
