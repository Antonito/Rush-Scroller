/*
** fire.h for gfx_scroller in /gfx_scroller/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 01:40:26 2016 Antoine Baché
** Last update Sat Mar 19 13:48:04 2016 Antoine Baché
*/

#ifndef FIRE_H_
# define FIRE_H_
# define PALETTE_SIZE 256
# define WHITE_COLOR 0xFFFFFF
# define BLACK_COLOR 0x000000

# include "demo.h"
# include <stdlib.h>
# include <lapin.h>
# include <time.h>

typedef struct		s_prog
{
  t_bunny_pixelarray	*pix;
  t_bunny_window	*win;
  t_bunny_music		*music;
  short			colors[1920 * (1080 + 2)];
  int			mod[3];
  unsigned int		palette[PALETTE_SIZE];
}			t_prog;

void			palette_generator(unsigned int *);
unsigned int		check_gradient(int);
void			display_fire(t_bunny_pixelarray *, short *,
				     unsigned int *);
int			pos_average(int, short *, int);
int			first_pos_average(int, short *);
int			last_pos_average(int, short *);
void			fire_calculator(short *, int);
t_bunny_response	fireKey(t_bunny_event_state, t_bunny_keysym, t_data *);
t_bunny_response	fireLoop(t_data *);
void			random_lines(short *);
int			flame(t_data *);
int			intensity_mod(int, int);
int			load_music(t_bunny_music *);
void			go_up_key(t_bunny_keysym, void *);
void			set_to_black(short *);
void			go_down_key(t_bunny_keysym, void *);

#endif /* !FIRE_H_ */
