#ifndef NV_ZBUFFER_H
#define NV_ZBUFFER_H

#include "nv.h"

typedef struct {
    float* buffer;
    int width;
    int height;
} NVZBuffer;

NVZBuffer* nv_zbuffer_create(int width, int height);
void nv_zbuffer_clear(NVZBuffer* zbuffer);
void nv_zbuffer_free(NVZBuffer* zbuffer);

#endif