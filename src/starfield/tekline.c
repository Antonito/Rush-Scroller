/*
** tekline.c for lightning in /home/petren_l/rendu/lightning_2020
**
** Made by ludovic petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Mon Nov  9 14:30:27 2015 ludovic petrenko
** Last update Sat Mar 19 21:08:38 2016 Ludovic Petrenko
*/

#include "starfield.h"
#include "tools/common.h"

void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color color)
{
  float			a;
  float			b;
  t_bunny_position	p;

  p = pos[0];
  a = 0;
  if (pos[1].x - pos[0].x != 0 && pos[1].y - pos[0].y != 0)
    a = (float)(pos[1].y - pos[0].y) / (float)(pos[1].x - pos[0].x);
  b = pos[0].y - a * pos[0].x;
  tekpixel(pix, pos, &color);
  if (a <= 1 && a >= -1 && pos[1].x != pos[0].x)
    while (p.x != pos[1].x)
      {
	p.x += (p.x > pos[1].x) ? -1 : 1;
	p.y = ROUND(int, a * p.x + b);
	tekpixel(pix, &p, &color);
      }
  else
    while (p.y != pos[1].y)
      {
	p.y += (p.y > pos[1].y) ? -1 : 1;
	if (pos[1].x - pos[0].x != 0)
	  p.x = ROUND(int, (p.y - b)/ a);
	tekpixel(pix, &p, &color);
      }
}
