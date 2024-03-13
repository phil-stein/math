#ifndef MATH_RAND_MATH_H
#define MATH_RAND_MATH_H


#include "math_m.h"
#include <stdlib.h>   // rand & srand

#ifdef __cplusplus
extern "C" {
#endif


// @DOC: seed rand, call before other calls to rand
M_INLINE void rand_seed(unsigned int seed)
{
	srand(seed);
}
M_INLINE int rand_max()
{
  return RAND_MAX;
}

M_INLINE int rand_int()
{
  return rand();
}
M_INLINE float rand_f32()
{
  return (float)rand() / (float)RAND_MAX;
}
#define rand_float()  rand_f32()

M_INLINE int rand_int_range(int min, int max)
{
  return (int)(rand_f32() * (float)(max - min)) + min;
}

M_INLINE bool rand_bool()
{
  return rand_int_range(0, 2) == 1;
}


M_INLINE uint64_t rand_u64()
{
  uint64_t g = 0;
  g += (uint64_t)rand_int();
  g *= (uint64_t)rand_int();
  g *= (uint64_t)rand_int();
  g *= (uint64_t)rand_int();
  g *= 2;
  return g;
}

#ifdef __cplusplus
} // extern C
#endif

#endif
