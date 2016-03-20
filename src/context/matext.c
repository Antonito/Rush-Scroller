/*
** matext.c for scroll in /gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 14:06:23 2016 Ludovic Petrenko
** Last update Sun Mar 20 22:41:38 2016 Antoine Baché
*/

#include <string.h>
#include "matext.h"

void	setMatextContext(t_bunny_context *context)
{
  memset(context, 0, sizeof(t_bunny_context));
  context->key = (t_bunny_key)matextKey;
  context->loop = (t_bunny_loop)matextLoop;
}
