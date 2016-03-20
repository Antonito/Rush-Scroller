/*
** texturedDegrad.h for gfx_scroller in /gfx_scroller/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar 20 00:30:51 2016 Antoine Baché
** Last update Sun Mar 20 08:42:41 2016 Antoine Baché
*/

#ifndef TEXTUREDDEGRAD_H_
# define TEXTUREDDEGRAD_H_
# define TEXTURE_SRC	"assets/picture/iceberg.jpg"

# include "demo.h"
# include <stdlib.h>
# include <lapin.h>
# include <time.h>

t_bunny_response	texturedDegradKey(t_bunny_event_state,
					  t_bunny_keysym,
					  t_data *);
t_bunny_response	texturedDegradLoop(t_data *);
int			texturedDegradMain(t_data *);

#endif /* !TEXTUREDDEGRAD_H_ */
