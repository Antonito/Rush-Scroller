/*
** main.c for scroll in /gfx_scroller/src/starfield
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 18:21:55 2016 Ludovic Petrenko
** Last update Sun Mar 20 15:35:30 2016 Antoine Baché
*/

#include <lapin.h>
#include <stdlib.h>
#include "starfield.h"
#include "tools/common.h"

t_bunny_response	starKey(t_bunny_event_state state,
				t_bunny_keysym key,
				t_data *data)
{
  return (eventKeys(state, key, data));
}

bool	isOffscreen(t_star *s)
{
  if (s->pos.x < 0 || s->pos.x >= WIN_X ||
      s->pos.y < 0 || s->pos.y >= WIN_Y)
    return (true);
  return (false);
}

t_bunny_response	starLoop(t_data *data)
{
  int			i;
  t_field		*field;

  i = 0;
  if (data->new && starfield(data))
    return (EXIT_ON_ERROR);
  clearColor(data->pix, 0xFF000000);
  field = data->data;
  while (i < 100)
    {
      drawStar(data->pix, field->star + i);
      moveStar(field->star + i);
      if (isOffscreen(field->star + i))
	genStar(field->star + i, 20.0);
      i++;
    }
  bunny_blit(&(data->win->buffer),
	     &(data->pix->clipable), 0);
  bunny_display(data->win);
  return (GO_ON);
}

int	starClose(t_data *data)
{
  t_field	*field;

  if (!data->new)
    {
      field = data->data;
      bunny_sound_stop(&field->music->sound);
      bunny_delete_sound(&field->music->sound);
      my_free(field->star);
      my_free(field);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int		starfield(t_data *data)
{
  t_field	*field;
  int		i;

  if (!(field = MALLOC(sizeof(t_field))) ||
      !(field->star = MALLOC(100 * sizeof(t_star))) ||
      !(field->music = bunny_load_music(STARFIELD_SONG)))
    return (1);
  data->data = field;
  startMusic(&field->music->sound);
  i = -1;
  while (++i < 100)
    genStar(field->star + i, 20.0);
  data->new = false;
  return (0);
}
