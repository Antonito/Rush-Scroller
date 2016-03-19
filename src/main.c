/*
** main.c for gfx_scroller in /gfx_scroller/src/demo1
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 18 19:40:34 2016 Antoine Baché
** Last update Sat Mar 19 13:50:02 2016 Antoine Baché
*/

#include <unistd.h>
#include <time.h>
#include "tools/common.h"
#include "demo.h"

t_bunny_response	eventMouse(t_bunny_event_state state,
				   t_bunny_mousebutton key, t_data *data)
{
  const bool		*mouseClick;

  mouseClick = bunny_get_mouse_button();
  return (GO_ON);
}

t_bunny_response	eventKeys(t_bunny_event_state state,
				  t_bunny_keysym key, t_data *data)
{
  if (state == GO_DOWN)
    {
      if (key == BKS_ESCAPE)
	return (EXIT_ON_SUCCESS);
    }
  return (GO_ON);
}

t_bunny_response	mainLoop(t_data *data)
{
  bunny_blit(&data->win->buffer, &data->pix->clipable, 0);
  bunny_display(data->win);
  return (GO_ON);
}

int			demo(void)
{
  t_data		*data;

  srand(time(NULL));
  if (!(data = MALLOC(sizeof(t_data))) ||
      !(data->win = bunny_start(WIN_X, WIN_Y, true, WIN_NAME)) ||
      !(data->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) ||
      setContext(data))
    return (1);
  data->new = true;
  data->mousePos = (t_bunny_position *)bunny_get_mouse_position();
  bunny_set_context(&data->context[0]);
  if (bunny_loop(data->win, 60, data) == EXIT_ON_ERROR)
    return (freeData(data, 1));
  return (freeData(data, 0));
}

int			main(UNUSED int ac, UNUSED char **av, char **env)
{
  if (!*env || demo())
    {
#ifdef	DEBUG
      write(1, "Status: KO\n", 11);
#endif
      return (1);
    }
#ifdef	DEBUG
  write(1, "Status: OK\n", 11);
#endif
  return (0);
}
