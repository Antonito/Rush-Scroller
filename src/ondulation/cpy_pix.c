/*
** cpy_pix.c for gfx_scroller in /gfx_scroller/src/ondulation
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 04:46:38 2016 Antoine Baché
** Last update Sat Mar 19 23:06:01 2016 Antoine Baché
*/

#include "ondulation.h"

void			fill_pix(t_ondulation		*ondulation,
				 double			ratio,
				 t_bunny_pixelarray	*pix,
				 int			height)
{
  t_color		*color_old;
  t_color		*color_new;
  int			i;
  int			j;

  i = j = -1;
  color_old = pix->pixels;
  color_new = ondulation->pix->pixels;
  while (++i < ondulation->width * height)
    {
      if (i >= ondulation->width * ((int) (ondulation->height * ratio / 2)) &&
	  i < ondulation->width *
	  ((int) (ondulation->height * (ratio + 2) / 2)))
	color_new[i].full = color_old[++j].full;
      else
	color_new[i].full = WHITE;
    }
}

int			cpy_pix(t_ondulation *ondulation, char *str, double ratio)
{
  int			height;

  if ((ondulation->flag = bunny_load_pixelarray(str)) == NULL)
    return (1);
  ondulation->width = ondulation->flag->clipable.buffer.width;
  ondulation->height = ondulation->flag->clipable.buffer.height;
  height = ondulation->flag->clipable.buffer.height * (1 + ratio);
  if ((ondulation->pix =
       bunny_new_pixelarray(ondulation->width, height)) == NULL)
    return (1);
  fill_pix(ondulation, ratio, ondulation->flag, height);
  return (0);
}
