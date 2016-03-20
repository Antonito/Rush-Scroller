/*
** main.c for main in /home/arnaud_e/rendu/info/gfx_scroller/src/sprite
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Mar 19 18:30:57 2016 Arthur ARNAUD
** Last update Sun Mar 20 01:14:59 2016 Arthur ARNAUD
*/

#include "demo.h"
#include "scroller.h"
#include "tools/common.h"

t_bunny_response	scrollerKey(t_bunny_event_state state,
				t_bunny_keysym key,
				t_data *data)
{
  return (eventKeys(state, key, data));
}

void			blitAllPix(t_prog *prog)
{
  /* myBlit(prog->sky, prog->pix, 1, subiVec2 */
  /* 	 (prog->sky_pos, ivec2(prog->sky->clipable.clip_width, 0))); */
  myBlit(prog->sky, prog->pix, prog->sky_pos);
  /* myBlit(prog->mountain, prog->pix, 1, subiVec2 */
  /* 	 (prog->mountain_pos, ivec2(prog->mountain->clipable.clip_width, 0))); */
  myBlit(prog->mountain, prog->pix, prog->mountain_pos);
  /* myBlit(prog->grass, prog->pix, 1, subiVec2 */
  /* 	 (prog->grass_pos, ivec2(prog->mountain->clipable.clip_width, 0))); */
  myBlit(prog->grass, prog->pix, prog->grass_pos);
}

t_bunny_response	scrollerLoop(t_data *data)
{
  t_prog		*prog;

  if (data->new && scrollerDisplay(data))
    return (EXIT_ON_ERROR);
  prog = data->data;
  /* if (prog->sky_pos.x++ > prog->sky->clipable.clip_width) */
  /*   prog->sky_pos.x = 0; */
  /* if (prog->mountain_pos.x++ > prog->mountain->clipable.clip_width) */
  /*   prog->mountain_pos.x = 0; */
  /* if (prog->grass_pos.x++ > prog->grass->clipable.clip_width) */
  /*   prog->grass_pos.x = 0; */
  blitAllPix(prog);
  bunny_blit(&(data->win->buffer),
	     &(prog->pix->clipable), 0);
  bunny_display(data->win);
  return (GO_ON);
}

int		scrollerClose(t_data *data)
{
  t_prog	*prog;

  prog = data->data;
  if (!data->new)
    {
      bunny_delete_clipable(&prog->pix->clipable);
      bunny_delete_clipable(&prog->sky->clipable);
      bunny_delete_clipable(&prog->mountain->clipable);
      bunny_delete_clipable(&prog->grass->clipable);
      my_free(prog);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int		scrollerDisplay(t_data *data)
{
  t_prog	*prog;

  if (!(prog = MALLOC(sizeof(t_prog))))
    return (1);
  data->data = prog;
  if (!(prog->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) ||
      !(prog->grass = bunny_load_pixelarray("assets/picture/herbe4.png")) ||
      !(prog->sky =
	bunny_load_pixelarray("assets/picture/nuages3.png")) ||
      !(prog->mountain =
	bunny_load_pixelarray("assets/picture/montagnes.png")))
    return (1);
  prog->sky_pos.x = 0;
  prog->sky_pos.y = 0;
  prog->mountain_pos.x = 0;
  prog->mountain_pos.y = 100;
  prog->grass_pos.x = 0;
  prog->grass_pos.y = 700;
  data->new = false;
  return (0);
}
