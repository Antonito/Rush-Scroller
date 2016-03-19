/*
** font.h for font in /home/arnaud_e/rendu/info/gfx_scroller/include/tools
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sat Mar 19 02:33:51 2016 Arthur ARNAUD
** Last update Sat Mar 19 04:54:19 2016 Arthur ARNAUD
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

int	loadFontIni(t_font *, char *);
int	fillFontTab(t_font *);
void	addCharFont(t_font *, int, int);
void	make_text_pix(t_bunny_pixelarray *, t_font *);
int	strlenSpace(char *);

#endif /* !FONT_H_ */
