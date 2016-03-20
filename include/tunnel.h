/*
** tunnel.h for scroll in /home/petren_l/rendu/tek1/semestre_02/gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 00:41:06 2016 Ludovic Petrenko
** Last update Sun Mar 20 03:30:00 2016 Ludovic Petrenko
*/

#ifndef TUNNEL_H_
# define TUNNEL_H_

# include <lapin.h>
# include "tools/transform.h"
# include "demo.h"

typedef struct	s_circle
{
  t_ivec2	pos;
  int		color;
}		t_circle;

t_bunny_response	tunnelKey(t_bunny_event_state,
				  t_bunny_keysym,
				  t_data *);
t_bunny_response	tunnelLoop(t_data *);
int			tunnel(t_data *);
void			drawCircle(t_bunny_pixelarray *,
				   t_circle *, int , t_ivec2 *);
void			moveCircles(t_circle *);

#endif /* !TUNNEL_H_ */