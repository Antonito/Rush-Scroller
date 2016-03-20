/*
** main.c for main in /home/arnaud_e/rendu/info/gfx_scroller/src/sprite
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Mar 19 18:30:57 2016 Arthur ARNAUD
** Last update Sun Mar 20 17:43:16 2016 Antoine Baché
*/

#include <math.h>
#include <time.h>
#include "demo.h"
#include "sprite.h"
#include "transition.h"
#include "tools/common.h"
#include "tools/transform.h"

t_bunny_response	spriteKey(t_bunny_event_state state,
				  t_bunny_keysym key,
				  t_data *data)
{
  return (eventKeys(state, key, data));
}

t_bunny_response	spriteLoop(t_data *data)
{
  t_prog		*prog;
  t_vec2		p;
  t_vec2		scale;
  static int		i = 0;
  time_t		timer;

  if (timer = time(NULL), data->new && spriteDisplay(data))
    return (EXIT_ON_ERROR);
  prog = data->data;
  if (prog->i++ > 0 && !(prog->i = 0))
    prog->index++;
  if (prog->index > 13)
    prog->index = 0;
  clearColor(prog->pix, (unsigned int)(0xFF000000 + POW3(256) * sin(i / 5) +
				       256 * sin(i / 5)));
  scale = vec2(10 + sin(i / 2.0) / 2.0, 10 + sin(i / 2.0) / 2.0);
  p = vec2((prog->pix->clipable.clip_width -
	    prog->spritePix[prog->index]->clipable.clip_width * scale.x) / 2,
	   (prog->pix->clipable.clip_height -
	    prog->spritePix[prog->index]->clipable.clip_height * scale.y) / 2);
  drawResized(prog->spritePix[prog->index], prog->pix, scale, to_ivec2(p));
  bunny_blit(&(data->win->buffer), &(prog->pix->clipable), 0);
  bunny_display(data->win);
  i++;
  return (timerChange(data, TIMER_DELAY, timer));
}

int		spriteClose(t_data *data)
{
  t_prog	*prog;
  int		i;

  if (!data->new)
    {
      i = -1;
      prog = data->data;
      bunny_sound_stop(&prog->music->sound);
      bunny_delete_sound(&prog->music->sound);
      bunny_delete_clipable(&prog->pix->clipable);
      while (prog->spritePix[++i] != NULL)
	bunny_delete_clipable(&prog->spritePix[i]->clipable);
      my_free(prog);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int		spriteDisplay(t_data *data)
{
  t_prog	*prog;

  if (!(prog = MALLOC(sizeof(t_prog))))
    return (1);
  data->data = prog;
  if (!(prog->pix = bunny_new_pixelarray(WIN_X, WIN_Y)))
    return (1);
  if (!(prog->spritePix = loadSprite("wolf")) ||
      !(prog->music = bunny_load_music(NYAN)))
    return (1);
  startMusic(&prog->music->sound);
  prog->i = 0;
  prog->index = 0;
  prog->pos.y = 10;
  prog->pos.x = 10;
  myBlit(prog->spritePix[prog->index], prog->pix, prog->pos);
  data->new = false;
  return (0);
}
