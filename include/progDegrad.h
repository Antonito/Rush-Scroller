/*
** progDegrad.h for gfx_scroller in /gfx_scroller/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar 20 00:30:51 2016 Antoine Baché
** Last update Sun Mar 20 07:09:52 2016 Antoine Baché
*/

#ifndef PROGDEGRAD_H_
# define PROGDEGRAD_H_

# include "demo.h"
# include <stdlib.h>
# include <lapin.h>
# include <time.h>

typedef struct		s_progDegrad
{
  t_color		*palette;
}			t_progDegrad;

t_bunny_response	progDegradKey(t_bunny_event_state,
				  t_bunny_keysym,
				  t_data *);
t_bunny_response	progDegradLoop(t_data *);
int			progDegradMain(t_data *);

#endif /* !PROGDEGRAD_H_ */
