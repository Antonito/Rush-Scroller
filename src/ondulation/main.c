/*
** main.c for gfx_colle_fantasy2 in /gfx_colle_fantasy2/sujet1/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 13 19:00:36 2016 Antoine Baché
** Last update Sun Mar 20 14:47:39 2016 Antoine Baché
*/

#include "ondulation.h"
#include "demo.h"
#include "tools/common.h"

t_bunny_response	ondulationLoop(t_data *data)
{
  t_ondulation		*ondulation;

  if (data->new && ondulationMain(data))
    return (EXIT_ON_ERROR);
  ondulation = data->data;
  move_flag(ondulation);
  bunny_blit(&data->win->buffer, &ondulation->pix->clipable, 0);
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response	ondulationKey(t_bunny_event_state	state,
				      t_bunny_keysym		key,
				      t_data			*data)
{
  t_ondulation		*ondulation;

  ondulation = data->data;
  if (state == GO_UP && key == BKS_SPACE)
    ondulation->inv = 1 - ondulation->inv;
  if (state == GO_DOWN && key == BKS_LEFT && ondulation->wind < 100)
    ondulation->wind = ondulation->wind + 2;
  if (state == GO_DOWN && key == BKS_RIGHT && ondulation->wind > 26)
    ondulation->wind = ondulation->wind - 2;
  if (state == GO_DOWN && key == BKS_DOWN && ondulation->speed < 20)
    ondulation->speed = ondulation->speed + 1;
  if (state == GO_DOWN && key == BKS_UP && ondulation->speed > 4)
    ondulation->speed = ondulation->speed - 1;
  return (eventKeys(state, key, data));
}

int			ondulationClose(t_data *data)
{
  t_ondulation		*ondulation;

  ondulation = data->data;
  if (!data->new)
    {
      bunny_sound_stop(&ondulation->music->sound);
      bunny_delete_sound(&ondulation->music->sound);
      bunny_delete_clipable(&ondulation->pix->clipable);
      bunny_delete_clipable(&ondulation->flag->clipable);
      my_free(ondulation);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int	       	ondulationMain(t_data *data)
{
  t_ondulation	*ondulation;

  if ((ondulation = MALLOC(sizeof(t_ondulation))) == NULL ||
      cpy_pix(ondulation, FLAG_NAME, RATIO) ||
      !(ondulation->music = bunny_load_music(FLAG_MUSIC)))
    return (1);
  bunny_sound_volume(&ondulation->music->sound, 100);
  bunny_sound_loop(&ondulation->music->sound, true);
  bunny_sound_play(&ondulation->music->sound);
  ondulation->dir = 1;
  ondulation->var = 1;
  ondulation->wind = 60;
  ondulation->speed = 10;
  ondulation->inv = 0;
  data->data = ondulation;
  data->new = false;
  return (0);
}
