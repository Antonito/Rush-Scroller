/*
** load_font_ini.c for load_font_ini in rendu/info/gfx_scroller/src/tools
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Fri Mar 18 22:50:54 2016 Arthur ARNAUD
** Last update Sat Mar 19 04:19:24 2016 Antoine Baché
*/

#include "tools/font.h"

int		loadFontIni(t_font *font, char *path)
{
  t_bunny_ini	*file;

  if (!(file = bunny_load_ini(path)) ||
      !bunny_ini_get_field(file, "asset") ||
      !bunny_ini_get_field(file, "chars") ||
      !bunny_ini_get_field(file, "width") ||
      !bunny_ini_get_field(file, "height") ||
      !(font->asset = strdup(bunny_ini_get_field(file, "asset"))) ||
      !(font->chars = strdup(bunny_ini_get_field(file, "chars"))) ||
      (font->width = atoi(bunny_ini_get_field(file, "width"))) == 0 ||
      (font->height = atoi(bunny_ini_get_field(file, "height"))) == 0)
    return (1);
  return (0);
}

void		addCharFont(t_font *font, int j, int i)
{
  t_ivec2	origin;
  t_ivec2	incr;
  t_ivec2	res;

  incr = ivec2(-1, -1);
  origin = ivec2(i * font->width % font->pix->clipable.clip_width ,
		 i * font->width / font->pix->clipable.clip_width);
  while (++incr.y < font->height)
    {
      incr.x = -1;
      while (++incr.x < font->width)
	{
	  res = addiVec2(origin, incr);
	  font->tab[j] = font->pix[res.x + res.y *
				   font->pix->clipable.clip_width];
	}
    }

}

int	fillFontTab(t_font *font)
{
  int	i;
  int	j;
  int	len;

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
}

void		make_text_pix(t_bunny_pixelarray *res, t_font *font)
{
  int		i;
  t_ivec2	pos;

  pos.y = 0;
  pos.x = 0;
  i = -1;
  while (font->tab[++i] != NULL)
    {
      myBlit(font->tab[i], res, 1, pos);
      pos.x += font->width;
    }
}

t_bunny_pixelarray	*printText(char *str, char *font)
{
  t_font		*font;
  t_bunny_pixelarray	*res;
  char			*path;

  if (!(font = MALLOC(sizeof(t_font *)))
      !(path = MALLOC(sizeof(char) * (14 + strlen(str)))))
    return (NULL);
  sprintf(path, "assets/fonts/%s", str);
  loadFontIni(font, path);
  if (!(font->pix = bunny_load_pixelarray(font->asset)) ||
      !(font->tab =
	MALLOC(sizeof(t_bunny_pixelarray *) * strlenSpace(font->chars) + 1)))
    return (NULL);
  font->tab[strlen(font->chars)] = NULL;
  if (fillFontTab(font) ||
      !(res = bunny_new_pixelarray) ||
      (font->width * strlenSpace(font->chars), font->height))
    return (NULL);
  i  = -1;
  make_text_pix(res, font);
  return (res);
}
