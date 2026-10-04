#include "nv_zbuffer.h"
#include <stdlib.h>

NVZBuffer* nv_zbuffer_create(int width, int height) {
    NVZBuffer* zb = (NVZBuffer*)malloc(sizeof(NVZBuffer));
    if (!zb) return NULL;
    zb->width = width;
    zb->height = height;
    zb->buffer = (float*)malloc(width * height * sizeof(float));
    if (!zb->buffer) {
        free(zb);
        return NULL;
    }
    nv_zbuffer_clear(zb);
    return zb;
}

void nv_zbuffer_clear(NVZBuffer* zbuffer) {
    if (!zbuffer || !zbuffer->buffer) return;
    int total = zbuffer->width * zbuffer->height;
    for (int i = 0; i < total; i++) {
        zbuffer->buffer[i] = 1.0f;
    }
}

void nv_zbuffer_free(NVZBuffer* zbuffer) {
    if (!zbuffer) return;
    if (zbuffer->buffer) free(zbuffer->buffer);
    free(zbuffer);
}