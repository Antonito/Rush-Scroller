/*
** main.c for scrollingText in /home/arnaud_e/rendu/info/gfx_scroller/src
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar 20 05:26:50 2016 Arthur ARNAUD
** Last update Sun Mar 20 06:12:25 2016 Arthur ARNAUD
*/

#include "demo.h"
#include "scrollingText.h"

t_bunny_response	scrollingTextKey(t_bunny_event_state state,
				t_bunny_keysym key,
				t_data *data)
{
  return (eventKeys(state, key, data));
}

t_bunny_response	scrollingTextLoop(t_data *data)
{
  t_prog		*prog;

  if (data->new && scrollerDisplay(data))
    return (EXIT_ON_ERROR);
  prog = data->data;
  if (prog->pos.x-- < -(prog->lyrics->clipable.clip_width))
    prog->pos.x = 0;
  myBlit(prog->lyrics, prog->pix, prog->pos)
  bunny_blit(&(data->win->buffer),
	     &(prog->pix->clipable), 0);
  bunny_display(data->win);
  return (GO_ON);
}

int		scrollingTextClose(t_data *data)
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

int		scrollingTextDisplay(t_data *data)
{
  t_prog	*prog;

  if (!(prog = MALLOC(sizeof(t_prog))))
    return (1);
  data->data = prog;
  if (!(prog->pix = bunny_new_pixelarray(WIN_X, WIN_Y) ||
	!(prog->lyrics = printText("The time has come The time for a drink
But I don't want whiskey or gin There's only one drink
That gets me so drunk Until my head starts to spin
Far to the west Under tropical sun This mystical drink is brewed
On our mission to get totally drunk
We have got nothing to lose Rum is the power
Rum is the key Rum is the thing that will set us free!
Rum rum rum yarr Rum rum ahoy Rum rum rum yarr
Rum rum gimme more rum Rum rum rum yarr
Rum rum ahoy Rum rum rum yarr Rum rum ya ha ha ha", "font2"))))
    return (1);
  prog->pos.x = 0;
  prog->pos.y = 100;
  data->new = false;
  return (0);
}
