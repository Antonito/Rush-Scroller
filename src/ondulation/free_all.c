/*
** free_all.c for gfx_scroller in /gfx_scroller/src/ondulation
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 04:47:26 2016 Antoine Baché
** Last update Sat Mar 19 04:47:35 2016 Antoine Baché
*/

#include "ondulation.h"

t_bunny_response	my_fct_free(t_data *data, int error_true)
{
  bunny_delete_clipable(&data->pix->clipable);
  bunny_delete_clipable(&data->flag->clipable);
  bunny_stop(data->win);
  bunny_free(data);
  if (error_true == 1)
    return (EXIT_ON_ERROR);
  return (EXIT_ON_SUCCESS);
}
