/*
** damier.c for gfx_scroller in /gfx_scroller/src/damier
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 05:05:23 2016 Antoine Baché
** Last update Sun Mar 20 16:44:15 2016 Antoine Baché
*/

#include "demo.h"
#include "damier.h"
#include "tools/common.h"
#include "transition.h"

t_bunny_response	damierKey(t_bunny_event_state state,
				  t_bunny_keysym key,
				  t_data *data)
{
  return (eventKeys(state, key, data));
}

t_bunny_response       	damierLoop(t_data *data)
{
  time_t		timer;

  timer = time(NULL);
  if (data->new && damierMain(data))
    return (EXIT_ON_ERROR);
  bunny_blit(&data->win->buffer, &data->pix->clipable, 0);
  bunny_display(data->win);
  return (timerChange(data, TIMER_DELAY, timer));
}

int			damierClose(t_data *data)
{
  t_damier	       	*damier;

  if (!data->new)
    {
      damier = data->data;
      bunny_sound_stop(&damier->music->sound);
      bunny_delete_sound(&damier->music->sound);
      my_free(damier);
    }
  data->data = NULL;
  data->new = true;
  transition(data, FADE, NULL);
  return (0);
}

void			damierMask(t_bunny_pixelarray *pix,
				   t_bunny_pixelarray *mask,
				   t_bunny_pixelarray *src)
{
  int			i;
  int			j;
  int			tmp;
  t_color		*colorPix;
  t_color		*colorMask;
  t_color		*colorSrc;

  i = -1;
  colorPix = pix->pixels;
  colorMask = mask->pixels;
  colorSrc = src->pixels;
  while (++i < WIN_Y && (j = -1))
    while (++j < WIN_X)
      {
	tmp = i * WIN_X + j;
	colorPix[tmp].argb[0] = colorMask[tmp].argb[0] ^ colorSrc[tmp].argb[0];
	colorPix[tmp].argb[1] = colorMask[tmp].argb[0] ^ colorSrc[tmp].argb[0];
	colorPix[tmp].argb[2] = colorMask[tmp].argb[0] ^ colorSrc[tmp].argb[0];
	colorPix[tmp].argb[3] = colorMask[tmp].argb[0] ^ colorSrc[tmp].argb[0];
      }
}

int			damierMain(t_data *data)
{
  t_damier		*damier;

  if (!(damier = MALLOC(sizeof(t_damier))) ||
      !(damier->mask = bunny_load_pixelarray(MASK_SRC)) ||
      !(damier->src = bunny_load_pixelarray(DAMIER_SRC)) ||
      !(damier->music = bunny_load_music(DAMIER_SONG)))
    return (1);
  startMusic(&damier->music->sound);
  damierMask(data->pix, damier->mask, damier->src);
  bunny_delete_clipable(&damier->src->clipable);
  bunny_delete_clipable(&damier->mask->clipable);
  data->data = damier;
  data->new = false;
  return (0);
}
