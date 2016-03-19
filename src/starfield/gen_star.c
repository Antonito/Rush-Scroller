/*
** gen_star.c for scroll in /gfx_scroller/src/starfield
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 18:44:19 2016 Ludovic Petrenko
** Last update Sat Mar 19 19:03:50 2016 Ludovic Petrenko
*/

#include <stdlib.h>
#include "tools/transform.h"

void	gen_star(t_star *star, double len)
{
  double	l;

  l = 0;
  star.pos = ivec2(WIN_X / 2, WIN_Y / 2);
  star.next = NULL;
  while (l < len)
    {
      star.dir = ivec2(rand() % 100, rand() % 100);
      l = ivec2Len(star.dir);
    }
}
