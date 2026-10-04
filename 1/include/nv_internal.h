#ifndef NV_INTERNAL_H
#define NV_INTERNAL_H

#include "nv.h"

#ifdef _WIN32
#include <windows.h>
#endif

typedef struct {
    NVDevice device;
#ifdef _WIN32
    HWND hwnd;
    HDC hdc;
    HBITMAP hbitmap;
    HDC mem_dc;
#endif
} NVInternalContext;

#endif