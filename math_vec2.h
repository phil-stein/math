#ifndef VEC2_MATH_H
#define VEC2_MATH_H

#include "math_inc.h"

typedef float	vec2[2]; 	// v[0]: x, v[1]: y
typedef int ivec2[2];   // v[0]: x, v[1]: y

// ---- vec2 creation ----

#define VEC2_INIT(f)		{ f, f }
#define VEC2_XY_INIT(x, y) 	{ x, y }
#define VEC2_X_INIT(x)		{ x, 0 }
#define VEC2_Y_INIT(y)		{ 0, y }

#define VEC2(f)			(vec2){ f, f }
#define VEC2_XY(x, y) 		(vec2){ x, y }
#define VEC2_X(x)		(vec2){ x, 0 }
#define VEC2_Y(y)		(vec2){ 0, y }


// ---- print util ----
#define P_VEC2(v) 	  printf("|%s| x: %.2f, y: %.2f\n", #v, v[0], v[1])
#define P_IL_VEC2(v) 	printf("|%s| x: %.2f, y: %.2f", #v, v[0], v[1])


// static to avoid duplication when including header in multiple files 
// forced inline to always inline the functions
// #define VEC2_INLINE static inline __attribute((always_inline))


// ---- vec2 ----


M_INLINE void vec2_add(vec2 a, vec2 b, vec2 dest)
{
	dest[0] = a[0] + b[0];
	dest[1] = a[1] + b[1];
}
M_INLINE void vec2_add_f(vec2 a, float f, vec2 dest)
{
	dest[0] = a[0] + f;
	dest[1] = a[1] + f;
}

M_INLINE void vec2_sub(vec2 a, vec2 b, vec2 dest)
{
	dest[0] = a[0] - b[0];
	dest[1] = a[1] - b[1];
}
M_INLINE void vec2_sub_f(vec2 a, float f, vec2 dest)
{
	dest[0] = a[0] - f;
	dest[1] = a[1] - f;
}

M_INLINE void vec2_mul(vec2 a, vec2 b, vec2 dest)
{
	dest[0] = a[0] * b[0];
	dest[1] = a[1] * b[1];
}
M_INLINE void vec2_mul_f(vec2 a, float f, vec2 dest)
{
	dest[0] = a[0] * f;
	dest[1] = a[1] * f;
}

M_INLINE void vec2_div(vec2 a, vec2 b, vec2 dest)
{
	dest[0] = a[0] / b[0];
	dest[1] = a[1] / b[1];
}
M_INLINE void vec2_div_f(vec2 a, float f, vec2 dest)
{
	dest[0] = a[0] / f;
	dest[1] = a[1] / f;
}

M_INLINE float vec2_dot(vec2 a, vec2 b)
{
	return (a[0] * b[0]) + (a[1] * b[1]);
}

M_INLINE float vec2_magnitude(vec2 a)
{
	return sqrtf((a[0] * a[0]) + (a[1] * a[1]));
}

M_INLINE void vec2_copy(vec2 a, vec2 dest)
{
	dest[0] = a[0]; 
	dest[1] = a[1];
}
M_INLINE void vec2_copy_f(float f, vec2 dest)
{
	dest[0] = f; 
	dest[1] = f;
}

M_INLINE void vec2_negate(vec2 a, vec2 dest)
{
	dest[0] = -a[0]; 
	dest[1] = -a[1];
}

M_INLINE void vec2_normalize(vec2 a, vec2 dest)
{
	vec2_copy(a, dest);
	float mag = vec2_magnitude(dest);
	vec2_div_f(dest, mag, dest);
}

M_INLINE float vec2_distance(vec2 a, vec2 b)
{
	vec2 d;
	vec2_sub(a, b, d);
	return vec2_magnitude(d); 
}

M_INLINE void vec2_clamp(vec2 a, vec2 min, vec2 max, vec2 dest)
{
	dest[0] = CLAMP(a[0], min[0], max[0]);
	dest[1] = CLAMP(a[1], min[1], max[1]);
}

M_INLINE void vec2_clamp_f(vec2 a, float min, float max, vec2 dest)
{
	dest[0] = CLAMP(a[0], min, max);
	dest[1] = CLAMP(a[1], min, max);
}

M_INLINE void vec2_abs(vec2 a, vec2 dest)
{
	dest[0] = fabsf(a[0]);
	dest[1] = fabsf(a[1]);
}


// ---- conditionals ----

M_INLINE bool vec2_equal(vec2 a, vec2 b)
{
  return a[0] == b[0] && a[1] == b[1];
}
M_INLINE bool vec2_not_equal(vec2 a, vec2 b)
{
  return !vec2_equal(a, b);
}
M_INLINE bool vec2_greater(vec2 a, vec2 b)
{
  return a[0] > b[0] && a[1] > b[1];
}
M_INLINE bool vec2_less(vec2 a, vec2 b)
{
  return a[0] < b[0] && a[1] < b[1];
}
M_INLINE bool vec2_greater_eq(vec2 a, vec2 b)
{
  return a[0] >= b[0] && a[1] >= b[1];
}
M_INLINE bool vec2_less_eq(vec2 a, vec2 b)
{
  return a[0] <= b[0] && a[1] <= b[1];
}

#endif
