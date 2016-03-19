/*
** vec_length.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 02:21:53 2016 Ludovic Petrenko
** Last update Sat Mar 19 19:00:49 2016 Ludovic Petrenko
*/

#include <math.h>
#include "tools/common.h"
#include "tools/transform.h"

double	ivec2Len(t_ivec2 v)
{
  return (sqrt(POW2(v.x) + POW2(v.y)));
}

double	vec2Len(t_vec2 v)
{
  return (sqrt(POW2(v.x) + POW2(v.y)));
}

double	vec3Len(t_vec3 v)
{
  return (sqrt(POW2(v.x) + POW2(v.y) + POW2(v.z)));
}

double	vec4Len(t_vec4 v)
{
  return (sqrt(POW2(v.x) + POW2(v.y) + POW2(v.z)));
}
