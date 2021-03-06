/*
** matext.h for scroll in /gfx_scroller/src
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 13:17:07 2016 Ludovic Petrenko
** Last update Sun Mar 20 14:56:09 2016 Ludovic Petrenko
*/

#ifndef MATEXT_H_
# define MATEXT_H_

# include <lapin.h>
# include "tools/transform.h"
# include "demo.h"

typedef struct		s_matext
{
  t_bunny_pixelarray	*img;
  t_vec3		corners[4];
  t_vec3		rot;
  t_ivec2		decal;
  unsigned int		pal[510];
}			t_matext;

t_bunny_response	matextKey(t_bunny_event_state,
				t_bunny_keysym,
				  t_data *);
t_bunny_response	matextLoop(t_data *);
int			matext(t_data *);
void			drawMatext(t_bunny_pixelarray *, t_matext *);
void			moveMatext(t_matext *);

#endif /* !MATEXT_H_ */
