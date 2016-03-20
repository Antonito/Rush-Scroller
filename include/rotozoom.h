/*
** rotozoom.h for scroll in /gfx_scroller/src/rotozoom
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 04:44:02 2016 Ludovic Petrenko
** Last update Sun Mar 20 15:06:51 2016 Antoine Baché
*/

#ifndef ROTOZOOM_H_
# define ROTOZOOM_H_
# define ROTO_MUSIC	"assets/music/pasta.ogg"

# include <lapin.h>
# include "demo.h"

typedef struct		s_roto
{
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*pict;
  int			size;
  double		zoomSpeed;
  double		zoom;
  double		rotSpeed;
  double		rot;
  t_bunny_music		*music;
}			t_roto;

t_bunny_response	rotoKey(t_bunny_event_state,
				t_bunny_keysym,
				t_data *);
t_bunny_response	rotoLoop(t_data *);
int			rotozoom(t_data *);
void			rotateImage(t_bunny_pixelarray *,
				    t_bunny_pixelarray *, double);
void			changeZoomRotate(t_roto *);
void			repeatImage(t_bunny_pixelarray *,
				    t_bunny_pixelarray *, double);

#endif /* !ROTOZOOM_H_ */
