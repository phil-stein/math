#ifndef M_MATH_H
#define M_MATH_H

#include "math_inc.h"

#ifndef M_PI
	#define M_PI 	3.14159265358979323846264338327950288
#endif
#ifndef M_PI_F
	#define M_PI_F	(float)M_PI
#endif

// if less than b than b else a
#ifndef MIN
	#define MIN(a, b)	((a) < (b) ? (a) : (b))
#endif

// if more than b than b else a
#ifndef MAX
	#define MAX(a, b)	((a) > (b) ? (a) : (b))
#endif

// if less than min, min, if more than max, else a
#ifndef CLAMP
	#define CLAMP(a, _min, _max)	MAX(_min, MIN(_max, a))
#endif

#define INT_ABS(v)      abs(v)
#define FLOAT_ABS(v)    fabsf(v)
#define DOUBLE_ABS(v)   absf(v)
#define INT_SQRT(v)     sqrtl(v)
#define FLOAT_SQRT(v)   sqrtf(v)
#define DOUBLE_SQRT(v)  sqrt(v)
#define F32_ABS(v)      FLOAT_ABS(v)
#define F64_ABS(v)      DOUBLE_ABS(v)
#define F32_SQRT        FLOAT_SQRT
#define F64_SQRT        DOUBLE_SQRT

// convert from degree to radians
M_INLINE void m_deg_to_rad(float* deg)
{
	*deg = *deg * M_PI_F / 180.0f;
}

// convert from radians to degree
M_INLINE void m_rad_to_deg(float* rad)
{
	*rad = *rad * 180.0f / M_PI_F;
}

#endif
