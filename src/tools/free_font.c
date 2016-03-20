/*
** free_font.c for free_font in /gfx_scroller/src/tools
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar 20 07:03:56 2016 Arthur ARNAUD
** Last update Sun Mar 20 12:25:20 2016 Arthur ARNAUD
*/

#include "tools/font.h"
#include "tools/common.h"

void	freeFont(t_font *font)
{
  int	i;

  i = -1;
  free(font->asset);
  free(font->chars);
  bunny_delete_clipable(&font->pix->clipable);
  while (font->tab[++i] != NULL)
    bunny_delete_clipable(&font->tab[i]->clipable);
}
