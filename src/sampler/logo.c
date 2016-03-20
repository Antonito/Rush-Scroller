/*
** logo.c for scroll in /gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 12:39:48 2016 Ludovic Petrenko
** Last update Sun Mar 20 12:51:41 2016 Ludovic Petrenko
*/

#include "sampler.h"
#include "tools/common.h"

void			drawCircle_(t_bunny_pixelarray *pix,
				    t_circle *c, int n,
				    t_ivec2 *pos)
{
  static t_color	pal[510] = {0};
  int			i;
  t_vec2		tmp;
  t_ivec2		p[4];

  if (pal[0].full == 0)
    setRainbowPal(pal);
  i = -1;
  *pos = addiVec2(*pos, c[i].pos);
  while (++i < 36)
    {
      tmp = vec2(my_sin(10 * i), my_cos(10 * i));
      tmp = multVec2(tmp, 5000 / (n + 1));
      p[0] = addiVec2(to_ivec2(tmp), *pos);
      tekcircle(pix, p[0], pal + (c[i].color % 510), 3);
    }
}

void		moveCircles_(t_circle *c)
{
  int		i;
  t_ivec2	s;

  i = -1;
  while (++i < 99)
    c[i] = c[i + 1];
  s = ivec2((rand() % 2) ? -1 : 1, (rand() % 2) ? -1 : 1);
  c[i].pos = ivec2(rand() % 3 * s.x, rand() % 3 * s.y);
  c[i].color = (c[i - 1].color + 10) % 510;
}
