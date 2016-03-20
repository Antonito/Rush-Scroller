/*
** select.c for gfx_scroller in /gfx_scroller/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 17:41:57 2016 Antoine Baché
** Last update Sun Mar 20 02:21:20 2016 Antoine Baché
*/

#include "demo.h"
#include "tools/common.h"
#include "transition.h"

transFunc     	selectorTransition(void)
{
  transFunc	array;

  if ((array = MALLOC(sizeof(int *) * NB_TRANSITION)) == NULL)
    return (NULL);
  array[0] = &transitionFade;
  return (array);
}

closeEvent     	selector(void)
{
  closeEvent	array;

  if ((array = MALLOC(sizeof(int *) * NB_CONTEXT)) == NULL)
    return (NULL);
  array[0] = &fireClose;
  array[1] = &plasmaClose;
  array[2] = &spriteClose;
  array[3] = &starClose;
  array[4] = &ondulationClose;
  array[5] = &damierClose;
  array[6] = &scrollerClose;
  return (array);
}
