#ifndef MATH_VEC3_MATH_H
#define MATH_VEC3_MATH_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "math_inc.h"

typedef float	vec3[3];	// v[0]: x, v[1]: y, v[2]: z
typedef int  ivec3[3];  // v[0]: x, v[1]: y, v[2]: z

// ---- vec3 creation ----

#define VEC3_INIT(f)		        { f, f, f }
#define VEC3_XYZ_INIT(x, y, z)  { x, y, z }
#define VEC3_X_INIT(x)		      { x, 0, 0 }
#define VEC3_Y_INIT(y)		      { 0, y, 0 }
#define VEC3_Z_INIT(z)		      { 0, 0, z }

#ifdef __cplusplus

#define VEC3(f)			      new (vec3){ f, f, f }
#define VEC3_XYZ(x, y, z)	new (vec3){ x, y, z }
#define VEC3_X(x)		      new (vec3){ x, 0, 0 }
#define VEC3_Y(y)		      new (vec3){ 0, y, 0 }
#define VEC3_Z(z)		      new (vec3){ 0, 0, z }

#else 

#define VEC3(f)			      (vec3){ f, f, f }
#define VEC3_XYZ(x, y, z)	(vec3){ x, y, z }
#define VEC3_X(x)		      (vec3){ x, 0, 0 }
#define VEC3_Y(y)		      (vec3){ 0, y, 0 }
#define VEC3_Z(z)		      (vec3){ 0, 0, z }

#endif

#ifndef MATH_PRINT_NO_COLOR // print without using terminal colors
// prints PF_NORMAL, PF_CYAN, then PF_NORMAL PF_WHITE
#define P_VEC3(v) 	  _PF("\033[%d;%dm", 0, 36); printf("|%s|", #v); _PF("\033[%d;%dm", 0, 37); \
                      printf(" x: %.2f, y: %.2f, z: %.2f\n", v[0], v[1], v[2])
// prints PF_NORMAL, PF_CYAN, then PF_NORMAL PF_WHITE
#define P_IL_VEC3(v) 	_PF("\033[%d;%dm", 0, 36); printf("|%s|", #v); _PF("\033[%d;%dm", 0, 37); \
                      printf(" x: %.2f, y: %.2f, z: %.2f", v[0], v[1], v[2])

