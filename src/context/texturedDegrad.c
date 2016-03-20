/*
** texturedDegrad.c for scroll in /gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 01:27:08 2016 Ludovic Petrenko
** Last update Sun Mar 20 08:22:01 2016 Antoine Baché
*/

#include "texturedDegrad.h"
#include <string.h>

void	setTexturedDegradContext(t_bunny_context *context)
{
  memset(context, 0, sizeof(t_bunny_context));
  context->key = (t_bunny_key)texturedDegradKey;
  context->loop = (t_bunny_loop)texturedDegradLoop;
}
