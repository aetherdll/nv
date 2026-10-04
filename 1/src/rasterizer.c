#include "nv.h"
#include "nv_internal.h"

void nv_clear(NVDevice* device, uint32_t color) {
    if (!device || !device->framebuffer) return;
    int total = device->framebuffer->width * device->framebuffer->height;
    uint32_t* pixels = device->framebuffer->pixels;
    for (int i = 0; i < total; i++) {
        pixels[i] = color;
    }
}