#ifndef MAT_MATH_H
#define MAT_MATH_H

#include "math_inc.h"

// mat4 row goes down
//
// mat4[0]	  mat4[1]		  mat4[2]		  mat4[3]
// mat4[0][0]	mat4[1][0]	mat4[2][0]	mat4[3][0]
// mat4[0][1]	mat4[1][1]	mat4[2][1]	mat4[3][1]
// mat4[0][2]	mat4[1][2]	mat4[2][2]	mat4[3][2]
// mat4[0][3]	mat4[1][3]	mat4[2][3]	mat4[3][3]
typedef float mat4[4][4];

#define P_MAT4(m)	printf("%s:\n", #m);			\
			printf("%.2f, %.2f, %.2f, %.2f\n", 	\
			m[0][0], m[1][0], m[2][0], m[3][0]); 	\
			printf("%.2f, %.2f, %.2f, %.2f\n", 	\
			m[0][1], m[1][1], m[2][1], m[3][1]); 	\
			printf("%.2f, %.2f, %.2f, %.2f\n", 	\
			m[0][2], m[1][2], m[2][2], m[3][2]); 	\
			printf("%.2f, %.2f, %.2f, %.2f\n", 	\
			m[0][3], m[1][3], m[2][3], m[3][3])




M_INLINE void mat4_make_identity(mat4 m)
{
	vec4 r0 = { 1.0f, 0.0f, 0.0f, 0.0f };
	vec4 r1 = { 0.0f, 1.0f, 0.0f, 0.0f };
	vec4 r2 = { 0.0f, 0.0f, 1.0f, 0.0f };
	vec4 r3 = { 0.0f, 0.0f, 0.0f, 1.0f };

	vec4_copy(r0, m[0]);
	vec4_copy(r1, m[1]);
	vec4_copy(r2, m[2]);
	vec4_copy(r3, m[3]);
}

M_INLINE void mat4_make_zero(mat4 m)
{
	vec4 v0 = { 0.0f, 0.0f, 0.0f, 0.0f };

	vec4_copy(v0, m[0]);
	vec4_copy(v0, m[1]);
	vec4_copy(v0, m[2]);
	vec4_copy(v0, m[3]);
}

M_INLINE void mat4_set_pos(float x, float y, float z, mat4 dest)
{
  dest[3][0] = x;
  dest[3][1] = y;
  dest[3][2] = z;
}

M_INLINE void mat4_copy(mat4 m, mat4 dest)
{
  vec4_copy(m[0], dest[0]);
  vec4_copy(m[1], dest[1]);
  vec4_copy(m[2], dest[2]);
  vec4_copy(m[3], dest[3]);
}

M_INLINE void mat4_translate(mat4 m, vec3 dist)
{
	vec4 v1, v2, v3;
	
	vec4_mul_f(m[0], dist[0], v1);
	vec4_mul_f(m[1], dist[1], v2);
	vec4_mul_f(m[2], dist[2], v3);

	vec4_add(v1, m[3], m[3]);
	vec4_add(v2, m[3], m[3]);
	vec4_add(v3, m[3], m[3]);
}

M_INLINE void mat4_scale(mat4 m, vec3 scale, mat4 dest)
{
	vec4_mul_f(m[0], scale[0], dest[0]);
	vec4_mul_f(m[1], scale[1], dest[1]);
	vec4_mul_f(m[2], scale[2], dest[2]);

	vec4_copy(m[3], dest[3]);
}

