#include "nv_colors.h"

uint32_t nv_color_pack(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    return ((uint32_t)a << 24) | ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
}

NVColor nv_color_unpack(uint32_t color) {
    NVColor c;
    c.a = (color >> 24) & 0xFF;
    c.r = (color >> 16) & 0xFF;
    c.g = (color >> 8) & 0xFF;
    c.b = color & 0xFF;
    return c;
}

uint32_t nv_color_lerp(uint32_t c1, uint32_t c2, float t) {
    if (t <= 0.0f) return c1;
    if (t >= 1.0f) return c2;

    NVColor col1 = nv_color_unpack(c1);
    NVColor col2 = nv_color_unpack(c2);

    uint8_t r = (uint8_t)(col1.r + (float)(col2.r - col1.r) * t);
    uint8_t g = (uint8_t)(col1.g + (float)(col2.g - col1.g) * t);
    uint8_t b = (uint8_t)(col1.b + (float)(col2.b - col1.b) * t);
    uint8_t a = (uint8_t)(col1.a + (float)(col2.a - col1.a) * t);

    return nv_color_pack(r, g, b, a);
}