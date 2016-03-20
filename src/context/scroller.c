/*
** scroller.c for scroller in /info/gfx_scroller/src/context
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar 20 00:42:42 2016 Arthur ARNAUD
** Last update Sun Mar 20 00:43:07 2016 Arthur ARNAUD
*/

#include "scroller.h"
#include <string.h>

void	setScrollerContext(t_bunny_context *context)
{
  memset(context, 0, sizeof(t_bunny_context));
  context->key = (t_bunny_key)scrollerKey;
  context->loop = (t_bunny_loop)scrollerLoop;
}