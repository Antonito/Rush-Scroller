/*
** starfield.h for scroll in /gfx_scroller/src/starfield
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 18:29:09 2016 Ludovic Petrenko
** Last update Sat Mar 19 20:23:16 2016 Ludovic Petrenko
*/

#ifndef STARFIELD_H_
# define STARFIELD_H_

# include <stdbool.h>
# include "tools/transform.h"
# include "demo.h"

typedef struct	s_star
{
  t_ivec2	pos;
  t_ivec2	dir;
}		t_star;

bool			isOffscreen(t_star *);
t_bunny_response	starLoop(t_data *);
int			starfield(t_data *);
void			drawStar(t_bunny_pixelarray *, t_star *);
void			moveStar(t_star *);
t_bunny_response	starKey(t_bunny_event_state,
				t_bunny_keysym,
				t_data *);
void			genStar(t_star *, double);

#endif /* !STARFIELD_H_ */
