/*
** main.c for main in /home/arnaud_e/rendu/info/gfx_scroller/src/sprite
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Mar 19 18:30:57 2016 Arthur ARNAUD
** Last update Sat Mar 19 22:47:28 2016 Arthur ARNAUD
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

t_bunny_response	scrollerLoop(t_data *data)
{
  t_prog		*prog;

  if (data->new && scrollerDisplay(data))
    return (EXIT_ON_ERROR);
  prog = data->data;
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
      my_free(prog);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int		spriteDisplay(t_data *data)
{
  t_prog	*prog;

  if (!(prog = MALLOC(sizeof(t_prog))))
    return (1);
  data->data = prog;
  if (!(prog->pix = bunny_new_pixelarray(WIN_X, WIN_Y))
      !(prog->grass = bunny_load_pixelarray("assets/picture/herbe4.png")) ||
      !(prog->sky = bunny_load_pixelarray("assets/picture/nuage3.png")) ||
      !(prog->mountain = bunny_load_pixelarray("assets/picture/herbe4.png")))
    return (1);

  prog->index = 0;
  prog->pos.y = 10;
  prog->pos.x = 10;
  myBlit(prog->spritePix[prog->index], prog->pix, 1, prog->pos);
  data->new = false;
  return (0);
}
