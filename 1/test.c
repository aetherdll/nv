#include <stdio.h>
#include "nv.h"
#include "nv_renderer.h"
#include "nv_colors.h"
#include "nv_2d.h"
#include "nv_3d.h"
#include "nv_zbuffer.h"
#include "nv_input.h"

int main() {
    int width = 800;
    int height = 600;

    NVDevice* device = nv_device_create(width, height, "NoneVisual Engine - 3D Test");
    if (!device) {
        printf("Failed to create device!\n");
        return -1;
    }

    NVZBuffer* zbuffer = nv_zbuffer_create(width, height);
    if (!zbuffer) {
        printf("Failed to create z-buffer!\n");
        nv_device_destroy(device);
        return -1;
    }

    printf("NoneVisual Engine is running. Press ESC to exit.\n");

    while (nv_device_is_running(device)) {
        if (nv_is_key_pressed(NV_KEY_ESCAPE)) {
            break;
        }

        nv_framebuffer_clear(device->framebuffer, NV_COLOR_BLACK);
        nv_zbuffer_clear(zbuffer);

        nv_draw_rect(device, 50, 50, 100, 100, NV_COLOR_BLUE);
        nv_draw_line(device, 0, 0, width, height, NV_COLOR_RED);

        if (nv_is_key_pressed(NV_KEY_W)) {
        }

        nv_device_present(device);
    }

    nv_zbuffer_free(zbuffer);
    nv_device_destroy(device);
    printf("Engine shut down successfully.\n");
    return 0;
}