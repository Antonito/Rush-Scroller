/*
** main.c for gfx_scroller in /gfx_scroller/src/demo1
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Fri Mar 18 19:40:34 2016 Antoine Baché
** Last update Fri Mar 18 21:05:26 2016 Antoine Baché
*/

int	main(int ac, char **av, char **env)
{
  if (!*env)
    {
#ifdef	DEBUG
      write(1, "Status: KO\n", 11);
#endif
      return (1);
    }
#ifdef	DEBUG
  write(1, "Status: OK\n", 11);
#endif
  return (0);
}
