/*
** starfield.c for scroll in /gfx_scroller/src/context
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 19:51:49 2016 Ludovic Petrenko
** Last update Sun Mar 20 11:01:03 2016 Antoine Baché
*/

#include <string.h>
#include "starfield.h"

void	setStarfieldContext(t_bunny_context *context)
{
  memset(context, 0, sizeof(t_bunny_context));
  context->key = (t_bunny_key)starKey;
  context->loop = (t_bunny_loop)starLoop;
}
