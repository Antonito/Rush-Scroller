/*
** main.c for scroll in /home/petren_l/rendu/tek1/semestre_02/gfx_scroller/src
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 03:44:45 2016 Ludovic Petrenko
** Last update Sat Mar 19 03:55:44 2016 Antoine Baché
*/

#include "plasma.h"

t_bunny_response	my_event(t_bunny_event_state state,
				 t_bunny_keysym keysym,
				 t_plasma *plasma)
{
  if (state == GO_DOWN && keysym == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (state == GO_DOWN && keysym == BKS_P)
    plasma->speed += (plasma->speed != 0.1 ? 0.1 : 0.2);
  if (state == GO_DOWN && keysym == BKS_M)
    plasma->speed -= (plasma->speed != -0.1 ? 0.1 : 0.2);
  if (state == GO_DOWN && keysym == BKS_O)
    plasma->size += (plasma->size != 0.1 ? 0.1 : 0.2);
  if (state == GO_DOWN && keysym == BKS_L)
    plasma->size -= (plasma->size != -0.1 ? 0.1 : 0.2);;
  if (state == GO_DOWN && keysym == BKS_I)
    plasma->coeff += (plasma->coeff != 0.1 ? 0.1 : 0.2);;
  if (state == GO_DOWN && keysym == BKS_K)
    plasma->coeff -= (plasma->coeff != -0.1 ? 0.1 : 0.2);;
  return (GO_ON);
}

t_bunny_response	my_loop(t_plasma *plasma)
{
  if (plasma->origin < 127)
    plasma->origin += plasma->speed;
  else
    plasma->origin = 0;
  new_frame(plasma);
  bunny_blit(&plasma->win->buffer, &plasma->pix->clipable, NULL);
  bunny_display(plasma->win);
  return (GO_ON);
}

void	free_all(t_plasma *plasma)
{
  bunny_delete_clipable(&plasma->pix->clipable);
  bunny_stop(plasma->win);
}

int		main__(int ac, char **av)
{
  t_plasma	plasma;

  if (ac > 1)
    return (check_args(av));
  bunny_set_loop_main_function((t_bunny_loop)&my_loop);
  bunny_set_key_response((t_bunny_key)&my_event);
  set_palette(plasma.palette);
  if (!(plasma.win = bunny_start(WIN_WIDTH, WIN_HEIGHT, false, WIN_NAME))
      || (plasma.pix = bunny_new_pixelarray(WIN_WIDTH, WIN_HEIGHT)) == NULL)
    return (1);
  plasma.size = 0.5;
  plasma.speed = 2;
  plasma.coeff = 0.1;
  plasma.origin = 0;
  bunny_loop(plasma.win, 30, &plasma);
  free_all(&plasma);
  return (0);
}
