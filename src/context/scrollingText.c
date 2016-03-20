/*
** scrollingText.c for scrollingText in /gfx_scroller/src/context
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar 20 06:22:24 2016 Arthur ARNAUD
** Last update Sun Mar 20 22:41:57 2016 Antoine Baché
*/

#include <string.h>
#include "scrollingText.h"

void	setScrollingTextContext(t_bunny_context *context)
{
  memset(context, 0, sizeof(t_bunny_context));
  context->key = (t_bunny_key)scrollingTextKey;
  context->loop = (t_bunny_loop)scrollingTextLoop;
}
