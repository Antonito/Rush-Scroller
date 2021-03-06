/*
** my_malloc.c for gfx_scroller in /gfx_scroller/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 18 22:03:41 2016 Antoine Baché
** Last update Sun Mar 20 12:09:12 2016 Antoine Baché
*/

#include <stdio.h>
#include <unistd.h>
#include <lapin.h>

#ifdef	DEBUG
void	*my_malloc(size_t size, const char *file, int line)
{
  void	*elem;

  if (!(elem = bunny_malloc(size)))
    {
      dprintf(2, "Malloc failed %s : line %d\n", file, line);
      return (NULL);
    }
  return (elem);
}
#else
void	*my_malloc(size_t size)
{
  void	*elem;

  if (!(elem = bunny_malloc(size)))
    {
      write(2, "Memory allocation failed\n", 25);
      return (NULL);
    }
  return (elem);
}
#endif
