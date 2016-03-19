#ifndef TRANSFORM_H_
# define TRANSFORM_H_

# include <lapin.h>

typedef struct	s_vec2
{
  double	x;
  double	y;
}		t_vec2;

typedef struct	s_vec3
{
  double	x;
  double	y;
  double	z;
}		t_vec3;

typedef struct	s_vec4
{
  double	x;
  double	y;
  double	z;
  double	w;
}		t_vec4;

typedef t_bunny_position t_ivec2;

typedef struct	s_mat2
{
  double	m00;
  double	m01;
  double	m10;
  double	m11;
}		t_mat2;

typedef struct	s_mat3
{
  double	m00;
  double	m01;
  double	m02;
  double	m10;
  double	m11;
  double	m12;
  double	m20;
  double	m21;
  double	m22;
}		t_mat3;

typedef struct	s_mat4
{
  double	m00;
  double	m01;
  double	m02;
  double	m03;
  double	m10;
  double	m11;
  double	m12;
  double	m13;
  double	m20;
  double	m21;
  double	m22;
  double	m23;
  double	m30;
  double	m31;
  double	m32;
  double	m33;
}		t_mat4;

#endif /* !TRANSFORM_H_ */
