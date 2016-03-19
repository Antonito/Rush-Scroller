/*
** fire.c for gfx_scroller in /gfx_scroller/src/context
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 13:24:19 2016 Antoine Baché
** Last update Sat Mar 19 22:44:09 2016 Antoine Baché
*/

#include "ondulation.h"
#include <string.h>

void	setOndulationContext(t_bunny_context *context)
{
  memset(context, 0, sizeof(t_bunny_context));
  context->key = (t_bunny_key)ondulationKey;
  context->loop = (t_bunny_loop)ondulationLoop;
}
