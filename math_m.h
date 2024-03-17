#ifndef MATH_MATH_M_H
#define MATH_MATH_M_H

#include <stdio.h>
#include <stdbool.h>
// #include "math_inc.h"
#include <math.h>
#include <inttypes.h>
#include <float.h>

#ifdef __cplusplus
extern "C" {
#endif

// static to avoid duplication when including header in multiple files 
// forced inline to always inline the functions
// #define M_INLINE static inline __attribute((always_inline))
#if defined(_MSC_VER)
#define M_INLINE __forceinline
#else
#define M_INLINE static inline __attribute((always_inline))
#endif



#ifndef M_PI
  #define M_PI 	3.14159265358979323846264338327950288
#endif
#ifndef M_PI_F
  #define M_PI_F	(float)M_PI
#endif

// if less than b than b else a
#define MIN(a, b)	    ((a) < (b) ? (a) : (b))
#define MIN3(a, b, c) MIN(a, MIN(b, c))
// #define MIN3(a, b, c)	((a) < (b) ? (a) < (c) ? (a) : (c) : (b))

// if more than b than b else a
#define MAX(a, b)	    ((a) > (b) ? (a) : (b))
// #define MAX3(a, b, c)	((a) > (b) ? (a) > (c) ? (a) : (c) : (b))
#define MAX3(a, b, c) MAX(a, MAX(b, c))

// if less than min, min, if more than max, else a
#define CLAMP(a, _min, _max)	MAX(_min, MIN(_max, a))
// #define CLAMP(a, _min, _max)	MIN(_min, MAX(_max, a))

#define INT_ABS(v)      abs(v)
#define FLOAT_ABS(v)    fabsf(v)
#define DOUBLE_ABS(v)   absf(v)
#define INT_SQRT(v)     sqrtl(v)
#define FLOAT_SQRT(v)   sqrtf(v)
#define DOUBLE_SQRT(v)  sqrt(v)
#define F32_ABS(v)      FLOAT_ABS(v)
#define F64_ABS(v)      DOUBLE_ABS(v)
#define F32_SQRT(v)     FLOAT_SQRT(v)
#define F64_SQRT(v)     DOUBLE_SQRT(v)

// floating point equal, cant use ==
// because floating-point in-precision may cause errror
#define FLOAT_EQUAL(a, b)   ( fabsf( ((float)(a))  - ((float)(b)) )  < ((float)(FLT_EPSILON)  + 0.000001f) )
#define DOUBLE_EQUAL(a, b)  ( fabs( ((double)(a)) - ((double)(b)) ) < ((double)(DBL_EPSILON) + 0.00000000001) )
#define FLOAT_EQ(a, b)      FLOAT_EQUAL(a, b)
#define DOUBLE_EQ(a, b)     DOUBLE_EQUAL(a, b)
#define F32_EQUAL(a, b)     FLOAT_EQUAL(a, b)
#define F64_EQUAL(a, b)     DOUBLE_EQUAL(a, b)
#define F32_EQ(a, b)        FLOAT_EQUAL(a, b)
#define F64_EQ(a, b)        DOUBLE_EQUAL(a, b)

// taken from nuklear.h NK_BETWEEN() & NK_INBOX()
#define POINT_BETWEEN(x, a, b) ((a) <= (x) && (x) < (b))
// taken from nuklear.h NK_BETWEEN() & NK_INBOX()
// @DOC: check if point is in rect
//        ____w___
//       |       |h
//       |   pxy |
//       x,y------
#define POINT_IN_RECT(px, py, x, y, w, h) (POINT_BETWEEN(px,x,x+w) && POINT_BETWEEN(py,y,y+h))

#define DEG_TO_RAD(_deg)	((_deg) * M_PI_F / 180.0f)
#define RAD_TO_DEG(_rad)	((_rad) * 180.0f / M_PI_F)

// @DOC: convert from degree to radians
M_INLINE void m_deg_to_rad(float* deg)
{
	*deg = *deg * M_PI_F / 180.0f;
}

// @DOC: convert from radians to degree
M_INLINE void m_rad_to_deg(float* rad)
{
	*rad = *rad * 180.0f / M_PI_F;
}

// taken from: http://www.corykoseck.com/2018/08/29/programming-in-c-lerp/
// @DOC: linear interpolation, float between start and end, given percentage
M_INLINE float m_lerp(float start, float end, float percentage)
{
  // return CLAMP(start + percentage * (end - start), start, end);
  // percentage = CLAMP(percentage, 0.0f, 1.0f);
  return (start + percentage * (end - start));
}
M_INLINE float m_ease_in_quadratic(float start, float end, float percentage)
{
  return m_lerp(start, end, (percentage * percentage)); 
}
M_INLINE float m_ease_in_cubic(float start, float end, float percentage)
{
  return m_lerp(start, end, (percentage * percentage * percentage)); 
}
// M_INLINE float m_ease_out(float start, float end, float percentage)
// {
//   return m_lerp(start, end, (percentage + (1.2f-percentage))); 
// }
// M_INLINE float m_ease_out_quadratic(float start, float end, float percentage)
// {
//   return m_lerp(start, end, (percentage + ((1.2f-percentage) *2) )); 
// }
// M_INLINE float m_ease_out_cubic(float start, float end, float percentage)
// {
//   return m_lerp(start, end, (percentage + ((1.2f-percentage) *3) )); 
// }

#ifdef __cplusplus
} // extern C
#endif

#endif
