/*
** tunnel.c for scroll in /home/petren_l/rendu/tek1/semestre_02/gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 00:36:41 2016 Ludovic Petrenko
** Last update Sun Mar 20 01:38:08 2016 Ludovic Petrenko
*/

#include <lapin.h>
#include "tunnel.h"

void		setPal(t_color *pal)
{
  int		i;
  t_color	rgb;

  i = -1;
  rgb.full = 0xFF0000FF
  while (++i < 510)
    {
      pal[i] = rgb;
      if (i < 85)
	rgb.argb[1] += 3;
      else if (i < 170)
	rgb.argb[0] -= 3;
      else if (i < 255)
	rgb.argb[2] += 3;
      else if (i < 340)
	rgb.argb[1] -= 3;
      else if (i < 425)
	rgb.argb[0] += 3;
      else
	rgb.argb[2] -= 3;
    }
}

void			drawCircle(t_bunny_pixelarray *pix, t_circle *c, int n, t_ivec2 *pos)
{
  static t_color	pal[510] = {0};
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
      tekpixel(pix, pal[c->color % 510], addiVec2(t_ivec2(tmp), *pos));
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
  c[i].color = c[i - 1].color + 1;
}
