/*
** scrollingText.c for scrollingText in /gfx_scroller/src/context
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar 20 06:22:24 2016 Arthur ARNAUD
** Last update Sun Mar 20 06:23:07 2016 Arthur ARNAUD
*/

#include "scrollingText.h"
#include <string.h>

void	setScrollingTextContext(t_bunny_context *context)
{
  memset(context, 0, sizeof(t_bunny_context));
  context->key = (t_bunny_key)scrollingTextKey;
  context->loop = (t_bunny_loop)scrollingTextLoop;
}
