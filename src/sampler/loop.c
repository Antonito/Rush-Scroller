/*
** loop.c for gfx_scroller in /gfx_scroller/src/sampler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar 20 05:25:36 2016 Antoine Baché
** Last update Sun Mar 20 11:38:22 2016 Antoine Baché
*/

#include "demo.h"
#include "sampler.h"
#include "tools/common.h"

t_bunny_response	samplerKey(t_bunny_event_state state,
				   t_bunny_keysym key,
				   t_data *data)
{
  t_sampler		*sampler;

  sampler = data->data;
  if (state == GO_DOWN)
    {
      if (key == BKS_UP)
	(sampler->freq > 1000) ? (sampler->freq = 1000) : (++sampler->freq);
      if (key == BKS_DOWN)
	(sampler->freq < 25) ? (sampler->freq = 25) : (--sampler->freq);
    }
  return (eventKeys(state, key, data));
}

t_bunny_response	samplerLoop(t_data *data)
{
  if (data->new && samplerMain(data))
    return (EXIT_ON_ERROR);
  bunny_blit(&data->win->buffer, &data->pix->clipable, 0);
  bunny_display(data->win);
  return (GO_ON);
}

int			samplerClose(t_data *data)
{
  t_sampler		*sampler;

  sampler = data->data;
  if (!data->new)
    {
      my_free(sampler->duration);
      my_free(sampler->frequency);
      bunny_delete_sound(&sampler->music->sound);
      my_free(sampler);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}
