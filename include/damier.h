/*
** damier.h for gfx_scroller in /gfx_scroller/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar 20 00:30:51 2016 Antoine Baché
** Last update Sun Mar 20 01:11:36 2016 Antoine Baché
*/

#ifndef DAMIER_H_
# define DAMIER_H_
# define DAMIER_SRC	"assets/picture/star_wars.jpg"
# define MASK_SRC	"assets/picture/damier.jpg"

# include "demo.h"
# include <stdlib.h>
# include <lapin.h>
# include <time.h>

typedef struct		s_damier
{
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*mask;
  t_bunny_pixelarray	*src;
}			t_damier;

t_bunny_response	damierKey(t_bunny_event_state,
				  t_bunny_keysym,
				  t_data *);
t_bunny_response	damierLoop(t_data *);
int			damierMain(t_data *);

#endif /* !DAMIER_H_ */
