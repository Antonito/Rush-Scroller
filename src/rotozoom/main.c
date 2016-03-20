/*
** main.c for scroll in /gfx_scroller/src/rotozoom
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 04:36:02 2016 Ludovic Petrenko
** Last update Sun Mar 20 16:44:31 2016 Antoine Baché
*/

#include <lapin.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "rotozoom.h"
#include "tools/common.h"

t_bunny_response	rotoKey(t_bunny_event_state state,
				t_bunny_keysym key,
				t_data *data)
{
  return (eventKeys(state, key, data));
}

t_bunny_response	rotoLoop(t_data *data)
{
  t_roto		*roto;
  time_t		timer;

  timer = time(NULL);
  if (data->new && rotozoom(data))
    return (EXIT_ON_ERROR);
  roto = data->data;
  repeatImage(roto->pict, roto->pix, roto->zoomSpeed);
  rotateImage(roto->pix, data->pix, roto->rotSpeed);
  changeZoomRotate(roto);
  bunny_blit(&(data->win->buffer),
	     &(data->pix->clipable), 0);
  bunny_display(data->win);
  return (timerChange(data, TIMER_DELAY, timer));
}

int		rotoClose(t_data *data)
{
  t_roto	*roto;

  if (!data->new)
    {
      roto = data->data;
      bunny_sound_stop(&roto->music->sound);
      bunny_delete_sound(&roto->music->sound);
      bunny_delete_clipable(&roto->pix->clipable);
      bunny_delete_clipable(&roto->pict->clipable);
      my_free(roto);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int	        rotozoom(t_data *data)
{
  t_roto	*roto;

  if (!(roto = MALLOC(sizeof(t_roto))))
    return (1);
  roto->size = (int)sqrt(POW2(WIN_X) + POW2(WIN_Y)) + 1;
  if (!(roto->pix = bunny_new_pixelarray(roto->size, roto->size)) ||
      !(roto->pict = bunny_load_pixelarray("assets/picture/fsm.jpg")) ||
      !(roto->music = bunny_load_music(ROTO_MUSIC)))
    return (1);
  startMusic(&roto->music->sound);
  roto->zoom = 1.0;
  roto->zoomSpeed = 1.0;
  roto->rot = 0.0;
  roto->rotSpeed = 1.0;
  data->data = roto;
  clearColor(data->pix, 0xFF000000);
  data->new = false;
  return (0);
}
