/*
** interpolate.c for scroll in /gfx_scroller/src/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 03:54:34 2016 Ludovic Petrenko
** Last update Sat Mar 19 13:13:33 2016 Antoine Baché
*/

#include <lapin.h>
#include "tools/transform.h"

double		interpolate3f(t_vec2 corners[3], t_vec2 pos, double val[3])
{
  double	a[4];

  a[0] = surfaceTriangle(pos, corners[1], corners[2]);
  a[1] = surfaceTriangle(corners[0], pos, corners[2]);
  a[2] = surfaceTriangle(corners[0], corners[1], pos);
  a[3] = (a[0] * val[0] + a[1] * val[1] + a[2] * val[2]) /
    (a[0] + a[1] + a[2]);
  return (a[3]);
}

t_vec2	interpolate3Vec2(t_vec2 *corners, t_vec2 pos)
{

}
