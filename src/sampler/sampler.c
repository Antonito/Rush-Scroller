/*
** sampler.c for gfx_scroller in /gfx_scroller/src/sampler
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar 20 04:03:11 2016 Antoine Baché
** Last update Sun Mar 20 05:53:50 2016 Antoine Baché
*/

#include "sampler.h"
#include "tools/common.h"
#include <string.h>
#include <stdio.h>

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
       !(sampler->music = bunny_load_music(path))) ||
      samplerLoad(sampler->file, "track1", sampler))
    return (1);
  bunny_delete_ini(sampler->file);
  my_free(path);
  data->data = sampler;
  data->new = false;
  return (0);
}
