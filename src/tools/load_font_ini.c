/*
** load_font_ini.c for load_font_ini in rendu/info/gfx_scroller/src/tools
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Fri Mar 18 22:50:54 2016 Arthur ARNAUD
** Last update Sun Mar 20 01:18:05 2016 Arthur ARNAUD
*/

#define _POSIX_C_SOURCE
#define _GNU_SOURCE
#define _BSD_SOURCE
#define _DEFAULT_SOURCE

#include "tools/font.h"

int		loadFontIni(t_font *font, char *path)
{
  t_bunny_ini	*file;

  if (!(file = bunny_load_ini(path)))
    return (1);
  if (!bunny_ini_get_field(file, "font", "asset", 0) ||
      !bunny_ini_get_field(file, "font", "chars", 0) ||
      !bunny_ini_get_field(file, "font", "width", 0) ||
      !bunny_ini_get_field(file, "font", "height", 0) ||
      !(font->asset = strdup(bunny_ini_get_field(file, "font", "asset", 0))) ||
      !(font->chars = strdup(bunny_ini_get_field(file, "font", "chars", 0))) ||
      !(font->width = atoi(bunny_ini_get_field(file, "font", "width", 0))) ||
      !(font->height = atoi(bunny_ini_get_field(file, "font", "height", 0))))
    return (1);
  return (0);
}

void		addCharFont(t_font *font, int j, int i)
{
  t_ivec2	origin;
  t_ivec2	incr;
  t_ivec2	res;
  t_color	*colors_src;
  t_color	*colors_dest;

  colors_src = font->pix->pixels;
  colors_dest = font->tab[j]->pixels;
  incr = ivec2(-1, -1);
  origin = ivec2(i * (font->width + 1) % font->pix->clipable.clip_width,
		 (i * (font->width + 1) / font->pix->clipable.clip_width) *
		 (font->height + 1));
  while (++incr.y < font->height)
    {
      incr.x = -1;
      while (++incr.x < font->width)
	{
	  res = addiVec2(origin, incr);
	  colors_dest[incr.x + incr.y * font->width] =
	    colors_src[res.x + res.y * font->pix->clipable.clip_width];
	}
    }

}

int	fillFontTab(t_font *font)
{
  int	i;
  int	j;

  i = -1;
  j = -1;
  while (font->chars[++i] != 0)
    {
      if (font->chars[i] != ' ')
	{
	  if (!(font->tab[++j] =
		bunny_new_pixelarray(font->width, font->height)))
	    return (1);
	  addCharFont(font, j, i);
	}
    }
  if (!(font->tab[++j] =
	bunny_new_pixelarray(font->width, font->height)))
    return (1);
  clearColor(font->tab[j], BLACK);
  return (0);
}

int		make_text_pix(t_bunny_pixelarray *res, t_font *font,
			      char * str)
{
  int		i;
  int		j;
  int		k;
  t_ivec2	pos;

  pos.y = 0;
  pos.x = 0;
  i = -1;
  while (str[++i] != 0)
    {
      j = -1;
      k = -1;
      while (font->tab[++j] != NULL && font->chars[++k] != 0 &&
	     font->chars[k] != str[i])
      	if (font->chars[k] == ' ')
      	  k++;
      if (font->tab[j] == NULL)
      	j = strlenSpace(font->chars);
      else
      	{
	  myBlit(font->tab[j], res, pos);
	  pos.x += font->width;
	}
    }
  return (0);
}

t_bunny_pixelarray	*printText(char *str, char *fontName)
{
  t_font		*font;
  t_bunny_pixelarray	*res;
  char			*path;

  if (!(font = MALLOC(sizeof(t_font *))) ||
      !(path = MALLOC(sizeof(char) * (16 + strlen(fontName)))))
    return (NULL);
  sprintf(path, "assets/font/%s.ini", fontName);
  if (loadFontIni(font, path))
    return (NULL);
  if (!(font->pix = bunny_load_pixelarray(font->asset)) ||
      !(font->tab =
	MALLOC(sizeof(t_bunny_pixelarray *) * (strlenSpace(font->chars) + 2))))
    return (NULL);
  font->tab[strlenSpace(font->chars) + 1] = NULL;
  if (fillFontTab(font) ||
      !(res = bunny_new_pixelarray(font->width * strlen(str), font->height)) ||
      make_text_pix(res, font, str))
    return (NULL);
  return (res);
}
