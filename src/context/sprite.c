/*
** sprite.c for sprite in /home/arnaud_e/rendu/info/gfx_scroller/src/context
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Mar 19 19:16:37 2016 Arthur ARNAUD
** Last update Sun Mar 20 11:00:59 2016 Antoine Baché
*/

#include <string.h>
#include "sprite.h"

void	setSpriteContext(t_bunny_context *context)
{
  memset(context, 0, sizeof(t_bunny_context));
  context->key = (t_bunny_key)spriteKey;
  context->loop = (t_bunny_loop)spriteLoop;
}
