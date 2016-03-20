/*
** main.c for main in /home/arnaud_e/rendu/info/gfx_scroller/src/sprite
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Mar 19 18:30:57 2016 Arthur ARNAUD
** Last update Sun Mar 20 21:35:32 2016 Antoine Baché
*/

#include <time.h>
#include "demo.h"
#include "scroller.h"
#include "tools/common.h"

t_bunny_response	scrollerKey(t_bunny_event_state state,
				t_bunny_keysym key,
				t_data *data)
{
  return (eventKeys(state, key, data));
}

void			blitAllPix(t_prog *prog)
{
  myBlit(prog->bigSky, prog->pix, subiVec2
  	 (prog->sky_pos, ivec2(prog->bigSky->clipable.clip_width, 0)));
  myBlit(prog->bigSky, prog->pix, prog->sky_pos);
  myBlit(prog->bigMountain, prog->pix, subiVec2
  	 (prog->mountain_pos,
	  ivec2(prog->bigMountain->clipable.clip_width, 0)));
  myBlit(prog->bigMountain, prog->pix, prog->mountain_pos);
  myBlit(prog->bigGrass, prog->pix, subiVec2
  	 (prog->grass_pos, ivec2(prog->bigGrass->clipable.clip_width, 0)));
  myBlit(prog->bigGrass, prog->pix, prog->grass_pos);
  myBlit(prog->bigBunny, prog->pix,
	 subiVec2(prog->bunny_pos ,
		  ivec2(0, (int)(ABS(sin(prog->bunny_pos.x / 10.0)) * 100))));
}

t_bunny_response	scrollerLoop(t_data *data)
{
  t_prog		*prog;
  time_t		timer;

  timer = time(NULL);
  if (data->new && scrollerDisplay(data))
    return (EXIT_ON_ERROR);
  prog = data->data;
  clearColor(prog->pix, 0xFFE68A00);
  if (prog->sky_pos.x++ > prog->sky->clipable.clip_width)
    prog->sky_pos.x = 0;
  if ((prog->mountain_pos.x > prog->mountain->clipable.clip_width) ||
      !(prog->mountain_pos.x += 2))
    prog->mountain_pos.x = 0;
  if ((prog->grass_pos.x > prog->grass->clipable.clip_width) ||
      !(prog->grass_pos.x += 4))
    prog->grass_pos.x = 0;
  if (prog->bunny_pos.x > prog->pix->WIDTH || !(prog->bunny_pos.x += 3))
    prog->bunny_pos.x = 0;
  blitAllPix(prog);
  bunny_blit(&(data->win->buffer),
	     &(prog->pix->clipable), 0);
  bunny_display(data->win);
  return (timerChange(data, TIMER_DELAY, timer));
}

int		scrollerClose(t_data *data)
{
  t_prog	*prog;

  prog = data->data;
  if (!data->new)
    {
      bunny_sound_stop(&prog->music->sound);
      bunny_delete_sound(&prog->music->sound);
      bunny_delete_clipable(&prog->pix->clipable);
      bunny_delete_clipable(&prog->sky->clipable);
      bunny_delete_clipable(&prog->mountain->clipable);
      bunny_delete_clipable(&prog->grass->clipable);
      bunny_delete_clipable(&prog->bigSky->clipable);
      bunny_delete_clipable(&prog->bigGrass->clipable);
      bunny_delete_clipable(&prog->bigMountain->clipable);
      bunny_delete_clipable(&prog->bigBunny->clipable);
      bunny_delete_clipable(&prog->bunny->clipable);
      my_free(prog);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int		scrollerDisplay(t_data *data)
{
  t_prog	*prog;

  if (!(prog = MALLOC(sizeof(t_prog))))
    return (1);
  data->data = prog;
  if (!(prog->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) ||
      !(prog->grass = bunny_load_pixelarray(HERBE4)) ||
      !(prog->sky = bunny_load_pixelarray(NUAGE3)) ||
      !(prog->mountain = bunny_load_pixelarray(MONTAGNES)) ||
      !(prog->bunny = bunny_load_pixelarray(BUNNY)) ||
      !(prog->bigSky = bunny_new_pixelarray
	(prog->sky->WIDTH * 2, prog->sky->HEIGHT * 2)) ||
      !(prog->bigMountain = bunny_new_pixelarray
	(prog->mountain->WIDTH * 2, prog->mountain->HEIGHT * 2)) ||
      !(prog->bigGrass = bunny_new_pixelarray
	(prog->grass->WIDTH * 3, prog->grass->HEIGHT * 3)) ||
      !(prog->bigBunny = bunny_new_pixelarray
	(prog->bunny->WIDTH * 2, prog->bunny->HEIGHT * 2)) ||
      !(prog->music = bunny_load_music(MUSIC_BUNNY)))
    return (1);
  startMusic(&prog->music->sound);
  clearPix(prog->bigBunny);
  setProg(prog);
  data->new = false;
  return (0);
}
