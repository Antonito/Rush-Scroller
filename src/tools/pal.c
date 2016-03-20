/*
** pal.c for gfx_scroller in /gfx_scroller/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar 20 06:35:57 2016 Antoine Baché
** Last update Sun Mar 20 06:38:36 2016 Antoine Baché
*/

#include <lapin.h>

void	setRainbowPal(t_color *pal)
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
