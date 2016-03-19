#include "tools/transform.h"

t_vec2		addVec2(t_vec2 u, t_vec2 v)
{
  u.x += v.x;
  u.y += v.y;
  return (u);
}

t_vec3		addVec3(t_vec3 u, t_vec3 v)
{
  u.x += v.x;
  u.y += v.y;
  u.z += v.z;
  return (u);
}

t_vec2		subVec2(t_vec2 u, t_vec2 v)
{
  u.x -= v.x;
  u.y -= v.y;
  return (u);
}

t_vec3		subVec3(t_vec3 u, t_vec3 v)
{
  u.x -= v.x;
  u.y -= v.y;
  u.z -= v.z;
  return (u);
}
