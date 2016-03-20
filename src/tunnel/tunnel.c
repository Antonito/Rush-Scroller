/*
** tunnel.c for scroll in /home/petren_l/rendu/tek1/semestre_02/gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 00:36:41 2016 Ludovic Petrenko
** Last update Sun Mar 20 00:59:56 2016 Ludovic Petrenko
*/

#include <lapin.h>
#include "tunnel.h"

void			drawCircle(t_bunny_pixelarray *pix, t_circle *c, int n, t_ivec2 *pos)
{
  static t_color	pal[512] = {0};
  int			i;
  t_vec2		tmp;

  if (pal[0] == 0)
    setPal(pal);
  i = -1;
  *pos += c->pos;
  while (++i < 36)
    {
      tmp = vec2(my_sin(10 * i), my_cos(10 * i));
      tmp = multVec2(tmp, 1500 / (n + 1));
      tekpixel(pix, pal[c->color], addiVec2(t_ivec2(tmp), *pos));
    }
}

void		moveCircles(t_circle *c)
{
  int		i;
  t_ivec2	s;

  i = -1;
  while (++i < 99)
    c[i] = c[i + 1];
  s = ivec2((rand() % 2) ? -1 : 1, (rand() % 2) ? -1 : 1);
  c[i].pos = ivec2(rand() % 3 * s.x, rand() % 3 * s.y);
}
