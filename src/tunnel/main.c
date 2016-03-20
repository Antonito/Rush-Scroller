/*
** main.c for scroll in /home/petren_l/rendu/tek1/semestre_02/gfx_scroller
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sun Mar 20 00:28:41 2016 Ludovic Petrenko
** Last update Sun Mar 20 14:22:11 2016 Antoine Baché
*/

#include <lapin.h>
#include <stdlib.h>
#include <string.h>
#include "tunnel.h"
#include "tools/common.h"

t_bunny_response	tunnelKey(t_bunny_event_state state,
				  t_bunny_keysym key,
				  t_data *data)
{
  return (eventKeys(state, key, data));
}

t_bunny_response	tunnelLoop(t_data *data)
{
  int			i;
  t_tunnel		*tun;
  t_ivec2		pos;

  i = 0;
  if (data->new && tunnel(data))
    return (EXIT_ON_ERROR);
  clearColor(data->pix, 0xFF000000);
  tun = data->data;
  pos = ivec2(WIN_X / 2, WIN_Y / 2);
  while (i < 100)
    {
      drawCircle(data->pix, tun->c, i, &pos);
      i++;
    }
  moveCircles(tun->c);
  bunny_blit(&(data->win->buffer), &(data->pix->clipable), 0);
  bunny_display(data->win);
  return (GO_ON);
}

int		tunnelClose(t_data *data)
{
  t_tunnel	*tunnel;

  if (!data->new)
    {
      tunnel = data->data;
      bunny_sound_stop(&tunnel->music->sound);
      bunny_delete_sound(&tunnel->music->sound);
      my_free(tunnel->c);
      my_free(tunnel);
    }
  data->data = NULL;
  data->new = true;
  return (0);
}

int		tunnel(t_data *data)
{
  t_tunnel	*tun;
  int		i;
  t_ivec2	s;

  if (!(tun = MALLOC(sizeof(t_tunnel))) ||
      !(tun->c = MALLOC(100 * sizeof(t_circle))) ||
      !(tun->music = bunny_load_music(TUNNEL_MUSIC)))
    return (1);
  data->data = tun;
  i = -1;
  bunny_sound_volume(&tun->music->sound, 100);
  bunny_sound_loop(&tun->music->sound, true);
  bunny_sound_play(&tun->music->sound);
  while (++i < 100)
    {
      s = ivec2((rand() % 2) ? -1 : 1, (rand() % 2) ? -1 : 1);
      tun->c[i].pos = ivec2(rand() % 2 * s.x, rand() % 2 * s.y);
      if (!i)
	tun->c[i].color = 0;
      else
	tun->c[i].color = (tun->c[i - 1].color + 1) % 510;
    }
  data->new = false;
  return (0);
}
