/*
** demo.h for gfx_scroller in /gfx_scroller/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 18 21:36:02 2016 Antoine Baché
** Last update Sat Mar 19 23:12:19 2016 Antoine Baché
*/

#ifndef	DEMO_H_
# define DEMO_H_
# define UNUSED		__attribute__((unused))
# define WIN_X		1920
# define WIN_Y		1080
# define WIN_NAME	"Rush Scroller"
# define NB_CONTEXT	5

# include <lapin.h>

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*pix;
  t_bunny_position	*mousePos;
  t_bunny_context	*context;
  int			contextId;
  int			contextPrev;
  void			*data;
  bool			new;
}			t_data;

typedef	int (**closeEvent)(t_data *);

closeEvent		selector(void);

/*
** Common events
*/
t_bunny_response	eventKeys(t_bunny_event_state, t_bunny_keysym,
				  t_data *);

/*
** Free
*/
int			freeData(t_data *, int);

/*
** Context
*/
int			setContext(t_data *);
void			setFireContext(t_bunny_context *);
void			setPlasmaContext(t_bunny_context *);
void			setSpriteContext(t_bunny_context *);
void			setStarfieldContext(t_bunny_context *);
void			setOndulationContext(t_bunny_context *);

/*
** Free
*/
int			fireClose(t_data *);
int			plasmaClose(t_data *);
int			spriteClose(t_data *);
int			starClose(t_data *);
int			ondulationClose(t_data *);

#endif /* !DEMO_H_ */
