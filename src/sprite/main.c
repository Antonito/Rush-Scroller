/*
** main.c for main in /home/arnaud_e/rendu/info/gfx_scroller/src/sprite
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Mar 19 18:30:57 2016 Arthur ARNAUD
** Last update Sat Mar 19 20:01:34 2016 Arthur ARNAUD
*/

#include "demo.h"
#include "sprite.h"
#include "tools/common.h"

t_bunny_response	spriteKey(t_bunny_event_state state,
				t_bunny_keysym key,
				t_data *data)
{
  return (eventKeys(state, key, data));
}

t_bunny_response	spriteLoop(t_data *data)
{
  t_prog		*prog;

  if (data->new && spriteDisplay(data))
    return (EXIT_ON_ERROR);
  prog = data->data;
  if (prog->i++ > 6)
    {
      prog->i = 0;
      prog->index++;
    }
  if (prog->index > 13)
    prog->index = 0;
  myBlit(prog->spritePix[prog->index], prog->pix, 1, prog->pos);
  bunny_blit(&(data->win->buffer),
	     &(prog->pix->clipable), 0);
  bunny_display(data->win);
  return (GO_ON);
}

int		spriteClose(t_data *data)
{
  t_prog	*prog;
  int		i;

  i = -1;
  prog = data->data;
  if (!data->new)
    {
      bunny_delete_clipable(&prog->pix->clipable);
      while (prog->spritePix[++i] != NULL)
	bunny_delete_clipable(&prog->spritePix[i]->clipable);
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
  if (!(prog->pix = bunny_new_pixelarray(WIN_X, WIN_Y)))
    return (1);
  if (!(prog->spritePix = loadSprite("wolf")))
    return (1);
  prog->index = 0;
  prog->pos.y = 10;
  prog->pos.x = 10;
  myBlit(prog->spritePix[prog->index], prog->pix, 1, prog->pos);
  data->new = false;
  return (0);
}
