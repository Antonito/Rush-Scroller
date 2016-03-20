/*
** main.c for scroll in /gfx_scroller/src/rotozoom
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 04:36:02 2016 Ludovic Petrenko
** Last update Sun Mar 20 05:26:01 2016 Ludovic Petrenko
*/

#include <lapin.h>
#include <stdlib.h>
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
  int			i;
  t_roto		*roto;

  i = 0;
  if (data->new && rotozoom(data))
    return (EXIT_ON_ERROR);
  roto = data->data;
  repeatImage(roto->pix, roto->pict, roto->zoom);
  /* rotateImage(data->pix, roto->pix, roto->rot); */
  changeZoomRotate(roto);
  bunny_blit(&(data->win->buffer),
	     &(data->pix->clipable), 0);
  bunny_display(data->win);
  return (GO_ON);
}

int		rotoClose(t_data *data)
{
  t_roto	*roto;

  if (!data->new)
    {
      roto = data->data;
      bunny_delete_clipable(roto->pix);
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
  if (!(roto->pix = bunny_new_pixelarray(roto->size, roto->size)))
    return (1);
  if (!(roto->pict = bunny_load_pixelarray("fsm.png")))
    return (1);
  data->data = roto;
  clearColor(data->pix, 0xFF000000);
  data->new = false;
  return (0);
}
