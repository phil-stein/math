#ifndef MATH_INC_H
#define MATH_INC_H

// include all math related header files

// --------------------------------------------------------------------------------------------
//
// this whole math library is inspired by, and partially taken from, cglm, the c version of glm
// i mostly am writing this to brush up my math skills not to produce a proper math library
//
// --------------------------------------------------------------------------------------------


// static to avoid duplication when including header in multiple files 
// forced inline to always inline the functions
#define M_INLINE static inline __attribute((always_inline))


#include <math.h>
#include <inttypes.h>
#include "math_m.h"
#include "math_vec2.h"
#include "math_vec3.h"
#include "math_vec4.h"
#include "math_mat4.h"
#include "math_color.h"
#include "math_rand.h"

#endif

