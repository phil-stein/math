#ifndef RAND_MATH_H
#define RAND_MATH_H

#include "math_inc.h"
#include <stdlib.h>   // rand & srand


// #define P_U64(u)   printf("|%s| %llu\n", #u, u)
#define P_U64(u)   printf("|%s| %"PRId64"\n", #u, u)

// convert from degree to radians
M_INLINE void rand_seed(int seed)
{
	srand(seed);
}

M_INLINE int rand_int()
{
  return rand();
}
M_INLINE int rand_max()
{
  return RAND_MAX;
}

M_INLINE f32 rand_f32()
{
  return (f32)rand() / (f32)RAND_MAX;
}

M_INLINE uint64_t rand_u64()
{
  uint64_t g = 0;
  g += rand_int();
  g *= rand_int();
  g *= rand_int();
  g *= rand_int();
  g *= 2;
  return g;
}

#endif
