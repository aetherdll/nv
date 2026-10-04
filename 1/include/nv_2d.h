#ifndef NV_2D_H
#define NV_2D_H

#include "nv.h"

void nv_draw_pixel(NVDevice* device, int x, int y, uint32_t color);
void nv_draw_line(NVDevice* device, int x0, int y0, int x1, int y1, uint32_t color);
void nv_draw_rect(NVDevice* device, int x, int y, int w, int h, uint32_t color);

#endif