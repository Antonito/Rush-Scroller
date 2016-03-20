/*
** font.h for font in /home/arnaud_e/rendu/info/gfx_scroller/include/tools
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Mar 19 02:33:51 2016 Arthur ARNAUD
** Last update Sun Mar 20 07:10:11 2016 Arthur ARNAUD
*/

#ifndef FONT_H
# define FONT_H_

# include <string.h>
# include <stdio.h>
# include <lapin.h>
# include "transform.h"
# include "common.h"

typedef struct		s_font
{
  char			*asset;
  char			*chars;
  int			width;
  int			height;
  t_bunny_pixelarray	**tab;
  t_bunny_pixelarray	*pix;
}			t_font;

int			loadFontIni(t_font *, char *);
int			fillFontTab(t_font *);
void			addCharFont(t_font *, int, int);
void			freeFont(t_font *);
int			make_text_pix(t_bunny_pixelarray *, t_font *, char *);
int			strlenSpace(char *);
t_bunny_pixelarray	*printText(char *, char *);

#endif /* !FONT_H_ */