#define VEC3_NAN(v)      (isnan(v[0]) != 0 || isnan(v[1]) != 0 || isnan(v[2]) != 0) 
// prints PF_NORMAL, PF_CYAN, then PF_NORMAL PF_WHITE
#define P_VEC3_NAN(v)                                                           \
  { if (VEC3_NAN(v))                                                            \
    { _PF("\033[%d;%dm", 0, 36); printf("|%s|", #v); _PF("\033[%d;%dm", 0, 37); \
      printf(" x: %.2f, y: %.2f, z: %.2f\n", v[0], v[1], v[2]); }               \
  }

#else // MATH_PRINT_NO_COLOR
//#define P_VEC3(v) 	printf("|%s| x: %.2f, y: %.2f, z: %.2f\n", #v, v[0], v[1], v[2])
#define P_IL_VEC3(v) 	printf("|%s| x: %.2f, y: %.2f, z: %.2f", #v, v[0], v[1], v[2])

#define VEC3_NAN(v)      (isnan(v[0]) != 0 || isnan(v[1]) != 0 || isnan(v[2]) != 0) 
#define P_VEC3_NAN(v)    { if (VEC3_NAN(v)) { printf("|%s| x: %.2f, y: %.2f, z: %.2f\n", #v, v[0], v[1], v[2]); } }
#endif // MATH_PRINT_NO_COLOR

// ---- vec3 ----


// @DOC: returns x+y+z
M_INLINE float vec3_sum(vec3 v)
{ return v[0] + v[1] + v[2]; }

// @DOC: same as func but can be passed as arg, or initialzier
//       vec3_copy(VEC3_ADD(a, b), c);
#define VEC3_INIT_ADD(a, b)  { (a)[0]+(b)[0], (a)[1]+(b)[1], (a)[2]+(b)[2] }
#define VEC3_ADD(a, b)       (vec3)VEC3_INIT_ADD((a), (b))
M_INLINE void vec3_add(vec3 a, vec3 b, vec3 out)
{
	out[0] = a[0] + b[0];
	out[1] = a[1] + b[1];
	out[2] = a[2] + b[2];
}
// @DOC: same as func but can be passed as arg or initialzier
//       vec3_copy(VEC3_ADD_F(a, 1), c);
#define VEC3_INIT_ADD_F(a, f)  { (a)[0]+(f), (a)[1]+(f), (a)[2]+(f) }
#define VEC3_ADD_F(a, f)       (vec3)VEC3_INIT_ADD_F((a), (f))
M_INLINE void vec3_add_f(vec3 a, float f, vec3 out)
{
	out[0] = a[0] + f;
	out[1] = a[1] + f;
	out[2] = a[2] + f;
}

// @DOC: same as func but can be passed as arg or initialzier
//       vec3_copy(VEC3_SUB(a, b), c);
#define VEC3_INIT_SUB(a, b)  { (a)[0]-(b)[0], (a)[1]-(b)[1], (a)[2]-(b)[2] }
#define VEC3_SUB(a, b)       (vec3)VEC3_INIT_SUB((a), (b))
M_INLINE void vec3_sub(vec3 a, vec3 b, vec3 out)
{
	out[0] = a[0] - b[0];
	out[1] = a[1] - b[1];
	out[2] = a[2] - b[2];
}
// @DOC: same as func but can be passed as arg or initializer
//       vec3_copy(VEC3_SUB_F(a, 1), c);
#define VEC3_INIT_SUB_F(a, f)  { (a)[0]-(f), (a)[1]-(f), (a)[2]-(f) }
#define VEC3_SUB_F(a, f)       (vec3)VEC3_INIT_SUB_F((a), (f))
M_INLINE void vec3_sub_f(vec3 a, float f, vec3 out)
{
	out[0] = a[0] - f;
	out[1] = a[1] - f;
	out[2] = a[2] - f;
}

// @DOC: same as func but can be passed as arg or initializer
//       vec3_copy(VEC3_MUL(a, b), c);
#define VEC3_INIT_MUL(a, b)  { (a)[0]*(b)[0], (a)[1]*(b)[1], (a)[2]*(b)[2] }
#define VEC3_MUL(a, b)       (vec3)VEC3_INIT_MUL((a), (b))
M_INLINE void vec3_mul(vec3 a, vec3 b, vec3 out)
{
	out[0] = a[0] * b[0];
	out[1] = a[1] * b[1];
	out[2] = a[2] * b[2];
}
// @DOC: same as func but can be passed as arg oe initializer
//       vec3_copy(VEC3_MUL_F(a, 1), c);
#define VEC3_INIT_MUL_F(a, f)  { (a)[0]*(f), (a)[1]*(f), (a)[2]*(f) }
#define VEC3_MUL_F(a, f)       (vec3)VEC3_INIT_MUL_F((a), (f))
M_INLINE void vec3_mul_f(vec3 a, float f, vec3 out)
{
	out[0] = a[0] * f;
	out[1] = a[1] * f;
	out[2] = a[2] * f;
}

// @DOC: same as func but can be passed as arg or initializer
//       vec3_copy(VEC3_DIV(a, b), c);
#define VEC3_INIT_DIV(a, b)  { (a)[0]/(b)[0], (a)[1]/(b)[1], (a)[2]/(b)[2] }
#define VEC3_DIV(a, b)       (vec3)VEC3_INIT_DIV((a), (b))
M_INLINE void vec3_div(vec3 a, vec3 b, vec3 out)
{
	out[0] = a[0] / b[0];
	out[1] = a[1] / b[1];
	out[2] = a[2] / b[2];
}
// @DOC: same as func but can be passed as arg or initializer
//       vec3_copy(VEC3_DIV_F(a, 1), c);
#define VEC3_INIT_DIV_F(a, f)  { (a)[0]/(f), (a)[1]/(f), (a)[2]/(f) }
#define VEC3_DIV_F(a, f)       (vec3)VEC3_INIT_DIV_F((a), (f)) 
M_INLINE void vec3_div_f(vec3 a, float f, vec3 out)
{
	out[0] = a[0] / f;
	out[1] = a[1] / f;
	out[2] = a[2] / f;
}

// @DOC: same as func but can be passed as arg or initializer
//       vec3_copy(VEC3_CROSS(a, b), c);
#define VEC3_INIT_CROSS(a, b) {                                   \
                              (a)[1] * (b)[2] - (a)[2] * (b)[1],  \
                              (a)[2] * (b)[0] - (a)[0] * (b)[2],  \
                              (a)[0] * (b)[1] - (a)[1] * (b)[0] }
