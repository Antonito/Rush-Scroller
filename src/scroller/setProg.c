/*
** setProg.c for setProg in /home/arnaud_e/rendu/info/gfx_scroller/src/scroller
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun Mar 20 02:05:57 2016 Arthur ARNAUD
** Last update Sun Mar 20 04:02:33 2016 Arthur ARNAUD
*/

#include "scroller.h"
#include "tools/common.h"

void	setProg(t_prog *prog)
{
  prog->sky_pos.x = 0;
  prog->sky_pos.y = 100;
  prog->mountain_pos.x = 0;
  prog->mountain_pos.y = 370;
  prog->grass_pos.x = 0;
  prog->grass_pos.y = 950;
  prog->bunny_pos.x = 0;
  prog->bunny_pos.y = 920;
  clearColor(prog->bigSky, 0xFFE68A00);
  clearColor(prog->bigMountain, 0xFFE68A00);
  clearColor(prog->bigGrass, 0xFFE68A00);
  drawResized(prog->sky, prog->bigSky, vec2(2, 2), ivec2(0, 0));
  drawResized(prog->mountain, prog->bigMountain, vec2(2, 2), ivec2(0, 0));
  drawResized(prog->grass, prog->bigGrass, vec2(3, 3), ivec2(0, 0));
  drawResized(prog->bunny, prog->bigBunny, vec2(2, 2), ivec2(0, 0));
}
