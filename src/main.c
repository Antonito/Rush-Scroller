/*
** main.c for gfx_scroller in /gfx_scroller/src/demo1
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 18 19:40:34 2016 Antoine Baché
** Last update Sun Mar 20 01:51:35 2016 Antoine Baché
*/

#include <unistd.h>
#include <time.h>
#include "tools/common.h"
#include "demo.h"

t_bunny_response	eventKeys(t_bunny_event_state state,
				  t_bunny_keysym key, t_data *data)
{
  if (state == GO_DOWN && (data->contextPrev = data->contextId) > -1)
    {
      if (!data->new && key == BKS_ESCAPE)
	return (EXIT_ON_SUCCESS);
      if (!data->new && key == BKS_P)
	{
	  (!data->contextId) ?
	    (data->contextId = NB_CONTEXT - 1) : (--data->contextId);
	  return (SWITCH_CONTEXT);
	}
      if (!data->new && key == BKS_N)
	{
	  (data->contextId == NB_CONTEXT - 1) ?
	    (data->contextId = 0) : (++data->contextId);
	  return (SWITCH_CONTEXT);
	}
    }
  return (GO_ON);
}

int			demo(void)
{
  t_data		*data;
  t_bunny_response	ret;
  closeEvent   		closeIt;

  srand(time(NULL));
  set_max_heap_size(100);
  if (!(data = MALLOC(sizeof(t_data))) ||
      !(data->win = bunny_start(WIN_X, WIN_Y, true, WIN_NAME)) ||
      !(data->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) ||
      !(data->trans = bunny_new_pixelarray(WIN_X, WIN_Y)) ||
      setContext(data) || !(closeIt = selector()))
    return (1);
  data->new = true;
  data->contextId = 1;
  data->contextPrev = 1;
  ret = GO_ON;
  while (ret != EXIT_ON_SUCCESS)
    {
      bunny_set_context(&data->context[data->contextId]);
      if ((ret = bunny_loop(data->win, 60, data)) == EXIT_ON_ERROR)
	return (my_free(closeIt), freeData(data, 1));
      closeIt[data->contextPrev](data);
    }
  my_free(closeIt);
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
