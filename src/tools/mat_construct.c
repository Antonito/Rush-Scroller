#include <string.h>
#include "tools/transform.h"

t_mat2		mat2()
{
  t_mat2	new;

  memset(&new, 0.0, sizeof(t_mat2));
  new.m00 = 1.0;
  new.m11 = 1.0;
  return (new);
}

t_mat3		mat3()
{
  t_mat3	new;

  memset(&new, 0.0, sizeof(t_mat3));
  new.m00 = 1.0;
  new.m11 = 1.0;
  new.m22 = 1.0;
  return (new);
}

t_mat4		mat4()
{
  t_mat4	new;

  memset(&new, 0.0, sizeof(t_mat4));
  new.m00 = 1.0;
  new.m11 = 1.0;
  new.m22 = 1.0;
  new.m33 = 1.0;
  return (new);
}
