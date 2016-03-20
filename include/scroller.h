/*
** scroller.h for scroller in /home/arnaud_e/rendu/info/gfx_scroller/include
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar 20 00:26:54 2016 Arthur ARNAUD
** Last update Sun Mar 20 15:47:40 2016 Antoine Baché
*/

#ifndef SCROLLER_H_
# define SCROLLER_H_

# define WIDTH		clipable.clip_width
# define HEIGHT		clipable.clip_height
# define HERBE4		"assets/picture/herbe4.png"
# define NUAGE3		"assets/picture/nuages3.png"
# define MONTAGNES	"assets/picture/montagnes.png"
# define BUNNY		"assets/picture/lapin_noir.png"
# define MUSIC_BUNNY	"assets/music/bunny.ogg"

# include "demo.h"
# include "tools/transform.h"
# include "tools/common.h"
# include <stdlib.h>
# include <stdio.h>
# include <lapin.h>
# include <math.h>

typedef struct		s_prog
{
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	*sky;
  t_bunny_pixelarray	*bigSky;
  t_bunny_pixelarray	*mountain;
  t_bunny_pixelarray	*bigMountain;
  t_bunny_pixelarray	*grass;
  t_bunny_pixelarray	*bigGrass;
  t_bunny_pixelarray	*bunny;
  t_bunny_pixelarray	*bigBunny;
  t_ivec2		sky_pos;
  t_ivec2		mountain_pos;
  t_ivec2		grass_pos;
  t_ivec2		bunny_pos;
  t_bunny_music		*music;
}			t_prog;

t_bunny_response	scrollerKey(t_bunny_event_state,
				  t_bunny_keysym,
				  t_data *);
t_bunny_response	scrollerLoop(t_data *);
int			scrollerDisplay(t_data *);
void			blitAllPix(t_prog *);
void			setProg(t_prog *);
void			clearPix(t_bunny_pixelarray *);

#endif /* !SCROLLER_H_ */
