/*
** scroller.c for scroller in /info/gfx_scroller/src/context
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar 20 00:42:42 2016 Arthur ARNAUD
** Last update Sun Mar 20 11:00:55 2016 Antoine Baché
*/

#include <string.h>
#include "scroller.h"

void	setScrollerContext(t_bunny_context *context)
{
  memset(context, 0, sizeof(t_bunny_context));
  context->key = (t_bunny_key)scrollerKey;
  context->loop = (t_bunny_loop)scrollerLoop;
}
