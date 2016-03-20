/*
** gen_star.c for scroll in /gfx_scroller/src/starfield
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 18:44:19 2016 Ludovic Petrenko
** Last update Sun Mar 20 20:37:37 2016 Antoine Baché
*/

#include <stdlib.h>
#include "tools/transform.h"
#include "starfield.h"

void		genStar(t_star *star, double len)
{
  double	l;
  t_ivec2	sign;
  int		r;

  l = 0;
  while (l < len)
    {
      sign = ivec2((rand() % 2) ? 1 : -1, (rand() % 2) ? 1 : -1);
      star->dir = ivec2(rand() % 100 * sign.x, rand() % 100 * sign.y);
      l = ivec2Len(star->dir);
    }
  r = rand() % 75;
  star->col.argb[0] = r + 180;
  star->col.argb[1] = r + 180;
  star->col.argb[2] = 255;
  star->col.argb[3] = 255;
  star->pos = addiVec2(ivec2(WIN_X / 2, WIN_Y / 2), star->dir);
}
