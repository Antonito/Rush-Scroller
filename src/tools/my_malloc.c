/*
** my_malloc.c for gfx_scroller in /gfx_scroller/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 18 22:03:41 2016 Antoine Baché
** Last update Fri Mar 18 22:09:14 2016 Antoine Baché
*/

#include <stdio.h>
#include <lapin.h>

#ifdef	DEBUG
void	*my_malloc(size_t size, int line)
{
  void	*elem;

  if (!(elem = bunny_malloc(size)))
    {
      dprintf(2, "Malloc failed : line %d\n", line);
      return (NULL);
    }
  return (elem);
}
#else
void	*my_malloc(size_t size)
{
  return (bunny_malloc(size));
}
#endif