#define VEC3_CROSS(a, b)      (vec3)VEC3_INIT_CROSS((a), (b)) 
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

#define VEC3_MAGNITUDE(a)   (sqrtf(((a)[0] * (a)[0]) + ((a)[1] * (a)[1]) + ((a)[2] * (a)[2])))
M_INLINE float vec3_magnitude(vec3 a) // length
{
	return sqrtf((a[0] * a[0]) + (a[1] * a[1]) + (a[2] * a[2]));
}

// @DOC: same as func but can initialize vec3 var
//       vec3 a = VEC3_INIT_COPY(b);
#define VEC3_INIT_COPY(a) { (a)[0], (a)[1], (a)[2] }
M_INLINE void vec3_copy(vec3 a, vec3 out)
{
	out[0] = a[0];
	out[1] = a[1];
	out[2] = a[2];
}
// @NOTE: VEC3_INIT_COPY_F(f) would just be VEC3_INIT(f)
M_INLINE void vec3_copy_f(float a, vec3 out)
{
	out[0] = a;
	out[1] = a;
	out[2] = a;
}

// @DOC: same as func but can be passed as arg or initializer
//       vec3_copy(VEC3_NEGATE(a), b);
#define VEC3_INIT_NEGATE(a)  { -(a)[0], -(a)[1], -(a)[2] } 
#define VEC3_NEGATE(a)       (vec3)VEC3_INIT_NEGATE((a)) 
M_INLINE void vec3_negate(vec3 a, vec3 out)
{
	out[0] = -a[0];
	out[1] = -a[1];
	out[2] = -a[2];
}

// @TODO:
// @DOC: same as func but can be passed as arg,
//       vec3_copy(VEC3_NORMALIZE(a), b);
// #define VEC3_INIT_NORMALIZE(a) ( ((a)[0] == 0.0f && (a)[1] == 0.0f && (a)[2] == 0.0f) ? VEC3(0.0f) : VEC3_INIT_DIV_F((a), VEC3_MAGNITUDE(a)) )
// #define VEC3_NORMALIZE(a)      ( ((a)[0] == 0.0f && (a)[1] == 0.0f && (a)[2] == 0.0f) ? VEC3(0.0f) : VEC3_DIV_F((a),      VEC3_MAGNITUDE(a)) )
M_INLINE void vec3_normalize(vec3 a, vec3 out)
{
	vec3_copy(a, out);
  if (a[0] == 0.0f && a[1] == 0.0f && a[2] == 0.0f) { return; } // otherwise next steps would be 0 / 0
	float mag = vec3_magnitude(out);
	vec3_div_f(out, mag, out);
}

M_INLINE float vec3_distance(vec3 a, vec3 b)
{
	vec3 d;
	vec3_sub(a, b, d);
	return vec3_magnitude(d); 
}

// @TODO: @BUGG: idk why i have to include here otherwise errors 
#include "math_vec4.h"
#include "math_mat4.h"

