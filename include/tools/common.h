/*
** common.h for gfx_scroller in /gfx_scroller/include/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 18 22:40:48 2016 Antoine Baché
** Last update Fri Mar 18 23:14:40 2016 Antoine Baché
*/

#ifndef	COMMON_H_
# define COMMON_H_
# define MALLOC(X)	my_malloc(X)

/*
** Maths macros
*/
# define POW2(X)	((X) * (X))
# define POW3(X)	(POW2(X) * (X))

# include <stdlib.h>

# ifndef DEBUG
void	*my_malloc(size_t);
# else
#  undef MALLOC
#  define MALLOC(X)	my_malloc((X), __FILE__, __LINE__)

void	*my_malloc(size_t, const char *, int);
# endif /* !DEBUG */

void	my_free(void *);

#endif	/* !COMMON_H_ */
