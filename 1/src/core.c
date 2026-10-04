#include "nv.h"
#include "nv_internal.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
static LRESULT CALLBACK window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    switch (msg) {
        case WM_DESTROY:
        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProcA(hwnd, msg, wparam, lparam);
    }
}
#endif

NVDevice* nv_device_create(int width, int height, const char* title) {
    NVDevice* device = (NVDevice*)malloc(sizeof(NVDevice));
    if (!device) return NULL;

    device->framebuffer = (NVFramebuffer*)malloc(sizeof(NVFramebuffer));
    if (!device->framebuffer) {
        free(device);
        return NULL;
    }

    device->framebuffer->width = width;
    device->framebuffer->height = height;
    device->framebuffer->pixels = (uint32_t*)malloc(width * height * sizeof(uint32_t));
    if (!device->framebuffer->pixels) {
        free(device->framebuffer);
        free(device);
        return NULL;
    }

    NVInternalContext* internal = (NVInternalContext*)malloc(sizeof(NVInternalContext));
    device->window_handle = internal;
    device->is_running = true;

#ifdef _WIN32
    HINSTANCE hInstance = GetModuleHandle(NULL);
    WNDCLASSA wc = {0};
    wc.lpfnWndProc = window_proc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "NVEngineClass";
    RegisterClassA(&wc);

    RECT rect = {0, 0, width, height};
    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW | WS_VISIBLE, FALSE);

    internal->hwnd = CreateWindowExA(
        0, "NVEngineClass", title,
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT,
        rect.right - rect.left, rect.bottom - rect.top,
        NULL, NULL, hInstance, NULL
    );

    internal->hdc = GetDC(internal->hwnd);
    internal->mem_dc = CreateCompatibleDC(internal->hdc);

    BITMAPINFO bmi = {0};
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = width;
    bmi.bmiHeader.biHeight = -height;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;

    internal->bitmap = CreateDIBSection(internal->hdc, &bmi, DIB_RGB_COLORS, &device->framebuffer->pixels, NULL, 0);
    internal->old_bitmap = (HBITMAP)SelectObject(internal->mem_dc, internal->bitmap);
#endif

    return device;
}

void nv_device_destroy(NVDevice* device) {
    if (!device || !device->window_handle) return;
    NVInternalContext* internal = (NVInternalContext*)device->window_handle;
#ifdef _WIN32
    if (internal) {
        SelectObject(internal->mem_dc, internal->old_bitmap);
        DeleteObject(internal->bitmap);
        DeleteDC(internal->mem_dc);
        ReleaseDC(internal->hwnd, internal->hdc);
        free(internal);
    }
#endif
    if (device->framebuffer) {
        free(device->framebuffer);
    }
    free(device);
}

bool nv_device_is_running(NVDevice* device) {
#ifdef _WIN32
    MSG msg;
    while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            device->is_running = false;
        }
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }
#endif
    return device->is_running;
}

void nv_device_present(NVDevice* device) {
    if (!device || !device->window_handle) return;
#ifdef _WIN32
    NVInternalContext* internal = (NVInternalContext*)device->window_handle;
    BitBlt(internal->hdc, 0, 0, device->framebuffer->width, device->framebuffer->height, internal->mem_dc, 0, 0, SRCCOPY);
#endif
}

void nv_framebuffer_clear(NVFramebuffer* fb, uint32_t color) {
    if (!fb || !fb->pixels) return;
    int total = fb->width * fb->height;
    for (int i = 0; i < total; i++) {
        fb->pixels[i] = color;
    }
}