M_INLINE void vec3_rotate_towards(vec3 current, vec3 target, float max_angle_deg, vec3 out)
{
  // taken from: https://gamedev.stackexchange.com/questions/203035/implementation-of-vector3-rotatetowards-from-unity
  // Vector3 fromDirection = fromVector.normalized; // current_dir = norm(current)
  // Vector3 toDirection = toVector.normalized;     // target_dir  = norm(target) 
  // float angleRadians = Mathf.Acos(Vector3.Dot(fromDirection, toDirection));
  // float angleDegrees = Mathf.Min(angleRadians * Mathf.Rad2Deg, maxAngleDegrees);
  // Vector3 axis = Vector3.Cross(fromDirection, toDirection);
  // Quaternion rotationIncrement = Quaternion.AngleAxis(angleDegrees, axis);
  // outputVector = rotationIncrement * fromVector;

  printf("i dont think this works: %s\n", __func__);
  abort();

  vec3 current_dir, target_dir;
  vec3_normalize(current, current_dir);
  vec3_normalize(target, target_dir);
  
  f32 angle_rad = acos(vec3_dot(current, current_dir));
  f32 angle_deg = angle_rad; 
  m_rad_to_deg(&angle_deg);
  angle_deg = MIN(angle_deg, max_angle_deg);
  angle_rad = angle_deg;
  m_deg_to_rad(&angle_rad);

  vec3 axis;
  vec3_cross(current, current_dir, axis);
  mat4 rot_mat;
  mat4_rotate_make(rot_mat, angle_rad, axis);
  vec4 result, current_v4;
  vec3_copy(current, current_v4);
  current_v4[3] = 0.0f; // @UNSURE:
  mat4_mul_v(rot_mat, current_v4, result);
  vec3_copy(result, out);
}

// @DOC: same as func but can be passed as arg,
//       vec3_copy(VEC3_MIN(a, min), b);
#define VEC3_INIT_MIN(a, min) {                       \
                              MIN((a)[0], (min)[0]),  \
                              MIN((a)[1], (min)[1]),  \
                              MIN((a)[2], (min)[2]) }
#define VEC3_MIN(a, min)      (vec3)VEC3_INIT_MIN((a), (min))
M_INLINE void vec3_min(vec3 a, vec3 min, vec3 out)
{
	out[0] = MIN(a[0], min[0]);
	out[1] = MIN(a[1], min[1]);
	out[2] = MIN(a[2], min[2]);
}
// @DOC: same as func but can be passed as arg,
//       vec3_copy(VEC3_MIN_F(a, 1), b);
#define VEC3_INIT_MIN_F(a, f) {                  \
                              MIN((a)[0], (f)),  \
                              MIN((a)[1], (f)),  \
                              MIN((a)[2], (f)) }
#define VEC3_MIN_F(a, f)      (vec3)VEC3_INIT_MIN_F((a), (f))
M_INLINE void vec3_min_f(vec3 a, float min, vec3 out)
{
	out[0] = MIN(a[0], min);
	out[1] = MIN(a[1], min);
	out[2] = MIN(a[2], min);
}

// @DOC: same as func but can be passed as arg,
//       vec3_copy(VEC3_MAX(a, max), b);
#define VEC3_INIT_MAX(a, max) {                       \
                              MAX((a)[0], (max)[0]),  \
                              MAX((a)[1], (max)[1]),  \
                              MAX((a)[2], (max)[2]) }
#define VEC3_MAX(a, max)      (vec3)VEC3_INIT_MAX((a), (max))
M_INLINE void vec3_max(vec3 a, vec3 max, vec3 out)
{
	out[0] = MAX(a[0], max[0]);
	out[1] = MAX(a[1], max[1]);
	out[2] = MAX(a[2], max[2]);
}
// @DOC: same as func but can be passed as arg,
//       vec3_copy(VEC3_MAX_F(a, 1), b);
#define VEC3_INIT_MAX_F(a, f) {                  \
                              MAX((a)[0], (f)),  \
                              MAX((a)[1], (f)),  \
                              MAX((a)[2], (f)) }
#define VEC3_MAX_F(a, f)      (vec3)VEC3_INIT_MAX_F((a), (f))
M_INLINE void vec3_max_f(vec3 a, float max, vec3 out)
{
	out[0] = MAX(a[0], max);
	out[1] = MAX(a[1], max);
	out[2] = MAX(a[2], max);
}

