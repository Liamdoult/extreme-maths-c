#include <stdio.h>
#include <cuda.h>

#if !defined(GPU)
#error Please add -DGPU flag to build with GPU support
#endif
#include "extreme_maths.h"


__global__ void _vector_add_float(float *out, float *a, float *b) {
    out[blockIdx.x] = a[blockIdx.x] + b[blockIdx.x];
}

__global__ void _vector_iadd_float(float *a, float *b) {
    a[blockIdx.x] += b[blockIdx.x];
}

__global__ void _vector_sub_float(float *out, float *a, float *b) {
    out[blockIdx.x] = a[blockIdx.x] - b[blockIdx.x];
}

__global__ void _vector_isub_float(float *a, float *b) {
    a[blockIdx.x] -= b[blockIdx.x];
}

__global__ void _vector_mul_float(float *out, float *a, float *b) {
    out[blockIdx.x] = a[blockIdx.x] * b[blockIdx.x];
}

__global__ void _vector_imul_float(float *a, float *b) {
    a[blockIdx.x] *= b[blockIdx.x];
}

__global__ void _vector_div_float(float *out, float *a, float *b) {
    out[blockIdx.x] = a[blockIdx.x] / b[blockIdx.x];
}

__global__ void _vector_idiv_float(float *a, float *b) {
    a[blockIdx.x] /= b[blockIdx.x];
}

extern "C" {

    void init() {}
    void clean() {}

    struct Vector_float Vector_generate_float(int size) {
        float *array;
        cudaMalloc((void**)&array, sizeof(float) * size);

        struct Vector_float vec;
        vec.size = size;
        vec.array = array;
        return vec;
    }

    struct Vector_float Vector_create_float(float *a, int size) {
        Vector_float vec = Vector_generate_float(size);

        cudaMemcpy(vec.array, a, sizeof(float) * size, cudaMemcpyHostToDevice);

        return vec;
    }


    void Vector_clean_float(struct Vector_float a) {
        cudaFree(a.array);
    }


    float* Vector_get_result_float(struct Vector_float *a) {
        float *out;

        out = (float*)malloc(sizeof(float) * a->size);

        cudaMemcpy(out, a->array, sizeof(float) * a->size, cudaMemcpyDeviceToHost);

        cudaError_t err = cudaGetLastError();  // add
        if (err != cudaSuccess) {
            printf("CUDA error: %s\n", cudaGetErrorString(err));
        }

        return out;
    }

    void Vector_iadd_float(struct Vector_float *a, struct Vector_float *b) {
        _vector_iadd_float<<<a->size, 1>>>(a->array, b->array);
    }

    void Vector_isub_float(struct Vector_float *a, struct Vector_float *b) {
        _vector_isub_float<<<a->size, 1>>>(a->array, b->array);
    }

    void Vector_imul_float(struct Vector_float *a, struct Vector_float *b) {
        _vector_imul_float<<<a->size, 1>>>(a->array, b->array);
    }

    void Vector_idiv_float(struct Vector_float *a, struct Vector_float *b) {
        _vector_idiv_float<<<a->size, 1>>>(a->array, b->array);
    }

    struct Vector_float Vector_add_float(struct Vector_float *a, struct Vector_float *b) {
        Vector_float out = Vector_generate_float(a->size);

        _vector_add_float<<<a->size, 1>>>(out.array, a->array, b->array);

        return out;
    }

    struct Vector_float Vector_sub_float(struct Vector_float *a, struct Vector_float *b) {
        Vector_float out = Vector_generate_float(a->size);

        _vector_sub_float<<<a->size, 1>>>(out.array, a->array, b->array);

        return out;
    }

    struct Vector_float Vector_mul_float(struct Vector_float *a, struct Vector_float *b) {
        Vector_float out = Vector_generate_float(a->size);

        _vector_mul_float<<<a->size, 1>>>(out.array, a->array, b->array);

        return out;
    }

    struct Vector_float Vector_div_float(struct Vector_float *a, struct Vector_float *b) {
        Vector_float out = Vector_generate_float(a->size);

        _vector_div_float<<<a->size, 1>>>(out.array, a->array, b->array);

        return out;
    }

}
