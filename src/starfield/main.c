/*
** main.c for scroll in /gfx_scroller/src/starfield
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 18:21:55 2016 Ludovic Petrenko
** Last update Sat Mar 19 19:50:15 2016 Ludovic Petrenko
*/

#include <lapin.h>
#include <stdlib.h>
#include "starfield.h"
#include "tools/common.h"

t_bunny_response	starKey(t_bunny_event_state state,
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

bool	isOffscreen(t_star *s)
{
  if (s->pos.x < 0 || s->pos.x >= WIN_X ||
      s->pos.y < 0 || s->pos.y >= WIN_Y)
    return (true);
  return (false);
}

t_bunny_response	starfieldLoop(t_data *data)
{
  int			i;

  i = 0;
  clearColor(data->pix, 0xFF000000);
  while (i < 100)
    {
      drawStar(data->pix, data->star + i);
      moveStar(data->star + i);
      if (isOffscreen(data->star + i))
	genStar(star + i, 10.0);
      i++;
    }
  bunny_blit(&(data->win->buffer),
	     &(prog->pix->clipable), 0);
  bunny_display(data->win);
  return (GO_ON);
}

int	starClose(t_data *data)
{
  t_star	*star;

  if (!data->new)
    {
      star = data->data;
      my_free(star);
    }
  data->data = NULL;
  data->new = true;
}

int		starfield(t_data *data)
{
  t_star	*star;
  int		i;

  if (!(star = MALLOC(100 * sizeof(t_star))))
    return (1);
  data->data = star;
  i = -1;
  while (++i < 100)
    genStar(star + i, 10.0);
  data->new = false;
  return (0);
}
