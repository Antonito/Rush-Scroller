/*
** select.c for gfx_scroller in /gfx_scroller/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat Mar 19 17:41:57 2016 Antoine Baché
** Last update Sun Mar 20 21:51:30 2016 Arthur ARNAUD
*/

#include "demo.h"
#include "tools/common.h"
#include "transition.h"

transFunc	selectorTransition(void)
{
  transFunc	array;

  if ((array = MALLOC(sizeof(int *) * NB_TRANSITION)) == NULL)
    return (NULL);
  array[0] = &transitionFade;
  array[1] = &transitionMorph;
  return (array);
}

closeEvent	selector(void)
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
  array[7] = &tunnelClose;
  array[8] = &samplerClose;
  array[9] = &texturedDegradClose;
  array[10] = &rotoClose;
  array[11] = &scrollingTextClose;
  array[12] = &matextClose;
  return (array);
}
