/*
** fire.c for gfx_scroller in /gfx_scroller/src/context
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 13:24:19 2016 Antoine Baché
** Last update Sat Mar 19 15:52:28 2016 Antoine Baché
*/

#include "fire.h"

void	setFireContext(t_bunny_context *context)
{
  context->key = (t_bunny_key)fireKey;
  context->loop = (t_bunny_loop)fireLoop;
  context->close = (t_bunny_close)fireClose;
}
