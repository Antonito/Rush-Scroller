/*
** common.h for gfx_scroller in /gfx_scroller/include/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 18 22:40:48 2016 Antoine Baché
** Last update Sat Mar 19 21:18:39 2016 Antoine Baché
*/

#ifndef	COMMON_H_
# define COMMON_H_
# define MALLOC(X)	my_malloc(X)

# include <stdlib.h>
# include <lapin.h>
# include "transform.h"

/*
** Maths macros
*/
# define RADIAN(X)	(((X) * M_PI) / 180)
# define DEGREE(X)	(((X) * 180) / M_PI)
# define POW2(X)	((X) * (X))
# define POW3(X)	(POW2(X) * (X))

# ifndef DEBUG
void			*my_malloc(size_t);
# else
#  undef MALLOC
#  define MALLOC(X)	my_malloc((X), __FILE__, __LINE__)

void			*my_malloc(size_t, const char *, int);
# endif /* !DEBUG */

void			my_free(void *);
void			free2DArray(void **);
void			tekpixel(t_bunny_pixelarray *, t_bunny_position *,
				 t_color *);
void			tekpixelTransp(t_bunny_pixelarray *,
				       t_bunny_position *,
				       t_color *, double);
void			clearColor(t_bunny_pixelarray *, unsigned int);
void			fillColor(t_bunny_pixelarray *, t_color *, double);
void			myBlit(const t_bunny_pixelarray *,
			       t_bunny_pixelarray *,
			       double,
			       t_ivec2);
unsigned int		getPixel(t_bunny_pixelarray *, t_ivec2);

#endif	/* !COMMON_H_ */
