/*
** sampler.c for gfx_scroller in /gfx_scroller/src/sampler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar 20 04:03:11 2016 Antoine Baché
** Last update Sun Mar 20 11:37:18 2016 Antoine Baché
*/

#include "sampler.h"
#include "tools/common.h"
#include <string.h>
#include <stdio.h>

void			playMusic(t_sampler *sampler)
{
  int			i;

  i = 0;
  bunny_compute_effect(sampler->music);
  bunny_sound_volume(&sampler->music->sound, 100);
  while (i < sampler->size)
    {
      bunny_sound_stop(&sampler->music->sound);
      bunny_sound_pitch(&sampler->music->sound,
			sampler->frequency[i] / sampler->freq);
      bunny_sound_play(&sampler->music->sound);
      usleep((int)sampler->duration[i] * 1000);
      ++i;
    }
}

int			countElemIni(t_bunny_ini *ini,
				     const char *scope,
				     const char *field)
{
  int			i;

  i = 0;
  while ((bunny_ini_get_field(ini, scope, field, i)) && ++i);
  return (i);
}

int			samplerLoad(t_bunny_ini *file, const char *scope,
				    t_sampler *sampler)
{
  int			nbDuration;
  int			nbFrequency;
  int			i;
  char			*tmp;

  if ((nbDuration = countElemIni(file, scope, "duration")) !=
      (nbFrequency = countElemIni(file, scope, "frequency")) ||
      !(sampler->duration = MALLOC(sizeof(double) * nbDuration)) ||
      !(sampler->frequency = MALLOC(sizeof(double) * nbFrequency)))
    return (1);
  i = 0;
  while (i < nbDuration)
    {
      if (!(tmp = (char *)bunny_ini_get_field(file, scope, "duration", i)))
	return (1);
      sampler->duration[i++] = atof(tmp);
    }
  i = 0;
  while (i < nbFrequency)
    {
      if (!(tmp = (char *)bunny_ini_get_field(file, scope, "frequency", i)))
	return (1);
      sampler->frequency[i++] = atof(tmp);
    }
  return (0);
}

int			samplerMain(t_data *data)
{
  t_sampler		*sampler;
  char			*path;
  char			*tmp;

  if (!(sampler = MALLOC(sizeof(t_sampler))) ||
      !(path = MALLOC(sizeof(char) * 1024)) ||
      (memset(path, 0, 1024),
       !(sampler->file = bunny_load_ini(SAMPLER_FILE)) ||
       !(tmp =
	 (char *)bunny_ini_get_field(sampler->file, "track1", "sample", 0))||
       sprintf(path, "assets/modlike/%s", tmp) < 0 ||
       !(sampler->music = bunny_load_effect(path))) ||
      samplerLoad(sampler->file, "track1", sampler))
    return (1);
  sampler->size = countElemIni(sampler->file, "track1", "duration");
  bunny_delete_ini(sampler->file);
  my_free(path);
  sampler->freq = 250;
  data->data = sampler;
  data->new = false;
  playMusic(sampler);
  return (0);
}
