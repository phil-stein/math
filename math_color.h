#ifndef COLOR_MATH_H
#define COLOR_MATH_H

#include "math_inc.h"

typedef unsigned char c_byte;
typedef c_byte        rgb[3];     // 0 - 255 
typedef c_byte        rgba[4];    // 0 - 255 
typedef float         rgbf[3];    // 0.0f - 1.0f
typedef float         rgbaf[4];   // 0.0f - 1.0f
typedef int           c_hex;      // 0xFF0000 rrggbb, 0xFF0000FF rrggbbaa          

#define R(r)                (rgb)  {r, 0, 0}
#define G(g)                (rgb)  {0, g, 0}
#define B(b)                (rgb)  {0, 0, b}
#define RGB(r, g, b)        (rgb)  {r, g, b}
#define RGB_RGB(c)          (rgb)  {c, c, c}
#define R_A(r)              (rgba) {r, 0, 0, 1}
#define G_A(g)              (rgba) {0, g, 0, 1}
#define B_A(b)              (rgba) {0, 0, b,1 }
#define RGB_A(r, g, b, a)   (rgba) {r, g, b, a}
#define RGB_A_RGB(c)        (rgba) {c, c, c, 1}
#define R_F(r)              (rgbf) {r, 0, 0}
#define G_F(g)              (rgbf) {0, g, 0}
#define B_F(b)              (rgbf) {0, 0, b}
#define RGB_F(r, g, b)      (rgbf) {r, g, b}
#define RGB_F_RGB(c)        (rgbf) {c, c, c}
#define R_AF(r)             (rgbaf){r, 0, 0, 1}
#define G_AF(g)             (rgbaf){0, g, 0, 1}
#define B_AF(b)             (rgbaf){0, 0, b,1 }
#define RGB_AF(r, g, b, a)  (rgbaf){r, g, b, a}
#define RGB_AF_RGB(c)       (rgbaf){c, c, c, 1}

#define P_RGB(c)    printf("RGB   | %s | r: %.3d, g: %.3d, b: %.3d\n", #c, (int)c[0], (int)c[1], (int)c[2])
#define P_RGBA(c)   printf("RGBA  | %s | r: %.3d, g: %.3d, b: %.3d, a: %.3d\n", #c, (int)c[0], (int)c[1], (int)c[2], (int)c[3])
#define P_RGBF(c)   printf("RGBF  | %s | r: %.2f, g: %.2f, b: %.2f\n", #c, c[0], c[1], c[2])
#define P_RGBAF(c)  printf("RGBFA | %s | r: %.2f, g: %.2f, b: %.2f, a: %.2f\n", #c, c[0], c[1], c[2], c[3])

#define P_IL_RGB(c)    printf("RGB   | %s | r: %.3d, g: %.3d, b: %.3d", #c, (int)c[0], (int)c[1], (int)c[2])
#define P_IL_RGBA(c)   printf("RGBA  | %s | r: %.3d, g: %.3d, b: %.3d, a: %.3d", #c, (int)c[0], (int)c[1], (int)c[2], (int)c[3])
#define P_IL_RGBF(c)   printf("RGBF  | %s | r: %.2f, g: %.2f, b: %.2f", #c, c[0], c[1], c[2])
#define P_IL_RGBAF(c)  printf("RGBFA | %s | r: %.2f, g: %.2f, b: %.2f, a: %.2f", #c, c[0], c[1], c[2], c[3])



// ---- copy ----

M_INLINE void rgb_copy(rgb a, rgb dest)
{
  dest[0] = a[0];
  dest[1] = a[1];
  dest[2] = a[2];
}
M_INLINE void rgba_copy(rgba a, rgba dest)
{
  dest[0] = a[0];
  dest[1] = a[1];
  dest[2] = a[2];
  dest[3] = a[3];
}
M_INLINE void rgbf_copy(rgbf a, rgbf dest)
{
  dest[0] = a[0];
  dest[1] = a[1];
  dest[2] = a[2];
}
M_INLINE void rgbaf_copy(rgbaf a, rgbaf dest)
{
  dest[0] = a[0];
  dest[1] = a[1];
  dest[2] = a[2];
  dest[3] = a[3];
}


// ---- type trunc ----

M_INLINE void rgba_to_rgb(rgba a, rgb dest)
{
  dest[0] = a[0];
  dest[1] = a[1];
  dest[2] = a[2];
}
M_INLINE void rgb_to_rgba(rgba a, c_byte alpha, rgb dest)
{
  dest[0] = a[0];
  dest[1] = a[1];
  dest[2] = a[2];
  dest[3] = alpha;
}
M_INLINE void rgbaf_to_rgbf(rgbaf a, rgbf dest)
{
  dest[0] = a[0];
  dest[1] = a[1];
  dest[2] = a[2];
}
M_INLINE void rgbf_to_rgbaf(rgbaf a, float alpha, rgbf dest)
{
  dest[0] = a[0];
  dest[1] = a[1];
  dest[2] = a[2];
  dest[3] = alpha;
}


// ---- conversion ----

M_INLINE void rgb_to_rgbf(rgb a, rgbf dest)
{
  dest[0] = a[0] / 256;
  dest[1] = a[1] / 256;
  dest[2] = a[2] / 256;
}
M_INLINE void rgba_to_rgbaf(rgba a, rgbaf dest)
{
  dest[0] = a[0] / 256;
  dest[1] = a[1] / 256;
  dest[2] = a[2] / 256;
  dest[3] = a[3] / 256;
}
M_INLINE void rgbf_to_rgb(rgbf a, rgb dest)
{
  dest[0] = a[0] * 256;
  dest[1] = a[1] * 256;
  dest[2] = a[2] * 256;
}
M_INLINE void rgbaf_to_rgba(rgbaf a, rgba dest)
{
  dest[0] = a[0] * 256;
  dest[1] = a[1] * 256;
  dest[2] = a[2] * 256;
  dest[3] = a[3] * 256;
}
M_INLINE void hex_to_rgb(c_hex a, rgb dest)
{
  dest[2] = ((a >> 8)  & 0xFF); // extract second byte
  dest[1] = ((a >> 16) & 0xFF); // extract third byte
  dest[0] = ((a >> 24) & 0xFF); // extract fourth byte
}
M_INLINE void hex_to_rgba(c_hex a, rgba dest)
{
  dest[3] = ( a  & 0xFF);       // extract first byte
  dest[2] = ((a >> 8)  & 0xFF); // extract second byte
  dest[1] = ((a >> 16) & 0xFF); // extract third byte
  dest[0] = ((a >> 24) & 0xFF); // extract fourth byte
}
M_INLINE c_hex rgb_to_hex(rgb a)
{
  return a[0] * 0x01000000 + 
         a[1] * 0x00010000 + 
         a[2] * 0x00000100;
}
M_INLINE c_hex rgba_to_hex(rgba a)
{
  return a[0] * 0x01000000 + 
         a[1] * 0x00010000 + 
         a[2] * 0x00000100 + 
         a[3] * 0x00000001;
}

#endif

