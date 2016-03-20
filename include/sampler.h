/*
** sampler.h for gfx_scroller in /gfx_scroller/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Mar 20 00:30:51 2016 Antoine Baché
** Last update Sun Mar 20 11:57:28 2016 Antoine Baché
*/

#ifndef SAMPLER_H_
# define SAMPLER_H_
# define SAMPLER_FILE	"assets/modlike/aerodynamic.bsf"

# include "demo.h"
# include <stdlib.h>
# include <lapin.h>
# include <time.h>

typedef struct		s_sampler
{
  t_bunny_effect       	*music;
  t_bunny_ini		*file;
  double		*duration;
  double		*frequency;
  int			size;
  int			freq;
}			t_sampler;

void			playMusic(t_sampler *, int);
t_bunny_response	samplerKey(t_bunny_event_state,
				  t_bunny_keysym,
				  t_data *);
t_bunny_response	samplerLoop(t_data *);
int			samplerMain(t_data *);

#endif /* !SAMPLER_H_ */
