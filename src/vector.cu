#include <stdio.h>
#include <cuda.h>
#include "extreme_maths.h"


__global__ void _vector_add(float *out, float *a, float *b) {
    out[blockIdx.x] = a[blockIdx.x] + b[blockIdx.x];
}

__global__ void _vector_iadd(float *a, float *b) {
    a[blockIdx.x] += b[blockIdx.x];
}

__global__ void _vector_sub(float *out, float *a, float *b) {
    out[blockIdx.x] = a[blockIdx.x] - b[blockIdx.x];
}

__global__ void _vector_isub(float *a, float *b) {
    a[blockIdx.x] -= b[blockIdx.x];
}

__global__ void _vector_mul(float *out, float *a, float *b) {
    out[blockIdx.x] = a[blockIdx.x] * b[blockIdx.x];
}

__global__ void _vector_imul(float *a, float *b) {
    a[blockIdx.x] *= b[blockIdx.x];
}

__global__ void _vector_div(float *out, float *a, float *b) {
    out[blockIdx.x] = a[blockIdx.x] / b[blockIdx.x];
}

__global__ void _vector_idiv(float *a, float *b) {
    a[blockIdx.x] /= b[blockIdx.x];
}

extern "C" {
     
    struct Vector create_vector(float *a, int size) {
        float *array;

        cudaMalloc((void**)&array, sizeof(float) * size);
        cudaMemcpy(array, a, sizeof(float) * size, cudaMemcpyHostToDevice);

        struct Vector vec;
        vec.size = size;
        vec.array = array;
        return vec;
    }

    void clean_vector(struct Vector a) {
        cudaFree(a.array);
    }


    float* get_result(struct Vector *a) {
        float *out;

        out = (float*)malloc(sizeof(float) * a->size);

        cudaMemcpy(out, a->array, sizeof(float) * a->size, cudaMemcpyDeviceToHost);

        cudaError_t err = cudaGetLastError();  // add
        if (err != cudaSuccess) {
            printf("CUDA error: %s\n", cudaGetErrorString(err));
        }

        return out;
    }

    void vector_iadd(struct Vector *a, struct Vector *b) { _vector_iadd<<<a->size, 1>>>(a->array, b->array);
    }

    struct Vector vector_add(struct Vector *a, struct Vector *b) {
        float *array;

        cudaMalloc((void**)&array, sizeof(float) * a->size);

        _vector_add<<<a->size, 1>>>(array, a->array, b->array);

        struct Vector vec;
        vec.size = a->size;
        vec.array = array;
        return vec;

    }

    void vector_isub(struct Vector *a, struct Vector *b) {
        _vector_isub<<<a->size, 1>>>(a->array, b->array);
    }

    struct Vector vector_sub(struct Vector *a, struct Vector *b) {
        float *array;

        cudaMalloc((void**)&array, sizeof(float) * a->size);

        _vector_sub<<<a->size, 1>>>(array, a->array, b->array);

        struct Vector vec;
        vec.size = a->size;
        vec.array = array;
        return vec;

    }

    void vector_imul(struct Vector *a, struct Vector *b) {
        _vector_imul<<<a->size, 1>>>(a->array, b->array);
    }

    struct Vector vector_mul(struct Vector *a, struct Vector *b) {
        float *array;

        cudaMalloc((void**)&array, sizeof(float) * a->size);

        _vector_mul<<<a->size, 1>>>(array, a->array, b->array);

        struct Vector vec;
        vec.size = a->size;
        vec.array = array;
        return vec;

    }

    void vector_idiv(struct Vector *a, struct Vector *b) {
        _vector_idiv<<<a->size, 1>>>(a->array, b->array);
    }

    struct Vector vector_div(struct Vector *a, struct Vector *b) {
        float *array;

        cudaMalloc((void**)&array, sizeof(float) * a->size);

        _vector_div<<<a->size, 1>>>(array, a->array, b->array);

        struct Vector vec;
        vec.size = a->size;
        vec.array = array;
        return vec;

    }


}
