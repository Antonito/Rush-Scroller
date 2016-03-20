/*
** rotozoom.h for scroll in /gfx_scroller/src/rotozoom
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 04:44:02 2016 Ludovic Petrenko
** Last update Sun Mar 20 05:04:40 2016 Ludovic Petrenko
*/

#ifndef ROTOZOOM_H_
# define ROTOZOOM_H_

# include <lapin.h>

typedef struct		s_roto
{
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*pict;
  int			size;
  double		zoomSpeed;
  double		zoom;
  double		rotSpeed;
  double		rot;
}			t_roto;

#endif /* !ROTOZOOM_H_ */
