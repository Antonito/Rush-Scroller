/*
** transition.c for gfx_scroller in /gfx_scroller/src/transition
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 05:05:23 2016 Antoine Baché
** Last update Sun Mar 20 01:43:06 2016 Antoine Baché
*/

#include "demo.h"
#include "transition.h"
#include "tools/common.h"

t_bunny_response	transitionKey(t_bunny_event_state state,
				  t_bunny_keysym key,
				  t_data *data)
{
  return (eventKeys(state, key, data));
}

t_bunny_response       	transitionLoop(t_data *data)
{
  t_transition		*transition;

  if (data->new && transitionMain(data))
    return (EXIT_ON_ERROR);
  transition = data->data;
  bunny_blit(&data->win->buffer, &transition->pix->clipable, 0);
  bunny_display(data->win);
  return (GO_ON);
}

int			transitionClose(t_data *data)
{
  t_transition	       	*transition;

  transition = data->data;
  if (!data->new)
    {
      bunny_delete_clipable(&transition->pix->clipable);
      my_free(transition);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

void			transitionMask(t_bunny_pixelarray *pix,
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

int			transitionMain(t_data *data)
{
  t_transition		*transition;

  if (!(transition = MALLOC(sizeof(t_transition))) ||
      !(transition->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) ||
      !(transition->mask = bunny_load_pixelarray(MASK_SRC)) ||
      !(transition->src = bunny_load_pixelarray(TRANSITION_SRC)))
    return (1);
  transitionMask(transition->pix, transition->mask, transition->src);
  bunny_delete_clipable(&transition->src->clipable);
  bunny_delete_clipable(&transition->mask->clipable);
  data->data = transition;
  data->new = false;
  return (0);
}
