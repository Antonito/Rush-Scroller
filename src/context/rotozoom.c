/*
** rotozoom.c for scroll in /gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 06:02:57 2016 Ludovic Petrenko
** Last update Sun Mar 20 06:03:50 2016 Ludovic Petrenko
*/

#include "rotozoom.h"
#include <string.h>

void	setRotozoomContext(t_bunny_context *context)
{
  memset(context, 0, sizeof(t_bunny_context));
  context->key = (t_bunny_key)rotoKey;
  context->loop = (t_bunny_loop)rotoLoop;
}
