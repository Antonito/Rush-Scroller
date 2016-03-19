/*
** my_free.c for gfx_scroller in /gfx_scroller/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 18 23:13:30 2016 Antoine Baché
** Last update Sat Mar 19 20:09:04 2016 Arthur ARNAUD
*/

#include <stdlib.h>
#include <lapin.h>

void	my_free(void *ptr)
{
  free(ptr);
}
