/*
** context.c for gfx_scroller in /gfx_scroller/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 13:16:50 2016 Antoine Baché
** Last update Sat Mar 19 20:15:58 2016 Antoine Baché
*/

#include "demo.h"
#include "tools/common.h"

int	setContext(t_data *data)
{
  if (!(data->context = MALLOC(sizeof(t_bunny_context) * NB_CONTEXT)))
    return (1);
  setFireContext(&data->context[0]);
  setPlasmaContext(&data->context[1]);
  setFireContext(&data->context[2]);
  return (0);
}
