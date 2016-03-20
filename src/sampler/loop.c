/*
** loop.c for gfx_scroller in /gfx_scroller/src/sampler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar 20 05:25:36 2016 Antoine Baché
** Last update Sun Mar 20 12:08:31 2016 Antoine Baché
*/

#include "demo.h"
#include "sampler.h"
#include "tools/common.h"

void			samplerFreq(t_sampler *sampler, t_bunny_keysym key)
{
  if (key == BKS_UP)
    (sampler->freq > 1000) ?
      (sampler->freq = 1000) : (sampler->freq += 20);
  if (key == BKS_DOWN)
    (sampler->freq < 25) ?
      (sampler->freq = 25) : (sampler->freq -= 20);
}

t_bunny_response	samplerKey(t_bunny_event_state state,
				   t_bunny_keysym key,
				   t_data *data)
{
  t_sampler		*sampler;

  sampler = data->data;
  if (state == GO_DOWN)
    {
      samplerFreq(sampler, key);
    }
  return (eventKeys(state, key, data));
}

t_bunny_response	samplerLoop(t_data *data)
{
  t_sampler		*sampler;
  static int		loop = 0;

  if (data->new && samplerMain(data))
    return (EXIT_ON_ERROR);
  sampler = data->data;
  playMusic(sampler, loop);
  bunny_blit(&data->win->buffer, &data->pix->clipable, 0);
  bunny_display(data->win);
  usleep((int)sampler->duration[loop] * 1000);
  if (++loop == sampler->size)
    loop = 0;
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
