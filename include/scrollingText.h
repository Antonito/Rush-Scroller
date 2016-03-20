/*
** scrollingText.h for scrollingText in gfx_scroller/include
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar 20 06:14:44 2016 Arthur ARNAUD
** Last update Sun Mar 20 06:18:21 2016 Arthur ARNAUD
*/

#ifndef SCROLLINGTEXT_H_
# define SCROLLINGTEXT_H_

# include "demo.h"
# include "tools/transform.h"
# include "tools/font.h"
# include "tools/common.h"
# include <stdlib.h>
# include <stdio.h>
# include <lapin.h>
# include <math.h>

typedef struct		s_prog
{
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*lyrics;
  t_ivec2		pos;
}			t_prog;

t_bunny_response	scrollingTextKey(t_bunny_event_state,
				  t_bunny_keysym,
				  t_data *);
t_bunny_response	scrollingTextLoop(t_data *);
int			scrollingTextDisplay(t_data *);

#endif /* !SCROLLINGTEXT_H_ */
