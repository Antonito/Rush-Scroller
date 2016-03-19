/*
** key_mod.c for gfx_scroller in /gfx_scroller/src/fire
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 02:06:28 2016 Antoine Baché
** Last update Sat Mar 19 02:06:34 2016 Antoine Baché
*/

#include "fire.h"

void	go_up_key(t_bunny_keysym key, void *prog)
{
  if (key == BKS_UP)
      ((t_prog *)prog)->mod[0] = 0;
  else if (key == BKS_DOWN)
    ((t_prog *)prog)->mod[1] = 0;
}

void	go_down_key(t_bunny_keysym key, void *prog)
{
  if (key == BKS_UP)
    ((t_prog *)prog)->mod[0] = 1;
  else if (key == BKS_DOWN)
    ((t_prog *)prog)->mod[1] = 1;
}
