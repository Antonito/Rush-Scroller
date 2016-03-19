/*
** cpy_pix.c for gfx_scroller in /gfx_scroller/src/ondulation
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 04:46:38 2016 Antoine Baché
** Last update Sat Mar 19 04:46:46 2016 Antoine Baché
*/

#include "ondulation.h"

void			fill_pix(t_data			*data,
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
  color_new = data->pix->pixels;
  while (++i < data->width * height)
    {
      if (i >= data->width * ((int) (data->height * ratio / 2)) &&
	  i < data->width * ((int) (data->height * (ratio + 2) / 2)))
	color_new[i].full = color_old[++j].full;
      else
	color_new[i].full = WHITE;
    }
}

int			cpy_pix(t_data *data, char *str, double ratio)
{
  int			height;

  if ((data->flag = bunny_load_pixelarray(str)) == NULL)
    return (1);
  data->width = data->flag->clipable.buffer.width;
  data->height = data->flag->clipable.buffer.height;
  height = data->flag->clipable.buffer.height * (1 + ratio);
  if ((data->win = bunny_start(data->width, height, false, "Rohan")) == NULL ||
      (data->pix = bunny_new_pixelarray(data->width, height)) == NULL)
    return (1);
  fill_pix(data, ratio, data->flag, height);
  return (0);
}
