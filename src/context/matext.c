/*
** matext.c for scroll in /gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 14:06:23 2016 Ludovic Petrenko
** Last update Sun Mar 20 14:08:13 2016 Ludovic Petrenko
*/

#include "matext.h"
#include <string.h>

void	setMatextContext(t_bunny_context *context)
{
  memset(context, 0, sizeof(t_bunny_context));
  context->key = (t_bunny_key)matextKey;
  context->loop = (t_bunny_loop)matextLoop;
}
