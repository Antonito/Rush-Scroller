/*
** select.c for gfx_scroller in /gfx_scroller/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 17:41:57 2016 Antoine Baché
** Last update Sat Mar 19 18:01:15 2016 Antoine Baché
*/

#include "demo.h"

closeEvent     	selector(void)
{
  closeEvent	array;

  if ((array = malloc(sizeof(int *) * NB_CONTEXT)) == NULL)
    return (NULL);
  array[0] = &fireClose;
  array[1] = &plasmaClose;
  return (array);
}
