/*
** main.c for scroll in /home/petren_l/rendu/tek1/semestre_02/gfx_scroller/src
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 03:44:45 2016 Ludovic Petrenko
** Last update Sun Mar 20 16:42:11 2016 Antoine Baché
*/

#include <time.h>
#include "plasma.h"
#include "tools/common.h"

t_bunny_response	plasmaKey(t_bunny_event_state state,
				 t_bunny_keysym keysym,
				 t_data *data)
{
  t_plasma		*plasma;

  plasma = data->data;
  if (state == GO_DOWN && keysym == BKS_UP)
    plasma->speed += (plasma->speed != 0.1 ? 0.1 : 0.2);
  if (state == GO_DOWN && keysym == BKS_DOWN)
    plasma->speed -= (plasma->speed != -0.1 ? 0.1 : 0.2);
  if (state == GO_DOWN && keysym == BKS_O)
    plasma->size += (plasma->size != 0.1 ? 0.1 : 0.2);
  if (state == GO_DOWN && keysym == BKS_L)
    plasma->size -= (plasma->size != -0.1 ? 0.1 : 0.2);
  if (state == GO_DOWN && keysym == BKS_I)
    plasma->coeff += (plasma->coeff != 0.1 ? 0.1 : 0.2);
  if (state == GO_DOWN && keysym == BKS_K)
    plasma->coeff -= (plasma->coeff != -0.1 ? 0.1 : 0.2);
  return (eventKeys(state, keysym, data));
}

t_bunny_response	plasmaLoop(t_data *data)
{
  t_plasma		*plasma;
  time_t		timer;

  timer = time(NULL);
  if (data->new && plasmaMain(data))
    return (EXIT_ON_ERROR);
  plasma = data->data;
  if (plasma->origin < 127)
    plasma->origin += plasma->speed;
  else
    plasma->origin = 0;
  new_frame(plasma);
  bunny_blit(&data->win->buffer, &plasma->pix->clipable, NULL);
  bunny_display(data->win);
  if (timerChange(data, TIMER_DELAY, timer) != GO_ON)
    return (SWITCH_CONTEXT);
  return (GO_ON);
}

int			plasmaClose(t_data *data)
{
  t_plasma		*plasma;

  plasma = data->data;
  if (!data->new)
    {
      bunny_sound_stop(&plasma->music->sound);
      bunny_delete_sound(&plasma->music->sound);
      bunny_delete_clipable(&plasma->pix->clipable);
      my_free(plasma);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int			plasmaMain(t_data *data)
{
  t_plasma		*plasma;

  if (!(plasma = MALLOC(sizeof(t_plasma))) ||
      !(plasma->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) ||
      !(plasma->music = bunny_load_music(PLASMA_MUSIC)))
    return (1);
  startMusic(&plasma->music->sound);
  set_palette(plasma->palette);
  plasma->size = 0.5;
  plasma->speed = 2;
  plasma->coeff = 0.1;
  plasma->origin = 0;
  data->data = plasma;
  data->new = false;
  return (0);
}
