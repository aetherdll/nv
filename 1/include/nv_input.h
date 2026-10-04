#ifndef NV_INPUT_H
#define NV_INPUT_H

#include "nv.h"
#include <stdbool.h>

#define NV_KEY_BACKSPACE 0x08
#define NV_KEY_TAB 0x09
#define NV_KEY_ENTER 0x0D
#define NV_KEY_SHIFT 0x10
#define NV_KEY_CONTROL 0x11
#define NV_KEY_ALT 0x12
#define NV_KEY_ESCAPE 0x1B
#define NV_KEY_SPACE 0x20

#define NV_KEY_LEFT 0x25
#define NV_KEY_UP 0x26
#define NV_KEY_RIGHT 0x27
#define NV_KEY_DOWN 0x28

#define NV_KEY_0 0x30
#define NV_KEY_1 0x31
#define NV_KEY_2 0x32
#define NV_KEY_3 0x33
#define NV_KEY_4 0x34
#define NV_KEY_5 0x35
#define NV_KEY_6 0x36
#define NV_KEY_7 0x37
#define NV_KEY_8 0x38
#define NV_KEY_9 0x39

#define NV_KEY_A 0x41
#define NV_KEY_B 0x42
#define NV_KEY_C 0x43
#define NV_KEY_D 0x44
#define NV_KEY_E 0x45
#define NV_KEY_F 0x46
#define NV_KEY_G 0x47
#define NV_KEY_H 0x48
#define NV_KEY_I 0x49
#define NV_KEY_J 0x4A
#define NV_KEY_K 0x4B
#define NV_KEY_L 0x4C
#define NV_KEY_M 0x4D
#define NV_KEY_N 0x4E
#define NV_KEY_O 0x4F
#define NV_KEY_P 0x50
#define NV_KEY_Q 0x51
#define NV_KEY_R 0x52
#define NV_KEY_S 0x53
#define NV_KEY_T 0x54
#define NV_KEY_U 0x55
#define NV_KEY_V 0x56
#define NV_KEY_W 0x57
#define NV_KEY_X 0x58
#define NV_KEY_Y 0x59
#define NV_KEY_Z 0x5A

#define NV_KEY_F1 0x70
#define NV_KEY_F2 0x71
#define NV_KEY_F3 0x72
#define NV_KEY_F4 0x73
#define NV_KEY_F5 0x74
#define NV_KEY_F6 0x75
#define NV_KEY_F7 0x76
#define NV_KEY_F8 0x77
#define NV_KEY_F9 0x78
#define NV_KEY_F10 0x79
#define NV_KEY_F11 0x7A
#define NV_KEY_F12 0x7B

bool nv_is_key_pressed(int key_code);

#endif