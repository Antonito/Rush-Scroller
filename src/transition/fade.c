/*
** fade.c for gfx_scroller in /gfx_scroller/src/transition
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 05:05:23 2016 Antoine Baché
** Last update Sun Mar 20 02:46:25 2016 Antoine Baché
*/

#include "demo.h"
#include "transition.h"

bool		isBlack(t_color *color)
{
  int		i;
  int		size;

  i = 0;
  size = WIN_X * WIN_Y;
  while (i < size)
    {
      if (color[i].full != 0)
	return (false);
      ++i;
    }
  return (true);
}

int		transitionFade(t_bunny_pixelarray *pix,
			       t_bunny_pixelarray *pix2,
			       t_bunny_window *win)
{
  int		i;
  int		size;
  t_color	*color;

  (void) pix2;
  color = pix->pixels;
  size = WIN_X * WIN_Y;
  while (!isBlack(color))
    {
      i = -1;
      while (++i < size)
	{
	  if (color[i].full >= 0x02020202)
	    color[i].full -= 0x02020202;
	  else
	    color[i].full = 0;
	}
      bunny_blit(&win->buffer, &pix->clipable, 0);
      bunny_display(win);
    }
  return (0);
}
