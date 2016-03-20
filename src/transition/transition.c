/*
** transition.c for gfx_scroller in /gfx_scroller/src/transition
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 05:05:23 2016 Antoine Baché
** Last update Sun Mar 20 02:36:20 2016 Antoine Baché
*/

#include "demo.h"
#include "transition.h"

int		transition(t_data *data, int type, t_bunny_pixelarray *pix2)
{
  return (data->transition[type](data->pix, pix2, data->win));
}
