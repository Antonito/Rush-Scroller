/*
** free2D.c for gfx_scroller in /gfx_scroller/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 18 23:23:22 2016 Antoine Baché
** Last update Fri Mar 18 23:24:59 2016 Antoine Baché
*/

#include "tools/common.h"

void	free2DArray(void **data)
{
  int	i;

  i = 0;
  while (data[i])
    my_free(data[++i]);
  my_free(data);
}
