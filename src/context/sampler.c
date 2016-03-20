/*
** sampler.c for gfx_scroller in /gfx_scroller/src/context
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 13:24:19 2016 Antoine Baché
** Last update Sun Mar 20 05:41:22 2016 Antoine Baché
*/

#include "sampler.h"
#include <string.h>

void	setSamplerContext(t_bunny_context *context)
{
  memset(context, 0, sizeof(t_bunny_context));
  context->key = (t_bunny_key)samplerKey;
  context->loop = (t_bunny_loop)samplerLoop;
}
