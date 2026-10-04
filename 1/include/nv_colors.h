#ifndef NV_COLORS_H
#define NV_COLORS_H

#include <stdint.h>

#define NV_COLOR_BLACK   0xFF000000
#define NV_COLOR_WHITE   0xFFFFFFFF
#define NV_COLOR_RED     0xFFFF0000
#define NV_COLOR_GREEN   0xFF00FF00
#define NV_COLOR_BLUE    0xFF0000FF
#define NV_COLOR_YELLOW  0xFFFFFF00
#define NV_COLOR_CYAN    0xFF00FFFF
#define NV_COLOR_MAGENTA 0xFFFF00FF

typedef struct {
    uint8_t r, g, b, a;
} NVColor;

uint32_t nv_color_pack(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
NVColor nv_color_unpack(uint32_t color);
uint32_t nv_color_lerp(uint32_t c1, uint32_t c2, float t);

#endif