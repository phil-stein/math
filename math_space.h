#ifndef M_SPACE_H
#define M_SPACE_H

// #include "math_inc.h"
#include "math_mat4.h"
#include "math_vec4.h"
#include "math_vec3.h"

// @UNSURE: dont know if this works 
// project from screen-space to world-space
// pos:  object pos
// m:    object mvp
// vp:   screen [x, y, w, h]
// out:  output
M_INLINE void space_screen_to_world(vec3 pos, mat4 m, vec4 vp, vec3 out) 
{ 
  // taken from glm_project_zo()
  // CGLM_ALIGN(16) 
  // vec4 pos4 = { pos[0], pos[1], pos[2], 1.0f };

  // mat4_mul_v(m, pos4, pos4);
  // vec4_mul_f(pos4, 1.0f / pos4[3], pos4); /* pos = pos / pos.w */

  // out[2] = pos4[2];

  // vec4_mul_f(pos4, 0.5f, pos4);
  // vec4_add_f(pos4,  0.5f, pos4);

  // out[0] = pos4[0] * vp[2] + vp[0];
  // out[1] = pos4[1] * vp[3] + vp[1];

  
  // taken from glm_project_no()
  vec4 pos4 = { pos[0], pos[1], pos[2], 1.0f };

  mat4_mul_v(m, pos4, pos4);
  vec4_mul_f(pos4, 1.0f / pos4[3], pos4); /* pos = pos / pos.w */
  vec4_mul_f(pos4, 0.5f, pos4);
  vec4_add_f(pos4,  0.5f, pos4);

  out[0] = pos4[0] * vp[2] + vp[0];
  out[1] = pos4[1] * vp[3] + vp[1];
  out[2] = pos4[2];
  P_VEC3(out);
}

#endif
