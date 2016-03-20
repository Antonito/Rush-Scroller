/*
** my.h for fire in /home/petren_l/rendu/gfx_incendie
**
** Made by ludovic petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Fri Dec  4 20:13:39 2015 ludovic petrenko
** Last update Sun Mar 20 15:23:32 2016 Antoine Baché
*/

#ifndef MY_H_
# define MY_H_
# define PLASMA_MUSIC	"assets/music/plasma.ogg"

# include "tools/common.h"
# include <lapin.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include "demo.h"

# define OCTET		sizeof(char)
# define RAD(DEG)	((double)(DEG * M_PI / 180))
# define ROUND(A)	(A - (int)A < 0.5 ? (int)A : (int)A + 1)

typedef struct		s_plasma
{
  t_bunny_pixelarray	*pix;
  int			origin;
  double		size;
  double		speed;
  double		coeff;
  double		**preCos;
  unsigned int		palette[128];
  t_bunny_music		*music;
}			t_plasma;

void			free_all(t_plasma *plasma);
t_bunny_response	plasmaKey(t_bunny_event_state state,
				 t_bunny_keysym keysym,
				 t_data *plasma);
t_bunny_response	plasmaLoop(t_data *plasma);
void			new_frame(t_plasma *plasma);
void			set_palette(unsigned int *palette);
void			tekpixel2(t_bunny_pixelarray *pix,
				 int x, int y,
				 unsigned int color);
int			check_args(char **av);
int			plasmaMain(t_data *);
int			get_val(double);

#endif /* !MY_H_ */
