/*
** fire_calcul.c for gfx_scroller in /gfx_scroller/src/fire
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 02:06:50 2016 Antoine Baché
** Last update Sat Mar 19 02:44:48 2016 Antoine Baché
*/

#include "fire.h"

int	pos_average(int i, short *colors, int mod)
{
  int	average;
  int	p_l;
  int	p_r;
  int	p_u;
  int	p;

  p = colors[i + WIN_X];
  if (i > WIN_X)
    p_l = colors[i - WIN_X];
  else
    p_l = BLACK_COLOR;
  p_r = colors[i + WIN_X + 2];
  p_u = colors[i + (WIN_X << 1)];
  average = (p + p_l + p_r + p_u) / 4;
  if (average > 70 && average < 120 && rand() % 100 > 95)
    average -= 11;
  if (average < 64)
    average -= 10;
  average = intensity_mod(average, mod);
  return (average);
}

int	intensity_mod(int average, int mod)
{
  if (rand() % 100 > 95)
    average += mod;
  if (average >= 90 && rand() % 100 >  97)
    average -= 15;
  if (average < 0)
    average = 0;
  return (average);
}

int	first_pos_average(int i, short *colors)
{
  int	average;

  average = (colors[i + WIN_X] + colors[i + (WIN_X << 1)] +
	     colors[i + WIN_X + 1]) / 3;
  return (average);
}

int	last_pos_average(int i, short *colors)
{
  int	average;

  average = (colors[i + WIN_X] + colors[i + (WIN_X << 1)] +
	      colors[i + WIN_X - 1]) / 3;
  return (average);
}

void	fire_calculator(short *colors, int mod)
{
  int	i;
  int	average;

  i = WIN_X * WIN_Y;
  while (--i >= (700 * WIN_X))
    {
      if (i % WIN_X == WIN_X - 1)
	average = last_pos_average(i, colors);
      else if (i % WIN_X == 0)
	average = first_pos_average(i, colors);
      else
	average = pos_average(i, colors, mod);
      colors[i] = average;
    }
}
