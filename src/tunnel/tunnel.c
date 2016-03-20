/*
** tunnel.c for scroll in /home/petren_l/rendu/tek1/semestre_02/gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 00:36:41 2016 Ludovic Petrenko
** Last update Sun Mar 20 03:30:46 2016 Ludovic Petrenko
*/

#include <lapin.h>
#include "tunnel.h"
#include "tools/common.h"

void		setPal(t_color *pal)
{
  int		i;
  t_color	rgb;

  i = -1;
  rgb.full = 0xFF0000FF;
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
  t_ivec2		p;

  if (pal[0].full == 0)
    setPal(pal);
  i = -1;
  *pos = addiVec2(*pos, c[n].pos);
  while (++i < 36)
    {
      tmp = vec2(my_sin(10 * i), my_cos(10 * i));
      tmp = multVec2(tmp, 1500 / (n + 1));
      p = addiVec2(to_ivec2(tmp), *pos);
      tekcircle(pix, p, pal + (c[n].color % 510), 19 / (n + 1) + 1);
    }
}

void			moveCircles(t_circle *c)
{
  int			i;
  t_ivec2		s;
  static t_ivec2	new;
  static int		p = 0;

  i = -1;
  while (++i < 99)
    c[i] = c[i + 1];
  if (p == 3)
    p = -1;
  s = ivec2((rand() % 2) ? -1 : 1, (rand() % 2) ? -1 : 1);
  new = addiVec2(new, ivec2((rand() % 2) * s.x, (rand() % 2) * s.y));
  new.x = (new.x > 20) ? 19 : new.x;
  new.x = (new.x < -20) ? -19 : new.x;
  new.y = (new.y > 20) ? 19 : new.y;
  new.y = (new.y < -20) ? -19 : new.y;
  c[i].pos = new;
  c[i].color = (c[i - 1].color + 10) % 510;
  p++;
}
