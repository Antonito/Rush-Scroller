/*
** free.c for gfx_scroller in /gfx_scroller/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 18 23:10:56 2016 Antoine Baché
** Last update Sun Mar 20 21:45:47 2016 Antoine Baché
*/

#include <stdlib.h>
#include "tools/common.h"
#include "demo.h"

int	freeData(t_data *data, int ret)
{
  bunny_delete_clipable(&data->pix->clipable);
  bunny_delete_clipable(&data->trans->clipable);
  bunny_stop(data->win);
  my_free(data->transition);
  my_free(data->context);
  my_free(data);
  return (ret);
}
