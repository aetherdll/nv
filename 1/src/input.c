#include "nv_input.h"

#ifdef _WIN32
#include <windows.h>
#endif

bool nv_is_key_pressed(int key_code) {
#ifdef _WIN32
    return (GetAsyncKeyState(key_code) & 0x8000) != 0;
#else
    return false;
#endif
}