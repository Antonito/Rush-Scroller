/*
** starfield.h for scroll in /gfx_scroller/src/starfield
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 18:29:09 2016 Ludovic Petrenko
** Last update Sun Mar 20 12:09:00 2016 Ludovic Petrenko
*/

#ifndef STARFIELD_H_
# define STARFIELD_H_

# include <stdbool.h>
# include <lapin.h>
# include "tools/transform.h"
# include "demo.h"

# define ROUND(TYPE, NB) (NB - (TYPE)(NB) < 0.5 ? (TYPE)(NB) : (TYPE)(NB) + 1)

typedef struct	s_star
{
  t_ivec2	pos;
  t_ivec2	dir;
  t_color	col;
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
void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
			        t_color color);

#endif /* !STARFIELD_H_ */
