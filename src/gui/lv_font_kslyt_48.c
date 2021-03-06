/*******************************************************************************
 * Size: 48 px
 * Bpp: 4
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef LV_FONT_KSLYT_48
#define LV_FONT_KSLYT_48 1
#endif

#if LV_FONT_KSLYT_48

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x0, 0xff, 0x24, 0x67, 0x7f, 0x6d, 0xb8, 0x80,
    0x7f, 0xf1, 0x5f, 0xad, 0xcc, 0x40, 0x49, 0x23,
    0xa4, 0x40, 0x3f, 0xf8, 0x27, 0xb0, 0x20, 0x1f,
    0xe6, 0xe7, 0x20, 0xf, 0xf2, 0xe1, 0x0, 0x7f,
    0xf0, 0xa3, 0x0, 0x3f, 0x96, 0x80, 0x3e, 0x13,
    0x30, 0x80, 0x78, 0x40, 0x3f, 0x15, 0x0, 0x79,
    0xb3, 0xb3, 0x1d, 0x8a, 0x1, 0xd2, 0x1, 0xf7,
    0x0, 0x71, 0xec, 0x98, 0x6, 0x3a, 0xa0, 0x6,
    0x6b, 0x0, 0xe5, 0x30, 0xc, 0x98, 0x40, 0x1f,
    0x97, 0x60, 0x2, 0x44, 0x0, 0x68, 0x0, 0xc5,
    0x60, 0x1f, 0xf1, 0x38, 0x80, 0x50, 0x1, 0x21,
    0x0, 0x6e, 0x0, 0xff, 0xe1, 0x38, 0x4, 0x66,
    0x0, 0x68, 0x6, 0x53, 0x0, 0xff, 0xe1, 0x50,
    0x6, 0xb0, 0x3, 0x80, 0x68, 0x0, 0xff, 0xe1,
    0x98, 0x80, 0x4a, 0x2, 0x20, 0x8, 0xc8, 0x3,
    0xff, 0x88, 0x80, 0x11, 0xa, 0x80, 0x64, 0x0,
    0xff, 0xe2, 0xe8, 0x6, 0x42, 0x0, 0xda, 0x1,
    0xff, 0xc5, 0x30, 0xd, 0xa2, 0x1, 0x98, 0x3,
    0xff, 0x8a, 0xc0, 0x18, 0xbc, 0x3, 0x8, 0x7,
    0xff, 0x14, 0xc0, 0x33, 0x0, 0x7f, 0xf2, 0xc4,
    0x3, 0xf, 0x80, 0x7f, 0xf2, 0x84, 0x3, 0x84,
    0x3, 0x8, 0x7, 0xff, 0x14, 0x80, 0x30, 0x98,
    0x6, 0x60, 0xf, 0xfe, 0x2b, 0x0, 0x67, 0x70,
    0x6, 0xc0, 0xf, 0xfe, 0x2e, 0x0, 0x62, 0x20,
    0x6, 0x40, 0xf, 0xfe, 0x2a, 0x0, 0x6f, 0x4,
    0x0, 0x89, 0x0, 0x3f, 0xf8, 0x66, 0x40, 0x19,
    0x43, 0x80, 0x34, 0x80, 0x7f, 0xf0, 0xe0, 0x3,
    0x11, 0x82, 0x80, 0x62, 0x70, 0xf, 0xfe, 0xa,
    0x20, 0x3, 0x28, 0x4, 0xe0, 0x1a, 0x14, 0x3,
    0xfe, 0x2a, 0x0, 0xea, 0x0, 0xa0, 0x40, 0x35,
    0x40, 0x7, 0xf1, 0xe0, 0x80, 0x66, 0x20, 0xd,
    0x60, 0x1c, 0xfa, 0xc2, 0x1, 0x8a, 0x70, 0x40,
    0x30, 0xc0, 0x7, 0x2c, 0x0, 0x71, 0x4f, 0x73,
    0x31, 0xda, 0xc0, 0x1e, 0xa1, 0x0, 0xf3, 0xb8,
    0x3, 0xe1, 0x33, 0x8, 0x7, 0xd4, 0x80, 0x1f,
    0xa2, 0x84, 0x3, 0xff, 0x84, 0x38, 0xa0, 0x1f,
    0xe5, 0xf5, 0x0, 0xff, 0xe0, 0x3f, 0x18, 0x7,
    0xff, 0x0, 0x6b, 0xa5, 0x48, 0x2, 0x13, 0x6a,
    0xf8, 0x0, 0xf8,

    /* U+0031 "1" */
    0x0, 0xfe, 0x7e, 0x70, 0xf, 0xf9, 0xe0, 0x63,
    0x48, 0x3, 0xf4, 0xc0, 0x4, 0x5a, 0x40, 0x1c,
    0x58, 0xc0, 0x1e, 0x70, 0xc, 0xba, 0x60, 0x1f,
    0x28, 0x0, 0x6a, 0x80, 0x1f, 0x84, 0x0, 0xde,
    0xa0, 0x19, 0xc0, 0x31, 0x84, 0xc8, 0x40, 0x34,
    0x40, 0x3, 0x8, 0x28, 0x7, 0x53, 0x80, 0x7d,
    0x40, 0x11, 0x62, 0x80, 0x79, 0xc1, 0xa9, 0xa7,
    0x4c, 0x3, 0xfc, 0xb2, 0xc0, 0x1f, 0xc2, 0x1,
    0xfc, 0x20, 0x1f, 0xfe, 0x3, 0x0, 0xff, 0xe8,
    0x88, 0x7, 0xff, 0x81, 0xc0, 0x3f, 0xfa, 0x22,
    0x1, 0xff, 0xe0, 0x30, 0xc, 0x20, 0x1f, 0xc2,
    0x1, 0xff, 0xd1, 0xf0, 0xc, 0xe0, 0x1f, 0xc2,
    0x1, 0xff, 0xc2, 0x30, 0xc, 0x20, 0x1f, 0xcc,
    0x1, 0x8c, 0x3, 0xf9, 0x40, 0x31, 0x80, 0x7f,
    0x40, 0x6, 0x70, 0xf, 0xe1, 0x90, 0x2, 0x58,
    0x0,

    /* U+0032 "2" */
    0x0, 0xff, 0x1c, 0x5e, 0xff, 0xbb, 0x6d, 0xc8,
    0x3, 0xff, 0x88, 0xbb, 0x8e, 0x84, 0x0, 0x12,
    0x48, 0xdc, 0x30, 0xf, 0xfe, 0x2, 0x6d, 0x10,
    0x7, 0xfc, 0x79, 0x0, 0x1f, 0xe9, 0xb2, 0x0,
    0xff, 0xe1, 0xbd, 0x0, 0x7c, 0x5a, 0xc0, 0x1f,
    0x1a, 0xa1, 0x80, 0x7c, 0xac, 0x1, 0xd1, 0xa4,
    0x1, 0xc3, 0x3d, 0x95, 0x79, 0xf2, 0x20, 0x1d,
    0x0, 0x1c, 0x60, 0x1e, 0x5e, 0x61, 0x0, 0xe6,
    0xf3, 0x0, 0xc2, 0xa0, 0x1b, 0x0, 0x39, 0xe8,
    0x3, 0xf8, 0x78, 0x3, 0xb0, 0x3, 0x20, 0x6,
    0x68, 0x0, 0xff, 0x88, 0xc0, 0x31, 0x0, 0x63,
    0x20, 0x1, 0xc8, 0x7, 0xff, 0x5, 0x80, 0x33,
    0x80, 0x74, 0x0, 0x38, 0x3, 0xff, 0x84, 0xc0,
    0x19, 0x80, 0x39, 0x66, 0xc8, 0x3, 0xff, 0x84,
    0x60, 0x18, 0x80, 0x3c, 0xc8, 0x1, 0xff, 0xc2,
    0x60, 0xe, 0xc0, 0xf, 0xfe, 0x48, 0xc8, 0x7,
    0x20, 0x7, 0xff, 0x20, 0x70, 0x3, 0x9c, 0x3,
    0xff, 0x90, 0x58, 0x40, 0x18, 0x64, 0x3, 0xff,
    0x8e, 0xda, 0x40, 0x1d, 0x42, 0x1, 0xff, 0xc5,
    0x1a, 0x90, 0xf, 0x4a, 0x0, 0x7f, 0xf1, 0x53,
    0xd4, 0x3, 0xd2, 0xc0, 0x1f, 0xfc, 0x57, 0xb1,
    0x0, 0xe1, 0xb6, 0x0, 0xff, 0xe2, 0xdc, 0x0,
    0x79, 0x3d, 0x0, 0x3f, 0xf8, 0x85, 0xa8, 0x1,
    0xe8, 0xb1, 0x0, 0xff, 0xe2, 0x26, 0x90, 0x7,
    0x1e, 0xb8, 0x7, 0xff, 0x15, 0xac, 0x3, 0xd1,
    0x84, 0x1, 0xff, 0xc5, 0x79, 0x0, 0xe3, 0xd7,
    0x0, 0xff, 0xe3, 0x44, 0x0, 0x3a, 0x70, 0x80,
    0x3f, 0xf8, 0xd0, 0xe0, 0x18, 0xb5, 0x80, 0x3f,
    0xf8, 0xee, 0xe0, 0xc, 0xba, 0x40, 0x1f, 0xfc,
    0x74, 0x80, 0xc, 0xf4, 0x1, 0xff, 0xc9, 0xa0,
    0xc, 0xd0, 0x1, 0xff, 0xc9, 0x91, 0x0, 0xc5,
    0xdf, 0xff, 0xfc, 0x6c, 0x2c, 0x60, 0xe, 0x41,
    0x0, 0xff, 0xe3, 0x1f, 0x28, 0x7, 0xff, 0x42,
    0x50, 0x3, 0xff, 0x9d, 0x21, 0x6c, 0x1, 0x89,
    0x15, 0x4c, 0xde, 0x55, 0x22, 0xc, 0x88, 0x20,
    0x32, 0xa0, 0x9, 0xdb, 0xef, 0xdb, 0xaa, 0x4c,
    0xfa, 0xa9, 0x76, 0xcd, 0xd7, 0x7f, 0x30, 0x0,

    /* U+0033 "3" */
    0x0, 0xfe, 0x26, 0x9c, 0xef, 0xfb, 0x6e, 0xc,
    0x3, 0xff, 0x84, 0x2f, 0xba, 0x96, 0x31, 0x0,
    0x89, 0x1f, 0x30, 0x80, 0x1f, 0xe3, 0xae, 0x82,
    0x0, 0xff, 0xe0, 0x1d, 0xc8, 0x7, 0xc5, 0x98,
    0x50, 0xf, 0xfe, 0x2b, 0x50, 0x7, 0xb0, 0xc0,
    0x3f, 0x13, 0x3c, 0x3a, 0x0, 0x79, 0x54, 0x1,
    0xff, 0xc0, 0x29, 0xed, 0x98, 0x78, 0xbf, 0x80,
    0xe, 0x80, 0xe, 0x90, 0xe, 0x9d, 0x61, 0x0,
    0xf9, 0xe4, 0x3, 0x10, 0x80, 0x67, 0x40, 0xb,
    0x18, 0x3, 0xfe, 0x60, 0xe, 0x20, 0xe, 0xb4,
    0xa, 0x30, 0xf, 0xfe, 0x31, 0x0, 0x7a, 0xf5,
    0x40, 0x3f, 0xf8, 0x28, 0x1, 0x88, 0x40, 0x3e,
    0x20, 0xf, 0xfe, 0x9, 0xd0, 0x6, 0xb0, 0xf,
    0xfe, 0x40, 0xc6, 0x8, 0x4, 0xac, 0x1, 0xff,
    0xc3, 0x12, 0x58, 0xce, 0x70, 0xd, 0x34, 0x1,
    0xff, 0xc0, 0xbe, 0xff, 0x76, 0xd3, 0x98, 0x6,
    0x7e, 0x60, 0xf, 0xfe, 0x1, 0x20, 0x80, 0x7f,
    0xcd, 0x4a, 0x1, 0xff, 0xce, 0x14, 0xac, 0x20,
    0xf, 0xf1, 0x0, 0x7e, 0x10, 0xf, 0x8f, 0x8,
    0x3, 0xfc, 0x80, 0x1, 0x5a, 0xdf, 0xef, 0xeb,
    0x50, 0xc, 0x3c, 0x1, 0xfe, 0xf1, 0x8e, 0xa5,
    0x20, 0x8, 0x52, 0xac, 0x3, 0x1a, 0x80, 0x7f,
    0x27, 0x38, 0x7, 0xf9, 0x24, 0x3, 0x70, 0x7,
    0xff, 0x2d, 0x80, 0x32, 0x80, 0x7f, 0xf3, 0xc,
    0x2, 0x11, 0x0, 0x7f, 0xf4, 0xc, 0x3, 0xff,
    0x96, 0x40, 0x18, 0xc0, 0x3f, 0xf9, 0x46, 0x20,
    0x18, 0x41, 0x8c, 0x3, 0xff, 0x8f, 0x0, 0x18,
    0xc0, 0x67, 0x20, 0x3, 0xff, 0x8b, 0x8, 0x1,
    0xa8, 0x8, 0x0, 0xfc, 0xe2, 0x1, 0xff, 0xc0,
    0x1a, 0x70, 0xc, 0x2c, 0x1, 0xc3, 0x1d, 0x6c,
    0x40, 0x1f, 0x24, 0xf2, 0x80, 0x75, 0x80, 0x8,
    0x3, 0xc9, 0x3b, 0xfb, 0x97, 0x9b, 0xf6, 0xc0,
    0x1e, 0x65, 0x0, 0xb, 0x0, 0x7f, 0x11, 0xa1,
    0x90, 0x7, 0xe7, 0x90, 0xd, 0x34, 0x40, 0x1f,
    0xfc, 0x61, 0xa8, 0x0, 0xf2, 0xed, 0xa8, 0x7,
    0xff, 0x8, 0xa3, 0x94, 0x3, 0xf9, 0x2b, 0xf2,
    0x14, 0xc4, 0x2, 0x13, 0x59, 0xcd, 0x70, 0xf,
    0x80,

    /* U+0034 "4" */
    0x0, 0xff, 0xe3, 0x16, 0x73, 0x80, 0x7f, 0xf4,
    0x3c, 0xc6, 0x30, 0x3, 0xff, 0x9d, 0x4, 0x1,
    0x19, 0x80, 0x3f, 0xf9, 0x86, 0xe0, 0x1f, 0xfd,
    0x2e, 0x0, 0xf1, 0x80, 0x7f, 0xf2, 0xe8, 0x80,
    0x38, 0xc0, 0x3f, 0xf9, 0x6c, 0xa0, 0x1e, 0x34,
    0x0, 0xff, 0xe4, 0x9c, 0x80, 0x7e, 0x10, 0xf,
    0xfe, 0x40, 0xe8, 0x6, 0x60, 0xc, 0x20, 0x1f,
    0xfc, 0x8a, 0x10, 0x9, 0xac, 0x3, 0x38, 0x7,
    0xff, 0x1e, 0x10, 0x2, 0x39, 0x0, 0xff, 0xe6,
    0x2b, 0x80, 0x43, 0xa0, 0x1f, 0xfc, 0xc3, 0xa0,
    0xd, 0xa2, 0x1, 0xff, 0xcb, 0x1d, 0x0, 0xd4,
    0x60, 0x1f, 0xfc, 0xcd, 0x10, 0x9, 0x94, 0x3,
    0xff, 0x99, 0x26, 0x1, 0x1c, 0x80, 0x7f, 0xf3,
    0x19, 0x80, 0x10, 0xe8, 0x7, 0xff, 0x30, 0xe4,
    0x3, 0x60, 0x80, 0x70, 0x80, 0x7f, 0xf1, 0x47,
    0x40, 0x35, 0x10, 0x7, 0xff, 0x33, 0x4, 0x2,
    0x85, 0x0, 0xff, 0xe6, 0x59, 0x0, 0x4a, 0xe0,
    0x1f, 0x9c, 0x3, 0xff, 0x87, 0x8, 0x1, 0x1d,
    0x0, 0x7f, 0xf0, 0x9c, 0x47, 0x80, 0x34, 0xb8,
    0x6, 0x46, 0x69, 0xe6, 0xaf, 0x37, 0x54, 0x1,
    0xaf, 0xbb, 0xbd, 0x80, 0xc, 0x1, 0xcf, 0x33,
    0x43, 0x2a, 0x19, 0x10, 0x40, 0x3f, 0xe9, 0x0,
    0x10, 0x7, 0xff, 0x40, 0x80, 0xa, 0x1, 0xff,
    0xd0, 0x90, 0x4, 0x80, 0x7f, 0xf3, 0x8a, 0xd0,
    0x0, 0x36, 0xd7, 0xbd, 0xff, 0xff, 0x38, 0x6,
    0xbf, 0xfd, 0xa8, 0x1, 0x92, 0x50, 0x84, 0x3,
    0xfe, 0x10, 0xc, 0x20, 0x1f, 0xfd, 0x33, 0x0,
    0xff, 0xe7, 0x18, 0x7, 0xff, 0x4d, 0x80, 0x30,
    0x80, 0x7f, 0xf3, 0x84, 0x3, 0xff, 0xa6, 0xc0,
    0x18, 0x80, 0x3f, 0xf9, 0xd4, 0xe4, 0x8, 0xa0,
    0x1f, 0x80,

    /* U+0035 "5" */
    0x0, 0xc8, 0xe8, 0x1, 0xff, 0xcb, 0x9b, 0x8b,
    0xc8, 0x8f, 0xfe, 0x1b, 0x8, 0x7, 0x30, 0x4,
    0x6e, 0xff, 0xfc, 0x39, 0xf3, 0x0, 0xc4, 0x1,
    0xff, 0xc8, 0x19, 0x0, 0xc2, 0x1, 0xff, 0xce,
    0x20, 0xc, 0xa2, 0x1, 0xff, 0xc1, 0x27, 0xb0,
    0xc, 0x20, 0x1a, 0xbb, 0xff, 0xff, 0x83, 0xb0,
    0x20, 0x10, 0x80, 0x63, 0x0, 0xff, 0xe4, 0xa8,
    0x6, 0x40, 0xf, 0xfe, 0x49, 0x80, 0x6b, 0x0,
    0xff, 0xe4, 0xe8, 0x6, 0x30, 0xf, 0xfe, 0x4b,
    0x80, 0x48, 0x1, 0xff, 0xca, 0x20, 0x8, 0xc0,
    0x21, 0x6a, 0xbd, 0xd5, 0xd3, 0x10, 0x7, 0xe3,
    0x0, 0xd8, 0x9, 0x9d, 0x2a, 0x84, 0x44, 0x59,
    0xdc, 0x40, 0xf, 0x20, 0x7, 0x65, 0x98, 0x7,
    0xf8, 0xee, 0x80, 0x3b, 0x0, 0x35, 0x98, 0x7,
    0xff, 0x9, 0x74, 0x40, 0x25, 0x0, 0xfc, 0x93,
    0xbd, 0xfd, 0x4c, 0x1, 0xc5, 0xa0, 0x2, 0x10,
    0xf, 0x1e, 0x5b, 0x10, 0x80, 0xac, 0xf2, 0x80,
    0x63, 0x70, 0x60, 0xf, 0x3e, 0x18, 0x7, 0xe1,
    0xa7, 0x0, 0xd2, 0x9, 0x22, 0x1, 0x44, 0x0,
    0x3f, 0xf8, 0x10, 0x80, 0x10, 0xa8, 0x37, 0xa0,
    0x2b, 0x80, 0x7f, 0xf0, 0xa0, 0x3, 0x78, 0x0,
    0x6f, 0x28, 0x3, 0xff, 0x86, 0x62, 0x1, 0x38,
    0x6, 0x30, 0xf, 0xfe, 0x29, 0x80, 0x46, 0x1,
    0xff, 0xce, 0x10, 0xf, 0xfe, 0x51, 0x0, 0x42,
    0x1, 0xff, 0xc9, 0x50, 0xc, 0x4e, 0xa0, 0x1f,
    0xfc, 0x78, 0x0, 0xc9, 0x55, 0x8, 0x7, 0xff,
    0x12, 0x88, 0x3, 0x58, 0x1, 0x7a, 0x4, 0x3,
    0xff, 0x80, 0x56, 0xa0, 0x18, 0xcc, 0xe0, 0x13,
    0xf5, 0xb0, 0x80, 0x7c, 0x93, 0xa8, 0x1, 0xde,
    0x18, 0x1, 0xc9, 0x3d, 0xcc, 0xba, 0xbd, 0xfb,
    0x60, 0xf, 0x41, 0x83, 0x18, 0x7, 0xc2, 0x68,
    0xa8, 0x40, 0x1f, 0xa1, 0xc0, 0x2c, 0x91, 0x0,
    0xff, 0xe2, 0x95, 0xb8, 0x7, 0x37, 0x5a, 0x80,
    0x7f, 0xf0, 0x4a, 0x75, 0x0, 0x3f, 0x25, 0x7e,
    0x42, 0x90, 0x80, 0x4, 0x96, 0x37, 0x4c, 0x1,
    0xe0,

    /* U+0036 "6" */
    0x0, 0xff, 0xe1, 0xd, 0x75, 0xa0, 0x7, 0xff,
    0x2c, 0xf1, 0x45, 0x2e, 0xc2, 0x1, 0xff, 0xc8,
    0x7c, 0x20, 0xc, 0x98, 0x20, 0x1f, 0xfc, 0x51,
    0xb8, 0x0, 0xf8, 0x98, 0x3, 0xff, 0x88, 0x7e,
    0x80, 0x1e, 0x16, 0xb7, 0x0, 0xff, 0xe1, 0xa6,
    0x8, 0x7, 0x1d, 0x74, 0xa0, 0x7, 0xff, 0xd,
    0x6c, 0x3, 0x8a, 0xb1, 0x40, 0x3f, 0xf8, 0xab,
    0x40, 0x1c, 0xda, 0xa0, 0x1f, 0xfc, 0x63, 0xa0,
    0xe, 0xa9, 0x0, 0xff, 0xe3, 0x8e, 0x80, 0x75,
    0xa8, 0x7, 0xff, 0x22, 0x84, 0x3, 0x4a, 0x0,
    0x7f, 0xf2, 0x15, 0x0, 0x32, 0xb0, 0x6, 0x12,
    0x10, 0xf, 0xfe, 0x15, 0x80, 0x61, 0xb0, 0x2,
    0xd7, 0xf6, 0xf7, 0xec, 0xa8, 0x7, 0xf3, 0x88,
    0x6, 0x91, 0x6e, 0xa5, 0x0, 0xe2, 0x6a, 0xd5,
    0x0, 0xfa, 0x40, 0x38, 0x76, 0x44, 0x3, 0xfc,
    0x55, 0x40, 0xe, 0x41, 0x0, 0xe9, 0x20, 0xf,
    0xfe, 0x12, 0xd8, 0x6, 0xd0, 0xf, 0xf9, 0xaf,
    0xbf, 0x69, 0x0, 0x39, 0x20, 0x2, 0x40, 0xf,
    0xc5, 0x3f, 0x28, 0x20, 0x4b, 0x78, 0x20, 0x19,
    0xc8, 0x0, 0x40, 0x18, 0xc0, 0xeb, 0x58, 0x3,
    0xf1, 0xf8, 0x80, 0x6b, 0x2, 0x0, 0xc7, 0x9f,
    0x8a, 0x1, 0xff, 0xd, 0x0, 0x67, 0x1, 0x0,
    0xd6, 0x1, 0xff, 0xc4, 0x43, 0x0, 0x84, 0xc0,
    0x3f, 0xf9, 0x76, 0x1, 0x98, 0x40, 0x37, 0x80,
    0x7f, 0xf1, 0x48, 0x3, 0x19, 0x0, 0x63, 0x0,
    0xff, 0xe6, 0x10, 0x4, 0x82, 0x1, 0xff, 0xc4,
    0xd0, 0xc, 0x60, 0x80, 0x19, 0x80, 0x3f, 0xf8,
    0x8a, 0x1, 0x9c, 0x28, 0x3, 0x41, 0x0, 0x7f,
    0xf0, 0x94, 0x80, 0x21, 0x20, 0x34, 0x0, 0xde,
    0x20, 0x1f, 0xfc, 0x2, 0xb0, 0xd, 0x20, 0x14,
    0x80, 0x62, 0xc3, 0x0, 0xff, 0x1e, 0x8, 0x4,
    0x2e, 0x1, 0x14, 0x0, 0x62, 0xca, 0x20, 0xf,
    0x14, 0xe0, 0x80, 0x6a, 0x0, 0xe7, 0x50, 0xe,
    0x5d, 0xeb, 0x99, 0x57, 0x6b, 0x0, 0x73, 0xa0,
    0x7, 0xa9, 0x80, 0x3c, 0x28, 0xcc, 0x51, 0x0,
    0xf3, 0xc0, 0x7, 0xe9, 0xa0, 0xf, 0xfe, 0x18,
    0xdc, 0x0, 0x7f, 0x97, 0x9c, 0x3, 0xfe, 0x18,
    0xf4, 0x0, 0xff, 0xe0, 0xc, 0x7d, 0x31, 0x88,
    0x0, 0x8d, 0xef, 0x9c, 0x40, 0x3c,

    /* U+0037 "7" */
    0x0, 0x13, 0x8, 0x7, 0xff, 0x10, 0xa1, 0xc0,
    0x21, 0xbd, 0x9e, 0xff, 0xff, 0xe2, 0x6b, 0xc4,
    0x80, 0xd, 0x0, 0x3f, 0xf9, 0x4d, 0x0, 0x40,
    0x1f, 0xfc, 0xc7, 0x30, 0xf, 0xfe, 0x75, 0x80,
    0x72, 0xb3, 0x7f, 0xf0, 0xc0, 0x3b, 0x0, 0x3a,
    0x67, 0xff, 0x87, 0xc0, 0x1a, 0x10, 0x40, 0x33,
    0x80, 0x7f, 0xf0, 0x46, 0x0, 0x25, 0x70, 0x30,
    0xc, 0xe0, 0x1f, 0xfc, 0x1b, 0x0, 0x86, 0xc0,
    0x6, 0x1, 0x84, 0x3, 0xff, 0x80, 0x6a, 0x1,
    0x40, 0x80, 0x7, 0x9c, 0x48, 0x80, 0x1f, 0xfc,
    0xf, 0x0, 0x89, 0x80, 0x30, 0xc7, 0x68, 0x7,
    0xff, 0x1, 0x4c, 0x2, 0x80, 0xf, 0xfe, 0x4c,
    0x0, 0x46, 0xa0, 0x1f, 0xfc, 0x87, 0x20, 0xa,
    0x0, 0x3f, 0xf9, 0x3, 0x20, 0x11, 0xa0, 0x7,
    0xff, 0x22, 0x4, 0x2, 0x80, 0xf, 0xfe, 0x41,
    0x30, 0x4, 0x68, 0x1, 0xff, 0xc8, 0x80, 0xd,
    0x0, 0x1f, 0xfc, 0x82, 0x50, 0x8, 0x90, 0x3,
    0xff, 0x91, 0x0, 0x1a, 0xc0, 0x3f, 0xf9, 0x6,
    0xa0, 0x10, 0xb0, 0x7, 0xff, 0x22, 0x0, 0x33,
    0x0, 0x7f, 0xf2, 0xd, 0x0, 0x34, 0x80, 0x7f,
    0xf2, 0x20, 0x3, 0x20, 0x80, 0x7f, 0xf1, 0xcd,
    0x0, 0x37, 0x0, 0x7f, 0xf2, 0x24, 0x3, 0xa,
    0x80, 0x7f, 0xf1, 0xc9, 0x40, 0x33, 0x0, 0x7f,
    0xf2, 0x2c, 0x3, 0xac, 0x3, 0xff, 0x8e, 0x2c,
    0x1, 0x88, 0xc0, 0x3f, 0xf8, 0xf2, 0x1, 0xc8,
    0x1, 0xff, 0xc8, 0x60, 0xe, 0xd0, 0xf, 0xfe,
    0x68, 0xa0, 0x7, 0xff, 0x21, 0x0, 0x34, 0x80,
    0x7f, 0xf2, 0x7c, 0x2, 0x27, 0x0, 0xff, 0xe4,
    0xaa, 0x80, 0x78, 0x3, 0xff, 0x84,

    /* U+0038 "8" */
    0x0, 0xfe, 0x59, 0xce, 0xff, 0x76, 0x4a, 0x0,
    0x7f, 0xf1, 0xa, 0xbe, 0x98, 0xc4, 0x0, 0x26,
    0xd7, 0xf8, 0xe4, 0x1, 0xff, 0x3e, 0xa8, 0x7,
    0xff, 0x0, 0xe3, 0x6d, 0x0, 0x3f, 0x4c, 0x0,
    0x7f, 0xf1, 0x53, 0x80, 0x3e, 0x66, 0x0, 0x70,
    0xac, 0x55, 0x25, 0xd0, 0x3, 0xc2, 0x1, 0xe1,
    0x90, 0xc, 0x33, 0xd4, 0xea, 0xa6, 0x8b, 0xf9,
    0x20, 0x9, 0x20, 0x3, 0x98, 0x3, 0xe, 0x30,
    0x7, 0xf3, 0x6a, 0x0, 0x4e, 0x20, 0x1b, 0x40,
    0x34, 0x90, 0x7, 0xff, 0x2, 0xdc, 0x2, 0x70,
    0xc, 0x20, 0x19, 0x0, 0x3f, 0xf8, 0x5c, 0x1,
    0x70, 0x7, 0xf3, 0x80, 0x7f, 0xf0, 0x84, 0x3,
    0xf6, 0x0, 0x6e, 0x0, 0xff, 0xe1, 0x50, 0x5,
    0x80, 0x19, 0x80, 0x32, 0xb8, 0x7, 0xff, 0x2,
    0x48, 0x0, 0x48, 0x1, 0x86, 0x40, 0x34, 0x51,
    0x0, 0x7e, 0x2b, 0x60, 0xb, 0x80, 0x3c, 0xd0,
    0x1, 0x97, 0x6d, 0x44, 0x0, 0x2d, 0x9a, 0x80,
    0x1, 0xb3, 0x0, 0xf9, 0xec, 0x40, 0x32, 0x57,
    0x67, 0x72, 0x4c, 0x2, 0x3f, 0x40, 0xf, 0xe4,
    0xe8, 0x10, 0xe, 0x31, 0x0, 0xc3, 0x58, 0x20,
    0x1f, 0xfc, 0x2, 0x20, 0x7, 0xfc, 0x3c, 0xa0,
    0x1f, 0xf2, 0xf5, 0x18, 0x7, 0xff, 0x1, 0x2b,
    0x50, 0x3, 0xe1, 0xba, 0x10, 0xe, 0x5a, 0xee,
    0x4a, 0x88, 0x6, 0x2b, 0x80, 0xe, 0x1c, 0x40,
    0xc, 0x31, 0xd4, 0xa2, 0x26, 0xae, 0xa2, 0x0,
    0xcf, 0x20, 0x1b, 0x8, 0x3, 0x27, 0xb8, 0x80,
    0x7c, 0xba, 0xa0, 0x19, 0x94, 0x0, 0xe4, 0x1,
    0x96, 0xc4, 0x3, 0xfe, 0xa5, 0x0, 0xd6, 0x0,
    0x90, 0xc, 0x54, 0x1, 0xff, 0xc2, 0xb0, 0xc,
    0x28, 0x62, 0x1, 0xa8, 0x3, 0xff, 0x86, 0x28,
    0x1, 0x8d, 0x80, 0x38, 0xc0, 0x3f, 0xf8, 0x84,
    0x1, 0xb8, 0xc0, 0x3f, 0xf9, 0x46, 0x1, 0xc6,
    0x1, 0xc4, 0x1, 0xff, 0xc4, 0x70, 0xc, 0x28,
    0x1, 0xd4, 0x1, 0xff, 0xc3, 0x42, 0x0, 0xda,
    0x28, 0x1, 0x8e, 0x0, 0x3f, 0xf8, 0x23, 0x40,
    0x1c, 0xa1, 0x0, 0x1c, 0xf2, 0x1, 0xff, 0x1f,
    0x88, 0x6, 0x80, 0x1, 0xc8, 0x7, 0x37, 0x41,
    0x80, 0x79, 0x2f, 0x4, 0x3, 0x1b, 0x80, 0x4d,
    0x20, 0x1c, 0x2f, 0x9f, 0xb9, 0x8d, 0xfb, 0x40,
    0xe, 0x2d, 0x0, 0xe6, 0xc3, 0x0, 0xf8, 0x8c,
    0xc4, 0x1, 0xf3, 0x68, 0x80, 0x78, 0xf2, 0x90,
    0x3, 0xff, 0x84, 0xdb, 0x20, 0x1f, 0xe5, 0xbe,
    0xa6, 0x32, 0x10, 0x8, 0x95, 0xef, 0xe4, 0x80,
    0x38,

    /* U+0039 "9" */
    0x0, 0xfe, 0x37, 0xad, 0xef, 0xf7, 0x6d, 0x39,
    0x80, 0x7f, 0xf0, 0xdb, 0x72, 0x14, 0x84, 0x0,
    0x24, 0xb1, 0x9d, 0x2, 0x1, 0xfe, 0x4d, 0x92,
    0x0, 0xff, 0xe0, 0xb, 0xf3, 0x0, 0x7e, 0x7b,
    0x20, 0xf, 0xfe, 0x2c, 0xc8, 0x3, 0xcf, 0x0,
    0x1c, 0x2b, 0x13, 0x52, 0xe6, 0x1, 0xf3, 0x40,
    0x6, 0x48, 0x0, 0xc3, 0x5d, 0x4e, 0xca, 0xd1,
    0x9d, 0x24, 0x1, 0xce, 0x40, 0x14, 0x80, 0x64,
    0xe5, 0x0, 0xfc, 0x2d, 0xae, 0x1, 0xd0, 0x0,
    0x62, 0x0, 0x8e, 0xc0, 0x3f, 0xf8, 0x31, 0x40,
    0x19, 0x0, 0x14, 0x1, 0xb8, 0x3, 0xff, 0x86,
    0xac, 0x1, 0x8, 0xc6, 0x1, 0x19, 0x0, 0x7f,
    0xf1, 0x34, 0x3, 0x11, 0x0, 0x32, 0x0, 0x7f,
    0xf1, 0x58, 0x3, 0x3b, 0x80, 0x37, 0x80, 0x7f,
    0xf1, 0x44, 0x3, 0x30, 0x7, 0x78, 0x7, 0xff,
    0x15, 0x40, 0x30, 0xb8, 0x6, 0x40, 0xf, 0xfe,
    0x2d, 0x0, 0x61, 0x20, 0xc, 0x64, 0x1, 0xff,
    0xc0, 0x15, 0x4, 0x30, 0x9, 0xc8, 0x4c, 0x3,
    0x70, 0x7, 0xfc, 0x59, 0x5b, 0x40, 0x1a, 0xc0,
    0x16, 0x1, 0x8e, 0xc4, 0x3, 0xf3, 0x61, 0x1,
    0x8, 0x4, 0x46, 0x0, 0x71, 0x0, 0xc9, 0xd0,
    0x62, 0x2, 0x71, 0xb2, 0x20, 0x1f, 0x50, 0x6,
    0xb0, 0xf, 0x3e, 0x77, 0xf6, 0x39, 0x0, 0x7f,
    0x30, 0x6, 0x58, 0x0, 0xff, 0xe4, 0xa8, 0x80,
    0x73, 0xd0, 0x7, 0xff, 0x9, 0x80, 0x3b, 0x80,
    0x3e, 0x5e, 0x60, 0xf, 0xf3, 0x6a, 0x0, 0x62,
    0x40, 0xf, 0xc3, 0x3f, 0x6c, 0x86, 0x24, 0xb3,
    0xd2, 0xa4, 0x1, 0xac, 0x3, 0xff, 0x80, 0x93,
    0x79, 0xdb, 0x4c, 0x22, 0x80, 0xc, 0x2c, 0x1,
    0xff, 0xc9, 0xa0, 0xe, 0x60, 0xf, 0xfe, 0x4a,
    0xa0, 0x7, 0x48, 0x7, 0xff, 0x20, 0x6c, 0x3,
    0x98, 0x40, 0x3f, 0xf9, 0x16, 0x20, 0x1d, 0x60,
    0x1f, 0xfc, 0x85, 0x50, 0x7, 0x21, 0x0, 0x7f,
    0xf1, 0xc6, 0xc0, 0x3d, 0xe0, 0x1f, 0xfc, 0x8d,
    0x10, 0xe, 0x34, 0x0, 0xff, 0xe3, 0x99, 0x80,
    0x3d, 0x20, 0x1f, 0xfc, 0x82, 0x0, 0xf0, 0xa8,
    0x7, 0xff, 0x20, 0x70, 0xc0, 0x34, 0x80, 0x7f,
    0xf2, 0x8f, 0x18, 0x0, 0x2c, 0x1, 0xff, 0xcc,
    0x99, 0x1d, 0x8, 0x7, 0xf0,

    /* U+003A ":" */
    0x0, 0x1d, 0xf6, 0x38, 0x4, 0x78, 0x82, 0x71,
    0x80, 0x8, 0x0, 0xe3, 0x50, 0x40, 0xf, 0x88,
    0x3, 0xe4, 0x21, 0x0, 0xe6, 0x10, 0xc2, 0x0,
    0x8e, 0x40, 0x5, 0xb7, 0x15, 0x80, 0x1c, 0x8e,
    0xa0, 0x1f, 0xff, 0xf0, 0xf, 0xfe, 0x1, 0xa9,
    0x80, 0x75, 0xe5, 0x67, 0x28, 0x1, 0xd0, 0x2,
    0x1a, 0x30, 0x90, 0xf, 0x28, 0x88, 0x3, 0xc4,
    0x40, 0xf, 0xa, 0x1a, 0x80, 0x75, 0x80, 0x2a,
    0x88, 0x5, 0x4a, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 534, .box_w = 29, .box_h = 34, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 307, .adv_w = 332, .box_w = 15, .box_h = 35, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 428, .adv_w = 534, .box_w = 29, .box_h = 36, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 724, .adv_w = 534, .box_w = 29, .box_h = 34, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1021, .adv_w = 534, .box_w = 32, .box_h = 35, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1263, .adv_w = 534, .box_w = 27, .box_h = 35, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 1544, .adv_w = 534, .box_w = 29, .box_h = 35, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1854, .adv_w = 490, .box_w = 27, .box_h = 35, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 2084, .adv_w = 534, .box_w = 29, .box_h = 35, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 2429, .adv_w = 534, .box_w = 29, .box_h = 36, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 2738, .adv_w = 283, .box_w = 9, .box_h = 26, .ofs_x = 4, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 48, .range_length = 11, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 1,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t lv_font_kslyt_48 = {
#else
lv_font_t lv_font_kslyt_48 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 36,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0)
    .underline_position = -5,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if LV_FONT_KSLYT_48*/

