/*
** my.h for gfx_scroller in /gfx_scroller/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 04:43:43 2016 Antoine Baché
** Last update Sun Mar 20 14:39:38 2016 Antoine Baché
*/

#ifndef ONDULATION_H_
# define ONDULATION_H_
# define RATIO		0.33
# define FLAG_NAME	"assets/picture/star_wars.jpg"
# define FLAG_MUSIC	"assets/music/star_wars.ogg"
# define END_WHILE	100000

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "demo.h"
# include <lapin.h>

typedef	struct		s_ondulation
{
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*flag;
  int			height;
  int			width;
  int			var;
  int			dir;
  int			wind;
  int			speed;
  int			inv;
  t_bunny_music		*music;
}			t_ondulation;

void			move_flag(t_ondulation *);
t_bunny_response	ondulationKey(t_bunny_event_state, t_bunny_keysym,
				      t_data *);
t_bunny_response	ondulationLoop(t_data *);
int			ondulationMain(t_data *);
int			cpy_pix(t_ondulation *, char *, double);

#endif /* !MY_H */
