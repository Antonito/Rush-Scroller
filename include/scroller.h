/*
** scroller.h for scroller in /home/arnaud_e/rendu/info/gfx_scroller/include
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar 20 00:26:54 2016 Arthur ARNAUD
** Last update Sun Mar 20 00:44:36 2016 Arthur ARNAUD
*/

#ifndef SCROLLER_H_
# define SCROLLER_H_

# include "demo.h"
# include "tools/transform.h"
# include <stdlib.h>
# include <stdio.h>
# include <lapin.h>

typedef struct		s_prog
{
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*sky;
  t_bunny_pixelarray	*mountain;
  t_bunny_pixelarray	*grass;
  t_ivec2		sky_pos;
  t_ivec2		mountain_pos;
  t_ivec2		grass_pos;
}			t_prog;

t_bunny_response	scrollerKey(t_bunny_event_state,
				  t_bunny_keysym,
				  t_data *);
t_bunny_response	scrollerLoop(t_data *);
int			scrollerDisplay(t_data *);
void			blitAllPix(t_prog *);

#endif /* !SCROLLER_H_ */
