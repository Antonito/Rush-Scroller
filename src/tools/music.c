/*
** music.c for gfx_scroller in /gfx_scroller/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar 20 14:57:29 2016 Antoine Baché
** Last update Sun Mar 20 14:58:41 2016 Antoine Baché
*/

#include <lapin.h>

void	startMusic(t_bunny_sound *sound)
{
  bunny_sound_volume(sound, 100);
  bunny_sound_loop(sound, true);
  bunny_sound_play(sound);
}
