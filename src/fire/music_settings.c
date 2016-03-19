/*
** music_settings.c for gfx_scroller in /gfx_scroller/src/fire
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 02:05:36 2016 Antoine Baché
** Last update Sat Mar 19 02:05:44 2016 Antoine Baché
*/

#include "fire.h"

int	load_music(t_bunny_music * music)
{
  bunny_sound_loop(&music->sound, 1);
  bunny_sound_volume(&music->sound, 20);
  bunny_sound_play(&music->sound);
  return (0);
}
