#include "nv_2d.h"
#include <stdlib.h>

void nv_draw_pixel(NVDevice* device, int x, int y, uint32_t color) {
    if (!device || !device->framebuffer) return;
    if (x < 0 || x >= device->framebuffer->width || y < 0 || y >= device->framebuffer->height) return;
    device->framebuffer->pixels[y * device->framebuffer->width + x] = color;
}

void nv_draw_line(NVDevice* device, int x0, int y0, int x1, int y1, uint32_t color) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    while (1) {
        nv_draw_pixel(device, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void nv_draw_rect(NVDevice* device, int x, int y, int w, int h, uint32_t color) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            nv_draw_pixel(device, x + j, y + i, color);
        }
    }
}