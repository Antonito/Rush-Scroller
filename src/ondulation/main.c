/*
** main.c for gfx_colle_fantasy2 in /gfx_colle_fantasy2/sujet1/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Jan 13 19:00:36 2016 Antoine Baché
** Last update Sat Mar 19 20:31:16 2016 Antoine Baché
*/

#include "ondulaton.h"

t_bunny_response	ondulationLoop(t_data *data)
{
  move_flag(data);
  bunny_blit(&data->win->buffer, &data->pix->clipable, 0);
  bunny_display(data->win);
  return (GO_ON);
}

t_bunny_response	ondulationKey(t_bunny_event_state	state,
				      t_bunny_keysym		key,
				      t_data			*data)
{
  if (state == GO_UP && key == BKS_ESCAPE)
    return (my_fct_free(data, 0));
  if (state == GO_UP && key == BKS_SPACE)
    data->inv = 1 - data->inv;
  if (state == GO_DOWN && key == BKS_LEFT && data->wind < 100)
    data->wind = data->wind + 2;
  if (state == GO_DOWN && key == BKS_RIGHT && data->wind > 26)
    data->wind = data->wind - 2;
  if (state == GO_DOWN && key == BKS_DOWN && data->speed < 20)
    data->speed = data->speed + 1;
  if (state == GO_DOWN && key == BKS_UP && data->speed > 4)
    data->speed = data->speed - 1;
  return (GO_ON);
}

int	       	rohan(char *path)
{
  t_data	*data;

  if ((data = bunny_malloc(sizeof(t_data))) == NULL ||
      cpy_pix(data, path, RATIO) == 1)
    return (1);
  data->dir = 1;
  data->var = 1;
  data->wind = 60;
  data->speed = 10;
  data->inv = 0;
  bunny_set_loop_main_function((t_bunny_loop)mainloop);
  bunny_set_key_response((t_bunny_key)escape);
  if (bunny_loop(data->win, 60, data) == EXIT_ON_ERROR)
    return (1);
  return (0);
}
