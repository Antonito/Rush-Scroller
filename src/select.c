/*
** select.c for gfx_scroller in /gfx_scroller/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 17:41:57 2016 Antoine Baché
** Last update Sat Mar 19 20:46:49 2016 Arthur ARNAUD
*/

#include "demo.h"
#include "tools/common.h"

closeEvent     	selector(void)
{
  closeEvent	array;

  if ((array = MALLOC(sizeof(int *) * NB_CONTEXT)) == NULL)
    return (NULL);
  array[0] = &fireClose;
  array[1] = &plasmaClose;
  array[2] = &spriteClose;
  return (array);
}