M_INLINE void mat4_rotate_make(mat4 m, float angle, vec3 axis)
{
	// @NOTE: yoinked straight from cglm, look this up
	vec3 axisn, v, vs;
	float c = cosf(angle);

	vec3_normalize(axis, axisn);
	vec3_mul_f(axisn, 1.0f - c, v);
	vec3_mul_f(axisn, sinf(angle), vs);

	vec3_mul_f(axisn, v[0], m[0]);
	vec3_mul_f(axisn, v[1], m[1]);
	vec3_mul_f(axisn, v[2], m[2]);

	m[0][0] += c;       m[1][0] -= vs[2];   m[2][0] += vs[1];
	m[0][1] += vs[2];   m[1][1] += c;       m[2][1] -= vs[0];
	m[0][2] -= vs[1];   m[1][2] += vs[0];   m[2][2] += c;

	m[0][3] = m[1][3] = m[2][3] = m[3][0] = m[3][1] = m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

M_INLINE void mat4_mul_rot(mat4 m1, mat4 m2, mat4 dest)
{
	// @NOTE: yoinked straight from cglm, look this up
	float a00 = m1[0][0], a01 = m1[0][1], a02 = m1[0][2], a03 = m1[0][3];
	float a10 = m1[1][0], a11 = m1[1][1], a12 = m1[1][2], a13 = m1[1][3];
	float a20 = m1[2][0], a21 = m1[2][1], a22 = m1[2][2], a23 = m1[2][3];
	float a30 = m1[3][0], a31 = m1[3][1], a32 = m1[3][2], a33 = m1[3][3];

	float b00 = m2[0][0], b01 = m2[0][1], b02 = m2[0][2];
	float b10 = m2[1][0], b11 = m2[1][1], b12 = m2[1][2];
	float b20 = m2[2][0], b21 = m2[2][1], b22 = m2[2][2];

	dest[0][0] = a00 * b00 + a10 * b01 + a20 * b02;
	dest[0][1] = a01 * b00 + a11 * b01 + a21 * b02;
	dest[0][2] = a02 * b00 + a12 * b01 + a22 * b02;
	dest[0][3] = a03 * b00 + a13 * b01 + a23 * b02;

	dest[1][0] = a00 * b10 + a10 * b11 + a20 * b12;
	dest[1][1] = a01 * b10 + a11 * b11 + a21 * b12;
	dest[1][2] = a02 * b10 + a12 * b11 + a22 * b12;
	dest[1][3] = a03 * b10 + a13 * b11 + a23 * b12;

	dest[2][0] = a00 * b20 + a10 * b21 + a20 * b22;
	dest[2][1] = a01 * b20 + a11 * b21 + a21 * b22;
	dest[2][2] = a02 * b20 + a12 * b21 + a22 * b22;
	dest[2][3] = a03 * b20 + a13 * b21 + a23 * b22;

	dest[3][0] = a30;
	dest[3][1] = a31;
	dest[3][2] = a32;
	dest[3][3] = a33;
}

M_INLINE void mat4_rotate(mat4 m, float deg, vec3 axis)
{
	// @NOTE: yoinked straight from cglm, look this up
	mat4 r;
	mat4_rotate_make(r, deg, axis);
	mat4_mul_rot(m, r, m);
}

M_INLINE void mat4_rotate_at(mat4 m, vec3 point, float deg, vec3 axis)
{
	// @NOTE: yoinked straight from cglm, look this up
	vec3 p_inv;
	vec3_negate(point, p_inv);

	mat4_translate(m, point);
	mat4_rotate(m, deg, axis);
	mat4_translate(m, p_inv);
}

M_INLINE void mat4_lookat(vec3 pos, vec3 center, vec3 up, mat4 dest) 
{
	// @NOTE: yoinked straight from cglm, look this up
	vec3 f, u, s;

	vec3_sub(center, pos, f);
	vec3_normalize(f, f);

	vec3_cross(f, up, s);
	vec3_normalize(s, s);
	vec3_cross(s, f, u);

	dest[0][0] =  s[0];
	dest[0][1] =  u[0];
	dest[0][2] = -f[0];
	dest[1][0] =  s[1];
	dest[1][1] =  u[1];
	dest[1][2] = -f[1];
	dest[2][0] =  s[2];
	dest[2][1] =  u[2];
	dest[2][2] = -f[2];
	dest[3][0] = -vec3_dot(s, pos);
	dest[3][1] = -vec3_dot(u, pos);
	dest[3][2] =  vec3_dot(f, pos);
	dest[0][3] =  dest[1][3] = dest[2][3] = 0.0f;
	dest[3][3] =  1.0f;

}

// @TODO: remove all calcs not needed in 2d
// helper function, making it easier for 2d
M_INLINE void mat4_lookat_2d(vec2 pos, float zoom, mat4 dest)
{
	vec3 center;
	center[0] = pos[0];
	center[1] = pos[1];
	center[2] = -1.0f;

	mat4_lookat(VEC3_XYZ(pos[0], pos[1], -zoom), center, VEC3_Y(1), dest);
}

M_INLINE void mat4_perspective(float fovy, float aspect, float near_val, float far_val, mat4  dest) 
{
	// @NOTE: yoinked straight from cglm, look this up
	float f, fn;

  	mat4_make_zero(dest);

  	f  = 1.0f / tanf(fovy * 0.5f);
  	fn = 1.0f / (near_val - far_val);

  	dest[0][0] = f / aspect;
  	dest[1][1] = f;
  	dest[2][2] = (near_val + far_val) * fn;
  	dest[2][3] = -1.0f;
  	dest[3][2] = 2.0f * near_val * far_val * fn;
}

M_INLINE void mat4_ortho(float left, float right, float bottom,  float top, float nearVal, float farVal, mat4  dest) 
{
	// @NOTE: yoinked straight from cglm, look this up
  float rl, tb, fn;
  mat4_make_zero(dest);  
  rl = 1.0f / (right  - left);
  tb = 1.0f / (top    - bottom);   
  fn =-1.0f / (farVal - nearVal);
  dest[0][0] = 2.0f * rl;
  dest[1][1] = 2.0f * tb;
  dest[2][2] = 2.0f * fn;
  dest[3][0] =-(right  + left)    * rl;
  dest[3][1] =-(top    + bottom)  * tb;
  dest[3][2] = (farVal + nearVal) * fn;
  dest[3][3] = 1.0f; 
}


M_INLINE void mat4_make_model(vec3 pos, vec3 rot, vec3 scale, mat4 model)
{
	mat4_make_identity(model);
	float x = rot[0];  m_deg_to_rad(&x);
	float y = rot[1];  m_deg_to_rad(&y);
	float z = rot[2];  m_deg_to_rad(&z);
	
	mat4_rotate_at(model, pos, x, VEC3_X(1));
	mat4_rotate_at(model, pos, y, VEC3_Y(1));
	mat4_rotate_at(model, pos, z, VEC3_Z(1));
	
	mat4_translate(model, pos);

	mat4_scale(model, scale, model);
}

// helper function, removes calcs not needed or 2d
M_INLINE void mat4_make_model_2d(vec2 pos, vec2 size, float rot, mat4 model)
{
	vec3 pos3  = { pos[0], pos[1], 0.0f };
	vec3 size3 = { size[0], size[1], 1.0f };
	// mat4_make_model(model, pos3, rot3, size3);
	mat4_make_identity(model);
	m_deg_to_rad(&rot);
	
	mat4_rotate_at(model, pos3, rot, VEC3_Z(1));
	
	mat4_translate(model, pos3);

	mat4_scale(model, size3, model);
}


#endif

