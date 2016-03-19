/*
** fire.c for gfx_scroller in /gfx_scroller/src/context
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 13:24:19 2016 Antoine Baché
** Last update Sat Mar 19 20:30:53 2016 Antoine Baché
*/

#include "ondulation.h"

void	setOndulationContext(t_bunny_context *context)
{
  context->key = (t_bunny_key)ondulationKey;
  context->loop = (t_bunny_loop)ondulationLoop;
}
