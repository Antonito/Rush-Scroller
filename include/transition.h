/*
** transition.h for gfx_scroller in /gfx_scroller/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar 20 00:30:51 2016 Antoine Baché
** Last update Sun Mar 20 17:23:37 2016 Antoine Baché
*/

#ifndef TRANSITION_H_
# define TRANSITION_H_
# define NB_TRANSITION 2

# include "demo.h"
# include <stdlib.h>
# include <lapin.h>
# include <time.h>

typedef	enum	e_transType
  {
    FADE	= 0,
    MORPHING	= 1
  }		t_transType;

typedef	int (**transFunc)(t_bunny_pixelarray *, t_bunny_pixelarray *,
			  t_bunny_window *);

transFunc		selectorTransition(void);
int			transition(t_data *, int, t_bunny_pixelarray *);

/*
** transitionType
*/
int			transitionFade(t_bunny_pixelarray *,
				       t_bunny_pixelarray *,
				       t_bunny_window *);
int			transitionMorph(t_bunny_pixelarray *,
					t_bunny_pixelarray *,
				       t_bunny_window *);

#endif /* !TRANSITION_H_ */
