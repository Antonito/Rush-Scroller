#include "tools/transform.h"

t_vec2		normalizeVec2(t_vec2 v)
{
  double	len;

  len = vec2Len(v);
  if (v == 0.0)
    return (vec2(0, 0));
  v.x /= len;
  v.y /= len;
  return (v);
}

t_vec3		normalizeVec2(t_vec3 v)
{
  double	len;

  len = vec3Len(v);
  if (v == 0.0)
    return (vec3(0, 0));
  v.x /= len;
  v.y /= len;
  v.z /= len;
  return (v);
}

t_vec4		normalizeVec4(t_vec4 v)
{
  double	len;

  len = vec4Len(v);
  if (v == 0.0)
    return (vec4(0, 0, 0, v.w));
  v.x /= len;
  v.y /= len;
  v.z /= len;
  return (v);
}
