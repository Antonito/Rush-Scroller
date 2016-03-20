/*
** main.c for scroll in /gfx_scroller/src/object
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 04:06:32 2016 Ludovic Petrenko
** Last update Sun Mar 20 04:08:50 2016 Ludovic Petrenko
*/

#include <lapin.h>
#include <stdlib.h>
#include "starfield.h"
#include "tools/common.h"

t_bunny_response	objKey(t_bunny_event_state state,
				t_bunny_keysym key,
				t_data *data)
{
  return (eventKeys(state, key, data));
}

t_bunny_response	objLoop(t_data *data)
{
  int			i;
  t_obj			*obj;

  i = 0;
  if (data->new && object(data))
    return (EXIT_ON_ERROR);
  clearColor(data->pix, 0xFF000000);
  obj = data->data;

  bunny_blit(&(data->win->buffer),
	     &(data->pix->clipable), 0);
  bunny_display(data->win);
  return (GO_ON);
}

int	objClose(t_data *data)
{
  t_obj	*obj;

  if (!data->new)
    {
      obj = data->data;
      my_free(obj);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int	        object(t_data *data)
{
  t_obj	*obj;

  if (!(obj = MALLOC(100 * sizeof(t_obj))))
    return (1);
  data->data = obj;
  data->new = false;
  return (0);
}
