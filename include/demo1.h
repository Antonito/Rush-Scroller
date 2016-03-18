/*
** demo1.h for gfx_scroller in /gfx_scroller/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 18 21:36:02 2016 Antoine Baché
** Last update Fri Mar 18 22:21:25 2016 Antoine Baché
*/

#ifndef	DEMO1_H_
# define UNUSED		__attribute__((unused))
# define WIN_X		1920
# define WIN_Y		1080
# define WIN_NAME	"Rush Scroller"

# include <lapin.h>

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	*mousePos;
  void			*data;
}			t_data;

#endif /* DEMO1_H_ */
