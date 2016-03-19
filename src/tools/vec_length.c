#include <math.h>
#include "tools/common.h"
#include "tools/transform.h"

double	vec2Len(t_vec2 v)
{
  return (sqrt(POW2(v.x) + POW2(v.y)));
}

double	vec3Len(t_vec3 v)
{
  return (sqrt(POW2(v.x) + POW2(v.y) + POW2(v.z)));
}

double	vec4Len(t_vec4 v)
{
  return (sqrt(POW2(v.x) + POW2(v.y) + POW2(v.z)));
}
