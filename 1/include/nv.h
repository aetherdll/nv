#ifndef NV_H
#define NV_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint32_t* pixels;
    int width;
    int height;
} NVFramebuffer;

typedef struct {
    void* window_handle;
    void* device_context;
    void* bitmap_memory;
    NVFramebuffer* framebuffer;
    bool is_running;
} NVDevice;

typedef struct {
    float x, y, z, w;
} NVVector4;

typedef struct {
    float m[4][4];
} NVMatrix4x4;

NVDevice* nv_device_create(int width, int height, const char* title);
void nv_device_destroy(NVDevice* device);
bool nv_device_is_running(NVDevice* device);
void nv_device_present(NVDevice* device);
void nv_framebuffer_clear(NVFramebuffer* fb, uint32_t color);

#endif