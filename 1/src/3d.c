#include "nv_3d.h"
#include <math.h>

void nv_matrix_identity(NVMatrix4x4* mat) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            mat->m[i][j] = (i == j) ? 1.0f : 0.0f;
        }
    }
}

void nv_matrix_perspective(NVMatrix4x4* mat, float fov, float aspect, float near, float far) {
    nv_matrix_identity(mat);
    float tan_half_fov = tanf(fov / 2.0f);
    mat->m[0][0] = 1.0f / (aspect * tan_half_fov);
    mat->m[1][1] = 1.0f / tan_half_fov;
    mat->m[2][2] = far / (far - near);
    mat->m[2][3] = 1.0f;
    mat->m[3][2] = (-far * near) / (far - near);
    mat->m[3][3] = 0.0f;
}

void nv_matrix_translation(NVMatrix4x4* mat, float x, float y, float z) {
    nv_matrix_identity(mat);
    mat->m[3][0] = x;
    mat->m[3][1] = y;
    mat->m[3][2] = z;
}

void nv_matrix_rotation_y(NVMatrix4x4* mat, float angle) {
    nv_matrix_identity(mat);
    float c = cosf(angle);
    float s = sinf(angle);
    mat->m[0][0] = c;
    mat->m[0][2] = -s;
    mat->m[2][0] = s;
    mat->m[2][2] = c;
}

NVVector4 nv_vector_transform(const NVMatrix4x4* mat, const NVVector4* vec) {
    NVVector4 res;
    res.x = vec->x * mat->m[0][0] + vec->y * mat->m[1][0] + vec->z * mat->m[2][0] + vec->w * mat->m[3][0];
    res.y = vec->x * mat->m[0][1] + vec->y * mat->m[1][1] + vec->z * mat->m[2][1] + vec->w * mat->m[3][1];
    res.z = vec->x * mat->m[0][2] + vec->y * mat->m[1][2] + vec->z * mat->m[2][2] + vec->w * mat->m[3][2];
    res.w = vec->x * mat->m[0][3] + vec->y * mat->m[1][3] + vec->z * mat->m[2][3] + vec->w * mat->m[3][3];
    return res;
}