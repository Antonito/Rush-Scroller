/*
** tekpixel.c for gfx_scroller in /gfx_scroller/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 18 23:30:38 2016 Antoine Baché
** Last update Sun Mar 20 00:24:11 2016 Ludovic Petrenko
*/

#include <lapin.h>

void	tekpixelTransp(t_bunny_pixelarray *pix,
		       t_bunny_position *pos, t_color *color, double transp)
{
  t_color	*tmp;

  if (pos[0].x < pix->clipable.clip_width &&
      pos[0].y < pix->clipable.clip_height && pos[0].x >= 0 && pos[0].y >= 0)
    {
      tmp = (t_color *)pix->pixels +
	pos[0].x + pos[0].y * pix->clipable.clip_width;
      tmp->argb[0] = (unsigned char)((tmp->argb[0] * transp) +
				     (color->argb[0] * (1 - transp)));
      tmp->argb[1] = (unsigned char)((tmp->argb[1] * transp) +
				     (color->argb[1] * (1 - transp)));
      tmp->argb[2] = (unsigned char)((tmp->argb[2] * transp) +
				     (color->argb[2] * (1 - transp)));
      tmp->argb[3] = (unsigned char)((tmp->argb[3] * transp) +
				     (color->argb[3] * (1 - transp)));
    }
}

unsigned int	getPixel(t_bunny_pixelarray *pix, t_bunny_position pos)
{
  unsigned int	*pixels;

  pixels = (unsigned int*)pix->pixels;
  if (pos.x >= 0 && pos.x < pix->clipable.clip_width &&
      pos.y >= 0 && pos.y < pix->clipable.clip_height)
    return (pixels[pos.x + pos.y * pix->clipable.clip_width]);
  return (0x00000000);
}

void		tekpixel(t_bunny_pixelarray *pix,
			 t_bunny_position *pos, t_color *c)
{
  t_color	*tmp;
  double	transp;
  t_color	color;

  transp = c->argb[3] / 255.0;
  color = *c;
  color.argb[3] = 255;
  if (pos[0].x < pix->clipable.clip_width &&
      pos[0].y < pix->clipable.clip_height && pos[0].x >= 0 && pos[0].y >= 0)
    {
      tmp = (t_color *)pix->pixels +
	pos[0].x + pos[0].y * pix->clipable.clip_width;
      tmp->argb[0] = (unsigned char)((color.argb[0] * transp) +
				     (tmp->argb[0] * (1 - transp)));
      tmp->argb[1] = (unsigned char)((color.argb[1] * transp) +
				     (tmp->argb[1] * (1 - transp)));
      tmp->argb[2] = (unsigned char)((color.argb[2] * transp) +
				     (tmp->argb[2] * (1 - transp)));
      tmp->argb[3] = (unsigned char)((color.argb[3] * transp) +
				     (tmp->argb[3] * (1 - transp)));
    }
}
