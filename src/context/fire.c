/*
** fire.c for gfx_scroller in /gfx_scroller/src/context
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 13:24:19 2016 Antoine Baché
** Last update Sat Mar 19 13:33:48 2016 Antoine Baché
*/

#include "fire.h"

int	setFireContext(t_bunny_context *context)
{
  context->key = fireKey;
  context->loop = fireLoop;
  return (0);
}
