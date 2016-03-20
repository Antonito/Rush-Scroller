/*
** prog.c for gfx_scroller in /gfx_scroller/src/prog
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 05:05:23 2016 Antoine Baché
** Last update Sun Mar 20 10:29:24 2016 Antoine Baché
*/

#include "demo.h"
#include "progDegrad.h"
#include "tools/common.h"
#include "transition.h"

t_bunny_response	progDegradKey(t_bunny_event_state state,
				  t_bunny_keysym key,
				  t_data *data)
{
  return (eventKeys(state, key, data));
}

void			progDegradDraw(t_progDegrad *progDegrad,
				       t_bunny_pixelarray *pix)
{
  int			i;
  int			j;
  static int		k = 0;
  t_color		*color;

  i = 0;
  color = pix->pixels;
  while (i < (WIN_Y - 10))
    {
      j = -1;
      while (++j < WIN_X)
	color[i * WIN_X + j].full = color[(i + 1) * WIN_X + j].full =
	  color[(i + 2) * WIN_X + j].full = color[(i + 3) * WIN_X + j].full =
	  color[(i + 4) * WIN_X + j].full =
	  color[(i + 5) * WIN_X + j].full =
	  color[(i + 6) * WIN_X + j].full =
	  color[(i + 7) * WIN_X + j].full =
	  color[(i + 8) * WIN_X + j].full =
	  color[(i + 9) * WIN_X + j].full =
	  progDegrad->palette[(i + k) % 510].full;
      i += 5;
    }
  if (k == 510)
    k = 0;
  ++k;
}

t_bunny_response       	progDegradLoop(t_data *data)
{
  t_progDegrad		*progDegrad;

  if (data->new && progDegradMain(data))
    return (EXIT_ON_ERROR);
  progDegrad = data->data;
  progDegradDraw(progDegrad, data->pix);
  bunny_blit(&data->win->buffer, &data->pix->clipable, 0);
  bunny_display(data->win);
  return (GO_ON);
}

int			progDegradClose(t_data *data)
{
  t_progDegrad	       	*progDegrad;

  progDegrad = data->data;
  if (!data->new)
    {
      my_free(progDegrad->palette);
      my_free(progDegrad);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int			progDegradMain(t_data *data)
{
  t_progDegrad		*progDegrad;

  if (!(progDegrad = MALLOC(sizeof(t_progDegrad))) ||
      !(progDegrad->palette = MALLOC(sizeof(t_color) * 510)))
    return (1);
  setRainbowPal(progDegrad->palette);
  data->data = progDegrad;
  data->new = false;
  return (0);
}
