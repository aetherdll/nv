#include "nv.h"
#include "nv_renderer.h"
#include <stdlib.h>

static void draw_flat_triangle(NVDevice* device, NVVertex v1, NVVertex v2, NVVertex v3) {
    if (!device || !device->framebuffer) return;
    
    int width = device->framebuffer->width;
    int height = device->framebuffer->height;
    uint32_t* pixels = device->framebuffer->pixels;

    if (v1.position.y > v2.position.y) { NVVertex t = v1; v1 = v2; v2 = t; }
    if (v1.position.y > v3.position.y) { NVVertex t = v1; v1 = v3; v3 = t; }
    if (v2.position.y > v3.position.y) { NVVertex t = v2; v2 = v3; v3 = t; }

    int y1 = (int)v1.position.y;
    int y2 = (int)v2.position.y;
    int y3 = (int)v3.position.y;

    for (int y = y1; y <= y3; y++) {
        if (y < 0 || y >= height) continue;
        
        int total_height = y3 - y1;
        if (total_height == 0) continue;
        
        float alpha = (float)(y - y1) / (float)total_height;
        float beta = (float)(y - (y < y2 ? y1 : y2)) / (float)(y < y2 ? (y2 - y1 ? y2 - y1 : 1) : (y3 - y2 ? y3 - y2 : 1));

        int xa = (int)(v1.position.x + (v3.position.x - v1.position.x) * alpha);
        int xb = (int)(y < y2 ? (v1.position.x + (v2.position.x - v1.position.x) * (float)(y - y1) / (y2 - y1 ? y2 - y1 : 1)) 
                              : (v2.position.x + (v3.position.x - v2.position.x) * (float)(y - y2) / (y3 - y2 ? y3 - y2 : 1)));

        if (xa > xb) { int t = xa; xa = xb; xb = t; }

        for (int x = xa; x <= xb; x++) {
            if (x < 0 || x >= width) continue;
            pixels[y * width + x] = v1.color;
        }
    }
}

void nv_draw_triangle(NVDevice* device, const NVVertex* v1, const NVVertex* v2, const NVVertex* v3) {
    draw_flat_triangle(device, *v1, *v2, *v3);
}

void nv_render_draw_indexed(NVDevice* device, const NVVertexBuffer* vb) {
    if (!vb || vb->count < 3) return;
    for (int i = 0; i < vb->count; i += 3) {
        if (i + 2 < vb->count) {
            nv_draw_triangle(device, &vb->vertices[i], &vb->vertices[i+1], &vb->vertices[i+2]);
        }
    }
}
