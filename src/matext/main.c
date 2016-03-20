/*
** main.c for scroll in /home/petren_l/rendu/tek1/semestre_02/gfx_scroller/src
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 12:56:55 2016 Ludovic Petrenko
** Last update Sun Mar 20 16:43:26 2016 Antoine Baché
*/

#include <time.h>
#include <lapin.h>
#include <stdlib.h>
#include "matext.h"
#include "tools/common.h"
#include "tools/font.h"

t_bunny_response	matextKey(t_bunny_event_state state,
				t_bunny_keysym key,
				t_data *data)
{
  return (eventKeys(state, key, data));
}

void	drawRainbow(t_bunny_pixelarray *pix, t_matext *m)
{
  int			i;
  int			j;
  static int		k = 0;
  t_color		*color;

  i = 0;
  color = pix->pixels;
  while (i < (WIN_Y - 9))
    {
      j = -1;
      while (++j < WIN_X)
	color[i * WIN_X + j].full = color[(i + 1) * WIN_X + j].full =
	  color[(i + 2) * WIN_X + j].full = color[(i + 3) * WIN_X + j].full =
	  color[(i + 4) * WIN_X + j].full = color[(i + 5) * WIN_X + j].full =
	  color[(i + 6) * WIN_X + j].full = color[(i + 7) * WIN_X + j].full =
	  color[(i + 8) * WIN_X + j].full = color[(i + 9) * WIN_X + j].full =
	  m->pal[(i + k) % 510];
      i += 5;
    }
  if (k == 510)
    k = 0;
  ++k;
}

t_bunny_response	matextLoop(t_data *data)
{
  t_matext		*m;
  time_t		timer;

  timer = time(NULL);
  if (data->new && matext(data))
    return (EXIT_ON_ERROR);
  m = data->data;
  drawRainbow(data->pix, m);
  drawMatext(data->pix, m);
  moveMatext(m);
  bunny_blit(&(data->win->buffer),
	     &(data->pix->clipable), 0);
  bunny_display(data->win);
  return (timerChange(data, TIMER_DELAY, timer));
}

int	matextClose(t_data *data)
{
  t_matext	*matext;

  if (!data->new)
    {
      matext = data->data;
      my_free(matext);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int			matext(t_data *data)
{
  t_matext		*matext;
  t_bunny_pixelarray	*tmp;

  if (!(matext = MALLOC(sizeof(t_matext))))
    return (1);
  if (!(tmp = printText("tu veux mon zizi?", "font2")))
    return (1);
  if (tmp->clipable.clip_width < WIN_X / 3)
    {
      if (!(matext->img = bunny_new_pixelarray(tmp->clipable.clip_width * 2,
					       tmp->clipable.clip_height * 2)))
	return (1);
      drawResized(tmp, matext->img, vec2(2, 2), ivec2(0, 0));
      bunny_delete_clipable(&tmp->clipable);
    }
  else
    matext->img = tmp;
  matext->rot = vec3(0, 0, 0);
  matext->decal = ivec2(matext->img->clipable.clip_width / 2,
			matext->img->clipable.clip_height / 2);
  setRainbowPal((t_color *)matext->pal);
  data->data = matext;
  data->new = false;
  return (0);
}
