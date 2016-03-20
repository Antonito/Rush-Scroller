/*
** sprite.h for sprite in /home/arnaud_e/rendu/info/gfx_scroller/include
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Mar 19 18:51:50 2016 Arthur ARNAUD
** Last update Sun Mar 20 16:02:20 2016 Antoine Baché
*/

#ifndef SPRITE_H_
# define SPRITE_H_
# define NYAN		"assets/music/nyanWolf.ogg"

# include "demo.h"
# include "tools/transform.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <lapin.h>

typedef struct		s_prog
{
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	**spritePix;
  int			i;
  int			index;
  t_ivec2		pos;
  t_bunny_music		*music;
}			t_prog;

typedef struct		s_sprite
{
  t_bunny_pixelarray	*pix;
  t_bunny_pixelarray	**spritePix;
  char			*picPath;
  int			width;
  int			height;
  int			nb;
}			t_sprite;

t_bunny_response	spriteKey(t_bunny_event_state,
				  t_bunny_keysym,
				  t_data *);
t_bunny_response	spriteLoop(t_data *);
int			spriteDisplay(t_data *);
int			loadSpriteIni(t_sprite *,
				      char *);
void			addSprite(t_sprite *,
				  int,
				  int);
int			fillSprite(t_sprite *);
t_bunny_pixelarray	**loadSprite(char *);

#endif /* !SPRITE_H_ */
