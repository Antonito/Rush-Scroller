/*
** fire.c for gfx_scroller in /gfx_scroller/src/context
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 13:24:19 2016 Antoine Baché
** Last update Sun Mar 20 11:00:27 2016 Antoine Baché
*/

#include <string.h>
#include "fire.h"

void	setFireContext(t_bunny_context *context)
{
  memset(context, 0, sizeof(t_bunny_context));
  context->key = (t_bunny_key)fireKey;
  context->loop = (t_bunny_loop)fireLoop;
}
