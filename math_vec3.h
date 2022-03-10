#ifndef VEC3_MATH_H
#define VEC3_MATH_H

#include "math_inc.h"

typedef float	vec3[3];	// v[0]: x, v[1]: y, v[2]: z
typedef int ivec3[3];   // v[0]: x, v[1]: y, v[2]: z

// ---- vec3 creation ----

#define VEC3_INIT(f)		      { f, f, f }
#define VEC3_XYZ_INIT(x, y, z)	      { x, y, z }
#define VEC3_X_INIT(x)		      { x, 0, 0 }
#define VEC3_Y_INIT(y)		      { 0, y, 0 }
#define VEC3_Z_INIT(z)		      { 0, 0, z }

#define VEC3(f)			(vec3){ f, f, f }
#define VEC3_XYZ(x, y, z)	(vec3){ x, y, z }
#define VEC3_X(x)		(vec3){ x, 0, 0 }
#define VEC3_Y(y)		(vec3){ 0, y, 0 }
#define VEC3_Z(z)		(vec3){ 0, 0, z }


#define P_VEC3(v) 	  printf("|%s| x: %.2f, y: %.2f, z: %.2f\n", #v, v[0], v[1], v[2])
#define P_IL_VEC3(v) 	printf("|%s| x: %.2f, y: %.2f, z: %.2f", #v, v[0], v[1], v[2])


// ---- vec3 ----

M_INLINE void vec3_add(vec3 a, vec3 b, vec3 out)
{
	out[0] = a[0] + b[0];
	out[1] = a[1] + b[1];
	out[2] = a[2] + b[2];
}
M_INLINE void vec3_add_f(vec3 a, float f, vec3 out)
{
	out[0] = a[0] + f;
	out[1] = a[1] + f;
	out[2] = a[2] + f;
}

M_INLINE void vec3_sub(vec3 a, vec3 b, vec3 out)
{
	out[0] = a[0] - b[0];
	out[1] = a[1] - b[1];
	out[2] = a[2] - b[2];
}
M_INLINE void vec3_sub_f(vec3 a, float f, vec3 out)
{
	out[0] = a[0] - f;
	out[1] = a[1] - f;
	out[2] = a[2] - f;
}

M_INLINE void vec3_mul(vec3 a, vec3 b, vec3 out)
{
	out[0] = a[0] * b[0];
	out[1] = a[1] * b[1];
	out[2] = a[2] * b[2];
}
M_INLINE void vec3_mul_f(vec3 a, float f, vec3 out)
{
	out[0] = a[0] * f;
	out[1] = a[1] * f;
	out[2] = a[2] * f;
}

M_INLINE void vec3_div(vec3 a, vec3 b, vec3 out)
{
	out[0] = a[0] / b[0];
	out[1] = a[1] / b[1];
	out[2] = a[2] / b[2];
}
M_INLINE void vec3_div_f(vec3 a, float f, vec3 out)
{
	out[0] = a[0] / f;
	out[1] = a[1] / f;
	out[2] = a[2] / f;
}

M_INLINE void vec3_cross(vec3 a, vec3 b, vec3 out)
{
	out[0] = a[1] * b[2] - a[2] * b[1];
	out[1] = a[2] * b[0] - a[0] * b[2];
	out[2] = a[0] * b[1] - a[1] * b[0];
}

M_INLINE float vec3_dot(vec3 a, vec3 b)
{
	return (a[0] * b[0]) + (a[1] * b[1]) + (a[2] * b[2]);
}

M_INLINE float vec3_magnitude(vec3 a)
{
	return sqrtf((a[0] * a[0]) + (a[1] * a[1]) + (a[2] * a[2]));
}

M_INLINE void vec3_copy(vec3 a, vec3 out)
{
	out[0] = a[0];
	out[1] = a[1];
	out[2] = a[2];
}

M_INLINE void vec3_negate(vec3 a, vec3 out)
{
	out[0] = -a[0];
	out[1] = -a[1];
	out[2] = -a[2];
}

M_INLINE void vec3_normalize(vec3 a, vec3 out)
{
	vec3_copy(a, out);
	float mag = vec3_magnitude(out);
	vec3_div_f(out, mag, out);
}

M_INLINE float vec3_distance(vec3 a, vec3 b)
{
	vec3 d;
	vec3_sub(a, b, d);
	return vec3_magnitude(d); 
}

M_INLINE void vec3_clamp(vec3 a, vec3 min, vec3 max, vec3 out)
{
	out[0] = CLAMP(a[0], min[0], max[0]);
	out[1] = CLAMP(a[1], min[1], max[1]);
	out[2] = CLAMP(a[2], min[2], max[2]);
}

M_INLINE void vec3_clamp_f(vec3 a, float min, float max, vec3 out)
{
	out[0] = CLAMP(a[0], min, max);
	out[1] = CLAMP(a[1], min, max);
	out[2] = CLAMP(a[2], min, max);
}

M_INLINE void vec3_abs(vec3 a, vec3 out)
{
	out[0] = fabsf(a[0]);
	out[1] = fabsf(a[1]);
	out[2] = fabsf(a[2]);
}


// ---- conditionals ----

M_INLINE bool vec3_equal(vec3 a, vec3 b)
{
  return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}
M_INLINE bool vec3_not_equal(vec3 a, vec3 b)
{
  return !vec3_equal(a, b);
}
M_INLINE bool vec3_greater(vec3 a, vec3 b)
{
  return a[0] > b[0] && a[1] > b[1] && a[2] > b[2];
}
M_INLINE bool vec3_less(vec3 a, vec3 b)
{
  return a[0] < b[0] && a[1] < b[1] && a[2] < b[2];
}
M_INLINE bool vec3_greater_eq(vec3 a, vec3 b)
{
  return a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2];
}
M_INLINE bool vec3_less_eq(vec3 a, vec3 b)
{
  return a[0] <= b[0] && a[1] <= b[1] && a[2] >= b[2];
}

#endif
