#ifndef MATH_MATH_SPACE_Hspace
#define MATH_MATM_SPACE_H

#include "global/global_print.h"
#include "math/math_mat4.h"
#ifdef __cplusplus
extern "C"
{
#endif


#include "math_inc.h"

// @DOC: project screen coordinates into world space
//       view:           view matrix
//       proj:           projection matrix
//       pos_normalized:
//                       x: mouse-pos.x range -1 to 1
//                       y: mouse-pos.y range -1 to 1
//       depth:          dist range -1 to 1, between near & far plane
//       out:            gets set to world pos 
#define space_screen_to_world(view, proj, pos_normalized, depth, out) space_screen_to_world_dbg(view, proj, pos_normalized, depth, out, __FILE__, __func__, __LINE__) 
M_INLINE void space_screen_to_world_dbg(mat4 view, mat4 proj, vec2 pos_normalized, float depth, vec3 out, const char* _file, const char* _func, int _line) 
{  
  // taken from: https://stackoverflow.com/questions/7692988/opengl-math-projecting-screen-space-to-world-space-coords
  // 1. get mouse-pos, view & proj mat
  // 2. multiply view & proj
  // 3. inverse view_proj
  // 4. get depth (dist ?)
  // 5. vec4: 
  //    x: mouse-pos.x range -1 - 1
  //    y: mouse-pos.y range -1 - 1
  //    z: depth       range -1 - 1
  //    w: 1.0
  // 6. multiply vec & inv_view_proj
  // 7. divide pos.xyz by pos.w
  //    pos.w /= 1; pos.xyz *= pos.w;
  
  printf( "space_screen_to_world: %s %s %d\n", _file, _func, _line );

  mat4 inv_v_p;
  mat4_mul(proj, view, inv_v_p);        // @UNSURE: about order
  mat4_inverse(inv_v_p, inv_v_p);

  vec4 pos = 
  {
    pos_normalized[0],
    pos_normalized[1],
    depth,
    1.0
  };

  mat4_mul_v(inv_v_p, pos, pos);

  // doesn't actually work
  // pos[3] = 1.0f / pos[3];
  // pos[0] *= pos[3];
  // pos[1] *= pos[3];
  // pos[2] *= pos[3];
  // or  
  // pos[0] /= pos[3];
  // pos[1] /= pos[3];
  // pos[2] /= pos[3];
  vec3_copy(pos, out);
}
M_INLINE void space_world_to_screen(vec3 pos, mat4 view, mat4 proj, vec2 out)
{
  // taken from: https://gamedev.stackexchange.com/questions/35263/converting-world-space-coordinate-to-screen-space-coordinate-and-getting-incorre
  // Vector4 objectPos4 = new Vector4( object.WorldPosition, 1.0f );
  // Vector4 postProjectivePosition = Vector4.Transform(objectPos4, camera.ViewProjectionMatrix);
  // Float clipSpaceX = postProjectivePosition.X / postProjectivePosition.W;
  // Float clipSpaceY = postProjectivePosition.Y / postProjectivePosition.W;
  
  ERR("doesnt work i think");
  vec4 pos4 = { pos[0], pos[1], pos[2], 1.0f };
  mat4 view_proj;
  mat4_mul(view, proj, view_proj);
  mat4_mul_v(view_proj, pos4, pos4);
  out[0] = pos4[0] / pos4[3];
  out[1] = pos4[1] / pos4[3];
}

// M_INLINE void space_screen_to_model(mat4 model, mat4 view, mat4 proj, vec2 pos_normalized, float depth, vec3 out) 
// {   
//   // 1. get mouse-pos, view & proj mat
//   // 2. multiply view & proj
//   // 3. inverse view_proj
//   // 4. get depth (dist ?)
//   // 5. vec4: 
//   //    x: mouse-pos.x range -1 - 1
//   //    y: mouse-pos.y range -1 - 1
//   //    z: depth       range -1 - 1
//   //    w: 1.0
//   // 6. multiply vec & inv_view_proj
//   // 7. divide pos.xyz by pos.w
//   //    pos.w /= 1; pos.xyz *= pos.w;
// 
//   mat4 inv_model;
//   mat4_inverse(model, inv_model);
// 
//   space_screen_to_world(view, proj, pos_normalized, depth, out);
// 
//   vec4 pos = { out[0], out[1], out[2], 1.0f };
//   mat4_mul_v(inv_model, pos, pos);
// 
//   // pos[3] = 1.0f / pos[3];
//   // pos[0] *= pos[3];
//   // pos[1] *= pos[3];
//   // pos[2] *= pos[3];
//   
//   // pos[0] /= pos[3];
//   // pos[1] /= pos[3];
//   // pos[2] /= pos[3];
//   
//   vec3_copy(pos, out);
// }

#ifdef __cplusplus
} // extern C
#endif

#endif
