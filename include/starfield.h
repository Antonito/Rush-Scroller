/*
** starfield.h for scroll in /gfx_scroller/src/starfield
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 18:29:09 2016 Ludovic Petrenko
** Last update Sat Mar 19 18:33:41 2016 Ludovic Petrenko
*/

#ifndef STARFIELD_H_
# define STARFIELD_H_

# include "tools/transform.h"

typedef struct	s_star
{
  t_ivec2	pos;
  t_ivec2	dir;
  struct s_star	*next;
}		t_star;

#endif /* !STARFIELD_H_ */
