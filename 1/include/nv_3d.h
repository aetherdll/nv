#ifndef NV_3D_H
#define NV_3D_H

#include "nv.h"

typedef struct {
    NVMatrix4x4 view;
    NVMatrix4x4 projection;
    NVMatrix4x4 world;
} NVTransformState;

void nv_matrix_identity(NVMatrix4x4* mat);
void nv_matrix_perspective(NVMatrix4x4* mat, float fov, float aspect, float near, float far);
void nv_matrix_translation(NVMatrix4x4* mat, float x, float y, float z);
void nv_matrix_rotation_y(NVMatrix4x4* mat, float angle);
NVVector4 nv_vector_transform(const NVMatrix4x4* mat, const NVVector4* vec);

#endif