#ifndef NV_RENDERER_H
#define NV_RENDERER_H

#include "nv.h"

typedef struct {
    NVVector4 position;
    uint32_t color;
} NVVertex;

typedef struct {
    NVVertex* vertices;
    int count;
} NVVertexBuffer;

void nv_draw_triangle(NVDevice* device, const NVVertex* v1, const NVVertex* v2, const NVVertex* v3);
void nv_render_draw_indexed(NVDevice* device, const NVVertexBuffer* vb);

#endif