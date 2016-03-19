/*
** my.h for gfx_scroller in /gfx_scroller/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 04:43:43 2016 Antoine Baché
** Last update Sat Mar 19 04:43:50 2016 Antoine Baché
*/

#ifndef ONDULATION_H_
# define ONDULATION_H_
# define RATIO		0.33
# define END_WHILE	100000

# include <unistd.h>
# include <stdlib.h>
# include <lapin.h>
# include <math.h>

typedef	struct		s_data
{
  t_bunny_window       	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*flag;
  int			height;
  int			width;
  int			var;
  int			dir;
  int			wind;
  int			speed;
  int			inv;
}			t_data;

void			move_flag(t_data *);
t_bunny_response	my_fct_free(t_data *, int);
int			cpy_pix(t_data *, char *, double);

#endif /* !MY_H */
