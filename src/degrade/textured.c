/*
** prog.c for gfx_scroller in /gfx_scroller/src/prog
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 05:05:23 2016 Antoine Baché
** Last update Sun Mar 20 15:22:23 2016 Antoine Baché
*/

#include "demo.h"
#include "texturedDegrad.h"
#include "tools/common.h"
#include "transition.h"

t_bunny_response	texturedDegradKey(t_bunny_event_state state,
					  t_bunny_keysym key,
					  t_data *data)
{
  return (eventKeys(state, key, data));
}

void			texturedDegradDraw(t_bunny_pixelarray *img,
					   t_bunny_pixelarray *pix)
{
  int			i;
  int			j;
  t_color		*color;
  t_ivec2		pos;

  i = -1;
  color = img->pixels;
  while (++i < WIN_Y)
    {
      j = -1;
      while (++j < WIN_X)
	{
	  pos.x = j;
	  pos.y = i;
	  if (color[i * WIN_X + j].argb[3] - (i >> 2) > 30)
	    color[i * WIN_X + j].argb[3] -= (i >> 2);
	  else
	    color[i * WIN_X + j].argb[3] = 30;
	  tekpixel(img, &pos, &color[i * WIN_X + j]);
	}
    }
  clearColor(pix, 0x0100AE);
  myBlit(img, pix, ivec2(0, 0));
}

t_bunny_response	       	texturedDegradLoop(t_data *data)
{
  if (data->new && texturedDegradMain(data))
    return (EXIT_ON_ERROR);
  bunny_display(data->win);
  return (GO_ON);
}

int				texturedDegradClose(t_data *data)
{
  t_bunny_music			*music;

  if (!data->new)
    {
      music = data->data;
      bunny_sound_stop(&music->sound);
      bunny_delete_sound(&music->sound);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int				texturedDegradMain(t_data *data)
{
  t_bunny_pixelarray		*img;
  t_bunny_music			*music;

  if (!(img = bunny_load_pixelarray(TEXTURE_SRC)) ||
      !(music = bunny_load_music(TEXTURE_SONG)))
    return (1);
  data->new = false;
  data->data = music;
  startMusic(&music->sound);
  texturedDegradDraw(img, data->pix);
  bunny_blit(&data->win->buffer, &data->pix->clipable, 0);
  bunny_delete_clipable(&img->clipable);
  return (0);
}