// @DOC: same as func but can be passed as arg,
//       vec3_copy(VEC3_CLAMP(a, min, max), b);
#define VEC3_INIT_CLAMP(a, min, max) {                                   \
                                     CLAMP((a)[0], (min)[0], (max)[0]),  \
                                     CLAMP((a)[1], (min)[1], (max)[1]),  \
                                     CLAMP((a)[2], (min)[2], (max)[2]) }
#define VEC3_CLAMP(a, min, max)      (vec3)VEC3_INIT_CLAMP((a), (min), (max))
M_INLINE void vec3_clamp(vec3 a, vec3 min, vec3 max, vec3 out)
{
	out[0] = CLAMP(a[0], min[0], max[0]);
	out[1] = CLAMP(a[1], min[1], max[1]);
	out[2] = CLAMP(a[2], min[2], max[2]);
}
// @DOC: same as func but can be passed as arg,
//       vec3_copy(VEC3_CLAMP_F(a, min, max), b);
#define VEC3_INIT_CLAMP_F(a, min, max) {                             \
                                       CLAMP((a)[0], (min), (max)),  \
                                       CLAMP((a)[1], (min), (max)),  \
                                       CLAMP((a)[2], (min), (max)) }
#define VEC3_CLAMP_F(a, min, max)      (vec3)VEC3_INIT_CLAMP_F((a), (min), (max))
M_INLINE void vec3_clamp_f(vec3 a, float min, float max, vec3 out)
{
	out[0] = CLAMP(a[0], min, max);
	out[1] = CLAMP(a[1], min, max);
	out[2] = CLAMP(a[2], min, max);
}

// @DOC: same as func but can be passed as arg,
//       vec3_copy(VEC3_ABS(a), b);
#define VEC3_INIT_ABS(a) {                   \
                         FLOAT_ABS((a)[0]),  \
                         FLOAT_ABS((a)[1]),  \
                         FLOAT_ABS((a)[2]) }
#define VEC3_ABS(a)      (vec3)VEC3_INIT_ABS((a))
M_INLINE void vec3_abs(vec3 a, vec3 out)
{
	out[0] = FLOAT_ABS(a[0]);
	out[1] = FLOAT_ABS(a[1]);
	out[2] = FLOAT_ABS(a[2]);
}

// ---- interpolation ----

// @DOC: same as func but can be passed as arg,
//       vec3_copy(VEC3_LERP(a), b);
#define VEC3_INIT_LERP(start, end, percentage) {                                            \
                                                m_lerp((start)[0], (end)[0], (percentage)), \
                                                m_lerp((start)[1], (end)[1], (percentage)), \
                                                m_lerp((start)[2], (end)[2], (percentage)) }
#define VEC3_LERP(start, end, percentage)       (vec3)VEC3_INIT_LERP((start), (end), (percentage))
M_INLINE void vec3_lerp(vec3 start, vec3 end, float percentage, vec3 out)
{
  out[0] = m_lerp(start[0], end[0], percentage);
  out[1] = m_lerp(start[1], end[1], percentage);
  out[2] = m_lerp(start[2], end[2], percentage);
}
// @DOC: same as func but can be passed as arg,
//       vec3_copy(VEC3_LERP_F(a), b);
#define VEC3_INIT_LERP_F(start, end, percentage) {                                      \
                                                  m_lerp((start), (end), (percentage)), \
                                                  m_lerp((start), (end), (percentage)), \
                                                  m_lerp((start), (end), (percentage)) }
#define VEC3_LERP_F(start, end, percentage)       (vec3)VEC3_INIT_LERP_F((start), (end), (percentage))
M_INLINE void vec3_lerp_f(float start, float end, float percentage, vec3 out)
{
  out[0] = m_lerp(start, end, percentage);
  out[1] = m_lerp(start, end, percentage);
  out[2] = m_lerp(start, end, percentage);
}


// ---- conditionals ----

M_INLINE bool vec3_equal(vec3 a, vec3 b)
{
  // return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
  return FLOAT_EQ(a[0], b[0]) && FLOAT_EQ(a[1], b[1]) && FLOAT_EQ(a[2], b[2]);
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

#ifdef __cplusplus
} // extern C
#endif

#endif
