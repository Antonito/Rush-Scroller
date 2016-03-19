/*
** demo.h for gfx_scroller in /gfx_scroller/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 18 21:36:02 2016 Antoine Baché
** Last update Sat Mar 19 13:40:54 2016 Antoine Baché
*/

#ifndef	DEMO_H_
# define DEMO_H_
# define UNUSED		__attribute__((unused))
# define WIN_X		1920
# define WIN_Y		1080
# define WIN_NAME	"Rush Scroller"
# define NB_CONTEXT	3

# include <lapin.h>

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	*mousePos;
  t_bunny_context	*context;
  void			*data;
  bool			new;
}			t_data;

/*
** Free
*/
int			freeData(t_data *, int);

/*
** Context
*/
int			setContext(t_data *);
int			setFireContext(t_bunny_context *);

#endif /* !DEMO_H_ */
