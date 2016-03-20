/*
** clearPix.c for clearPix in /info/gfx_scroller/src/scroller
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar 20 04:10:39 2016 Arthur ARNAUD
** Last update Sun Mar 20 20:38:48 2016 Antoine Baché
*/

#include "scroller.h"
#include "tools/common.h"

void		clearPix(t_bunny_pixelarray *pix)
{
  t_color	*color;
  int		i;
  int		j;

  i = -1;
  while (++i < pix->HEIGHT)
    {
      j = -1;
      while (++j < pix->WIDTH)
	{
	  color = (t_color *)pix->pixels + i + j * pix->WIDTH;
	  color->argb[3] = 0;
	}
    }
}
