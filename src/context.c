/*
** context.c for gfx_scroller in /gfx_scroller/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 13:16:50 2016 Antoine Baché
** Last update Sun Mar 20 15:08:11 2016 Ludovic Petrenko
*/

#include "demo.h"
#include "tools/common.h"

int	setContext(t_data *data)
{
  if (!(data->context = MALLOC(sizeof(t_bunny_context) * NB_CONTEXT)))
    return (1);
  setFireContext(&data->context[0]);
  setPlasmaContext(&data->context[1]);
  setSpriteContext(&data->context[2]);
  setStarfieldContext(&data->context[3]);
  setOndulationContext(&data->context[4]);
  setDamierContext(&data->context[5]);
  setScrollerContext(&data->context[6]);
  setTunnelContext(&data->context[7]);
  setSamplerContext(&data->context[8]);
  setProgDegradContext(&data->context[9]);
  setTexturedDegradContext(&data->context[10]);
  setRotozoomContext(&data->context[11]);
  setScrollingTextContext(&data->context[12]);
  setMatextContext(&data->context[12]);
  return (0);
}
