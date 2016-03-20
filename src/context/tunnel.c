/*
** tunnel.c for scroll in /gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 01:27:08 2016 Ludovic Petrenko
** Last update Sun Mar 20 11:01:13 2016 Antoine Baché
*/

#include <string.h>
#include "tunnel.h"

void	setTunnelContext(t_bunny_context *context)
{
  memset(context, 0, sizeof(t_bunny_context));
  context->key = (t_bunny_key)tunnelKey;
  context->loop = (t_bunny_loop)tunnelLoop;
}
