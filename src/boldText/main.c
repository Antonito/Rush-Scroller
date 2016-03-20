/*
** main.c for scrollingText in /home/arnaud_e/rendu/info/gfx_scroller/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar 20 05:26:50 2016 Arthur ARNAUD
** Last update Sun Mar 20 15:38:52 2016 Arthur ARNAUD
*/

#include "demo.h"
#include "boldText.h"

t_bunny_response	boldTextKey(t_bunny_event_state state,
				t_bunny_keysym key,
				t_data *data)
{
  return (eventKeys(state, key, data));
}

void			blitAllText(t_prog *prog)
{
  myBlit(prog->lyrics, prog->pix, prog->pos);
  myBlit(prog->rhum, prog->pix, prog->pos_rhum);
  myBlit(prog->rhum_sin, prog->pix,
	 subiVec2(prog->pos_sin,
		  ivec2(0, (int)(sin(prog->pos_sin.x / 5.0) * 100))));
  myBlit(prog->lyrics, prog->pix,
	 addiVec2(prog->pos, ivec2(prog->pix->clipable.clip_width,0)));
}

t_bunny_response	boldTextLoop(t_data *data)
{
  t_prog		*prog;

  if (data->new && scrollingTextDisplay(data))
    return (EXIT_ON_ERROR);
  prog = data->data;
  if (prog->pos.x-- < -(prog->pix->clipable.clip_width))
    prog->pos.x = 0;
  if ((prog->pos_rhum.x > prog->pix->clipable.clip_width  ||
      !(prog->pos_rhum.x += 7)) ||
      (prog->pos_rhum.y > prog->pix->clipable.clip_height ||
       !(prog->pos_rhum.y += 4)))
    {
      prog->pos_rhum.x = 0;
      prog->pos_rhum.y = 0;
    }
  if (prog->pos_sin.x++ > prog->pix->clipable.clip_width)
    prog->pos_sin.x = 0;
  clearColor(prog->pix, BLACK);
  blitAllText(prog);
  bunny_blit(&(data->win->buffer),
	     &(prog->pix->clipable), 0);
  bunny_display(data->win);
  return (GO_ON);
}

int		boldTextClose(t_data *data)
{
  t_prog	*prog;

  prog = data->data;
  if (!data->new)
    {
      bunny_delete_clipable(&prog->pix->clipable);
      bunny_delete_clipable(&prog->lyrics->clipable);
      my_free(prog);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int		boldTextDisplay(t_data *data)
{
  t_prog	*prog;

  if (!(prog = MALLOC(sizeof(t_prog))))
    return (1);
  data->data = prog;
  if (!(prog->pix = bunny_new_pixelarray(WIN_X, WIN_Y)) ||
      !(prog->lyrics = printText("the time has come the time for a drink",
				 "font2")) ||
      !(prog->rhum = printText("rhum", "font2")) ||
      !(prog->rhum_sin = printText("rhum", "font2")))
    return (1);
  prog->pos.x = 0;
  prog->pos.y = 100;
  prog->pos_rhum.x = 0;
  prog->pos_rhum.y = 0;
  prog->pos_sin.x = 0;
  prog->pos_sin.y = 300;
  data->new = false;
  return (0);
}
