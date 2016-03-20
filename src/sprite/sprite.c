/*
** sprite.c for sprite in /home/arnaud_e/rendu/info/gfx_scroller/src/sprite
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Mar 19 17:30:03 2016 Arthur ARNAUD
** Last update Sun Mar 20 05:24:05 2016 Arthur ARNAUD
*/

#define _POSIX_C_SOURCE
#define _GNU_SOURCE
#define _BSD_SOURCE
#define _DEFAULT_SOURCE

#include "sprite.h"
#include "tools/common.h"

int		loadSpriteIni(t_sprite *sprite, char *path)
{
  t_bunny_ini	*file;

  if (!(file = bunny_load_ini(path)))
    return (1);
  if (!bunny_ini_get_field(file, "sprite", "picPath", 0) ||
      !bunny_ini_get_field(file, "sprite", "nb", 0) ||
      !bunny_ini_get_field(file, "sprite", "width", 0) ||
      !bunny_ini_get_field(file, "sprite", "height", 0) ||
      !(sprite->picPath =
	strdup(bunny_ini_get_field(file, "sprite", "picPath", 0))) ||
      !(sprite->width =
	atoi(bunny_ini_get_field(file, "sprite", "width", 0))) ||
      !(sprite->height =
	atoi(bunny_ini_get_field(file, "sprite", "height", 0))) ||
      !(sprite->nb =
	atoi(bunny_ini_get_field(file, "sprite", "nb", 0))))
    return (1);
  bunny_delete_ini(file);
  return (0);
}

void		addSprite(t_sprite *sprite, int j, int i)
{
  t_ivec2	origin;
  t_ivec2	incr;
  t_ivec2	res;
  t_color	*colors_src;
  t_color	*colors_dest;

  colors_src = sprite->pix->pixels;
  colors_dest = sprite->spritePix[j]->pixels;
  incr = ivec2(-1, -1);
  origin = ivec2(i * (sprite->width + 1) % sprite->pix->clipable.clip_width,
		 (i * (sprite->width + 1) / sprite->pix->clipable.clip_width) *
		 (sprite->height + 1));
  while (++incr.y < sprite->height)
    {
      incr.x = -1;
      while (++incr.x < sprite->width)
	{
	  res = addiVec2(origin, incr);
	  colors_dest[incr.x + incr.y * sprite->width] =
	    colors_src[res.x + res.y * sprite->pix->clipable.clip_width];
	}
    }
}

int	fillSprite(t_sprite *sprite)
{
  int	i;
  int	j;

  i = -1;
  j = -1;
  while (++i < sprite->nb)
    {
      if (!(sprite->spritePix[++j] =
	    bunny_new_pixelarray(sprite->width, sprite->height)))
	return (1);
      addSprite(sprite, j, i);
    }
  return (0);
}

t_bunny_pixelarray	**loadSprite(char *spriteName)
{
  t_sprite		*sprite;
  char			*path;

  if (!(sprite = MALLOC(sizeof(t_sprite *))) ||
      !(path = malloc(sizeof(char) * (19 + strlen(spriteName)))) ||
      !(sprintf(path, "assets/sprite/%s.ini", spriteName)))
    return (NULL);
  if (loadSpriteIni(sprite, path) ||
      !(sprite->pix = bunny_load_pixelarray(sprite->picPath)) ||
      !(sprite->spritePix =
	MALLOC(sizeof(t_bunny_pixelarray *) * (sprite->nb + 1))))
    return (NULL);
  sprite->spritePix[sprite->nb] = NULL;
  if (fillSprite(sprite))
    return (NULL);
  free(path);
  free(sprite->picPath);
  bunny_delete_clipable(&sprite->pix->clipable);
  return (sprite->spritePix);
}
