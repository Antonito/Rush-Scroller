/*
** starfield.c for scroll in /gfx_scroller/src/context
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 19:51:49 2016 Ludovic Petrenko
** Last update Sat Mar 19 19:54:11 2016 Ludovic Petrenko
*/

#include "starfield.h"

void	setStarfieldContext(t_bunny_context *context)
{
  context->key = (t_bunny_key)starKey;
  context->loop = (t_bunny_loop)starLoop;
}
