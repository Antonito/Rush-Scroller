/*
** trigo.c for wolf in /home/asphahyre/rendu/gfx_wolf3d/src
**
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
**
** Started on  Wed Dec 23 14:59:40 2015 Luka Boulagnon
** Last update Sat Mar 19 18:53:52 2016 Ludovic Petrenko
*/

#include "tekdoom.h"

void		init_sinuses(double **values)
{
  int		i;
  double	angle;

  i = 0;
  angle = 0;
  while (i < 7200)
    {
      values[i] = sin(angle);
      angle += M_PI / 3600;
      ++i;
    }
}

void		init_cosinuses(double *values)
{
  int		i;
  double	angle;

  i = 0;
  angle = 0;
  while (i < 7200)
    {
      values[i] = cos(angle);
      angle += M_PI / 3600;
      ++i;
    }
}

int		get_val(double nb)
{
  int		value;

  value = nb * 20;
  value %= 7200;
  while (value < 0)
    value += 7200;
  return (value);
}

double		my_sin(double nb)
{
  static double	sinuses[7200];
  static bool	isSet = false;

  if (!isSet)
    init_sinuses(sinuses);
  return (sinuses[get_val(nb)]);
}

double		my_cos(double nb)
{
  static double	cosinuses[7200];
  static bool	isSet = false;

  if (!isSet)
    init_cosinuses(cosinuses);
  return (cosinuses[get_val(nb)]);
}
