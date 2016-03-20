/*
** main.c for scroll in /home/petren_l/rendu/tek1/semestre_02/gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 00:28:41 2016 Ludovic Petrenko
** Last update Sun Mar 20 03:29:54 2016 Ludovic Petrenko
*/

#include <lapin.h>
#include <stdlib.h>
#include <string.h>
#include "tunnel.h"
#include "tools/common.h"

t_bunny_response	tunnelKey(t_bunny_event_state state,
				  t_bunny_keysym key,
				  t_data *data)
{
  return (eventKeys(state, key, data));
}

t_bunny_response	tunnelLoop(t_data *data)
{
  int			i;
  t_circle		*c;
  t_ivec2		pos;

  i = 0;
  if (data->new && tunnel(data))
    return (EXIT_ON_ERROR);
  clearColor(data->pix, 0xFF000000);
  c = data->data;
  pos = ivec2(WIN_X / 2, WIN_Y / 2);
  while (i < 100)
    {
      drawCircle(data->pix, c, i, &pos);
      i++;
    }
  moveCircles(c);
  bunny_blit(&(data->win->buffer), &(data->pix->clipable), 0);
  bunny_display(data->win);
  return (GO_ON);
}

int	tunnelClose(t_data *data)
{
  t_circle	*c;

  if (!data->new)
    {
      c = data->data;
      my_free(c);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int		tunnel(t_data *data)
{
  t_circle	*c;
  int		i;
  t_ivec2	s;

  if (!(c = MALLOC(100 * sizeof(t_circle))))
    return (1);
  data->data = c;
  i = -1;
  while (++i < 100)
    {
      s = ivec2((rand() % 2) ? -1 : 1, (rand() % 2) ? -1 : 1);
      c[i].pos = ivec2(rand() % 2 * s.x, rand() % 2 * s.y);
      if (!i)
	c[i].color = 0;
      else
	c[i].color = (c[i - 1].color + 1) % 510;
    }
  data->new = false;
  return (0);
}
