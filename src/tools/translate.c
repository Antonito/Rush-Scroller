#include "tools/transform.h"

void	translate(t_mat4 *mat, t_vec3 t)
{
  mat->m03 += t.x;
  mat->m13 += t.y;
  mat->m23 += t.z;
}
