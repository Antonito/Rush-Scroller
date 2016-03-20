/*
** main.c for gfx_scroller in /gfx_scroller/src/fire
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 02:06:05 2016 Antoine Baché
** Last update Sun Mar 20 23:19:27 2016 Antoine Baché
*/

#include "demo.h"
#include "fire.h"
#include "transition.h"
#include "tools/common.h"

t_bunny_response	fireKey(t_bunny_event_state state,
				t_bunny_keysym key,
				t_data *data)
{
  t_prog		*prog;

  prog = data->data;
  if (state == GO_DOWN && key != BKS_ESCAPE)
    go_down_key(key, prog);
  else if (state == GO_UP && key != BKS_ESCAPE)
    go_up_key(key, prog);
  else if (key == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ON_SUCCESS);
  return (eventKeys(state, key, data));
}

t_bunny_response	fireLoop(t_data *data)
{
  t_prog		*prog;
  time_t		timer;

  timer = time(NULL);
  if (data->new && flame(data))
    return (EXIT_ON_ERROR);
  prog = data->data;
  if (prog->mod[0] && prog->mod[3] < 19)
    prog->mod[3] += 1;
  else if (prog->mod[1] && prog->mod[3] > 0)
    prog->mod[3] -= 1;
  bunny_sound_volume(&prog->music->sound, prog->mod[3] * 4 + 20);
  random_lines(prog->colors);
  fire_calculator(prog->colors, prog->mod[3]);
  display_fire(prog->pix, prog->colors, prog->palette);
  bunny_blit(&(data->win->buffer),
	     &(prog->pix->clipable), 0);
  bunny_display(data->win);
  return (timerChange(data, TIMER_DELAY, timer));
}

void	set_to_black(short *colors)
{
  int	i;
  int	size;

  i = -1;
  size = WIN_X * (WIN_Y + 2);
  while (++i < size)
    colors[i] = 0;
}

int		fireClose(t_data *data)
{
  t_prog	*prog;

  if (!data->new)
    {
      prog = data->data;
      bunny_delete_sound(&prog->music->sound);
      bunny_delete_clipable(&prog->pix->clipable);
      my_free(prog->colors);
      my_free(prog);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int		flame(t_data *data)
{
  t_prog	*prog;

  if (!(prog = MALLOC(sizeof(t_prog))) ||
      !(prog->colors = MALLOC(sizeof(short) * (WIN_X * (WIN_Y + 2)))))
    return (1);
  data->data = prog;
  palette_generator(prog->palette);
  prog->mod[0] = 0;
  prog->mod[1] = 0;
  prog->mod[3] = 14;
  set_to_black(prog->colors);
  if (!(prog->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) ||
      !(prog->music = bunny_load_music("assets/sounds/fire.ogg")))
    return (1);
  load_music(prog->music);
  data->new = false;
  return (0);
}
