/*
** trigo.c for gfx_scroller in /gfx_scroller
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 18:57:32 2016 Antoine Baché
** Last update Sun Mar 20 22:38:01 2016 Antoine Baché
*/

#include <lapin.h>
#include <math.h>

void		init_sinuses(double *values)
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
    {
      init_sinuses(sinuses);
      isSet = true;
    }
  return (sinuses[get_val(nb)]);
}

double		my_cos(double nb)
{
  static double	cosinuses[7200];
  static bool	isSet = false;

  if (!isSet)
    {
      init_cosinuses(cosinuses);
      isSet = true;
    }
  return (cosinuses[get_val(nb)]);
}
