/*
** my.h for fire in /home/petren_l/rendu/gfx_incendie
**
** Made by ludovic petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Fri Dec  4 20:13:39 2015 ludovic petrenko
** Last update Sat Mar 19 02:55:04 2016 Ludovic Petrenko
*/

#ifndef MY_H_
# define MY_H_

# include <lapin.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

# define WIN_NAME ("Ziçe gueurle ise haunne Phailleur!")
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define OCTET sizeof(char)
# define RAD(DEG) ((double)(DEG * M_PI / 180))
# define UNUSED __attribute__((unused))
# define ROUND(A) (A - (int)A < 0.5 ? (int)A : (int)A + 1)
# define ABS(VAL) (VAL >= 0 ? (VAL) : -(VAL))

typedef struct		s_plasma
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  int			origin;
  double		size;
  double		speed;
  double		coeff;
  unsigned int		palette[128];
}			t_plasma;

void			free_all(t_plasma *plasma);
t_bunny_response	my_event(t_bunny_event_state state,
				 t_bunny_keysym keysym,
				 t_plasma *plasma);
t_bunny_response	my_loop(t_plasma *plasma);
void			new_frame(t_plasma *plasma);
void			set_palette(unsigned int *palette);
void			tekpixel(t_bunny_pixelarray *pix,
				 int x, int y,
				 unsigned int color);
int			check_args(char **av);
#endif /* !MY_H_ */
