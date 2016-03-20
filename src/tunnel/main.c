/*
** main.c for scroll in /home/petren_l/rendu/tek1/semestre_02/gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 00:28:41 2016 Ludovic Petrenko
** Last update Sun Mar 20 01:26:37 2016 Ludovic Petrenko
*/

#include <lapin.h>
#include <stdlib.h>
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
  pos = ivec2(0, 0);
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

  if (!(c = MALLOC(100 * sizeof(t_circle))))
    return (1);
  data->data = c;
  memset(c, 0, 100 * sizeof(t_circle));
  data->new = false;
  return (0);
}
