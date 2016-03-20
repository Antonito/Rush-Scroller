/*
** timer.c for gfx_scroller in /home/bache_a/work/Infographie/gfx_scroller/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar 20 15:57:40 2016 Antoine Baché
** Last update Sun Mar 20 17:03:27 2016 Antoine Baché
*/

#include <lapin.h>
#include <time.h>
#include "demo.h"
#include "tools/common.h"

t_bunny_response	timerChange(t_data *data, int timeToWait, time_t event)
{
  static time_t		current = 0;
  time_t		tmp;

  tmp = time(NULL);
  current = current + tmp - event;
  if (timeToWait && current >= ABS(timeToWait))
    {
      current = 0;
      if (!data->new)
	{
	  data->contextPrev = data->contextId;
	  (data->contextId == NB_CONTEXT - 1) ?
	    (data->contextId = 0) : (++data->contextId);
	  return (SWITCH_CONTEXT);
	}
    }
  return (GO_ON);
}
