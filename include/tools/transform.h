/*
** transform.h for scroll in /gfx_scroller/include/tools
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Sat Mar 19 02:25:35 2016 Ludovic Petrenko
** Last update Sat Mar 19 15:31:33 2016 Ludovic Petrenko
*/

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

/*
** Constructors
*/

t_vec2		vec2(double, double);
t_vec3		vec3(double, double, double);
t_vec4		vec4(double, double, double, double);
t_ivec2		ivec2(int, int);
t_mat2		mat2(void);
t_mat3		mat3(void);
t_mat4		mat4(void);

/*
** Basic vector operation (add, sub, mult, div)
*/

t_vec2		addVec2(t_vec2, t_vec2);
t_vec3		addVec3(t_vec3, t_vec3);
t_vec4		addVec4(t_vec4, t_vec4);
t_ivec2		addiVec2(t_ivec2, t_ivec2);

t_vec2		subVec2(t_vec2, t_vec2);
t_vec3		subVec3(t_vec3, t_vec3);
t_vec4		subVec4(t_vec4, t_vec4);
t_ivec2		subiVec2(t_ivec2, t_ivec2);

t_vec2		multVec2(t_vec2, double);
t_vec3		multVec3(t_vec3, double);
t_vec4		multVec4(t_vec4, double);

t_vec2		divVec2(t_vec2, double);
t_vec3		divVec3(t_vec3, double);
t_vec4		divVec4(t_vec4, double);

/*
** Vectorial operation
*/

double		dotVec2(t_vec2, t_vec2);
double		dotVec3(t_vec3, t_vec3);
double		dotVec4(t_vec4, t_vec4);

t_vec3		cross(t_vec3, t_vec3);

double		vec2Len(t_vec2);
double		vec3Len(t_vec3);
double		vec4Len(t_vec4);

t_vec2		vec2Normalize(t_vec2 v);
t_vec3		vec3Normalize(t_vec3 v);
t_vec4		vec4Normalize(t_vec4 v);

/*
** Matrix * Matrix and Matrix * Vector
** (for multMat[2/3/4] 2nd parameter become the result)
*/

void		multMat2(t_mat2 *, t_mat2 *);
void		multMat3(t_mat3 *, t_mat3 *);
void		multMat4(t_mat4 *, t_mat4 *);

t_vec2		multMatVec2(t_mat2 *, t_vec2);
t_vec3		multMatVec3(t_mat3 *, t_vec3);
t_vec4		multMatVec4(t_mat4 *, t_vec4);

/*
** Transformation applyed on matrix
*/

void		translate(t_mat4 *, t_vec3);

void		rotate2D(t_mat2 *m, double deg);
void		rotate3D(t_mat3 *m, t_vec3 deg);
void		rotate4D(t_mat4 *m, t_vec3 deg);

void		scale2D(t_mat2 *m, t_vec2 deg);
void		scale3D(t_mat3 *m, t_vec3 deg);
void		scale4D(t_mat4 *m, t_vec3 deg);

/*
** 3D special
*/

t_mat4		perspective(double, double, double, double);

/*
** Cast
*/

t_ivec2		to_ivec2(t_vec2);
t_vec2		to_vec2(t_ivec2);
t_vec4		to_vec4(t_vec3, double);
t_mat4		to_mat4(t_mat3);

#endif /* !TRANSFORM_H_ */
