#include <string.h>
#include "extreme_maths.h"

void init() {}
void close() {}

float* _generate_f(int *size) {
    return (float*)malloc(sizeof(float) * *size);

}

v_f copy_f(float *arr, int size) {
    float* array = _generate_f(&size);

    memcpy(array, arr, sizeof(float) * size);

    v_f vec;
    vec.size = size;
    vec.array = array;
    return vec;
}

v_f point_f(float *arr, int size) {
    v_f vec;
    vec.size = size;
    vec.array = arr;
    return vec;
}

float* result_f(v_f *vec) {
    return vec->array;
}

void clean_f(v_f *vec) {
    free(vec->array);
}

void iadd_f(float *a, float *b, int *s) {
    for (int i = 0; i < *s; i++) {
        a[i] += b[i];
    }
}

void isub_f(float *a, float *b, int *s) {
    for (int i = 0; i < *s; i++) {
        a[i] -= b[i];
    }
}

void imul_f(float *a, float *b, int *s) {
    for (int i = 0; i < *s; i++) {
        a[i] *= b[i];
    }
}

void idiv_f(float *a, float *b, int *s) {
    for (int i = 0; i < *s; i++) {
        a[i] /= b[i];
    }
}

// Normal Operations 

float* add_f(float *a, float *b, int *s) {
    float* c = _generate_f(s);
    for (int i = 0; i < *s; i++) {
        c[i] = a[i] + b[i];
    }
    return c;
}

float* sub_f(float *a, float *b, int *s) {
    float* c = _generate_f(s);
    for (int i = 0; i < *s; i++) {
        c[i] = a[i] - b[i];
    }
    return c;
}

float* mul_f(float *a, float *b, int *s) {
    float* c = _generate_f(s);
    for (int i = 0; i < *s; i++) {
        c[i] = a[i] * b[i];
    }
    return c;
}

float* div_f(float *a, float *b, int *s) {
    float* c = _generate_f(s);
    for (int i = 0; i < *s; i++) {
        c[i] = a[i] / b[i];
    }
    return c;
}

// ===============================================

void iadd_v_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    iadd(a->array, b->array, &a->size);
}

void isub_v_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    isub(a->array, b->array, &a->size);
}

void imul_v_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    imul(a->array, b->array, &a->size);
}

void idiv_v_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    idiv(a->array, b->array, &a->size);
}

// Normal Operations 

v_f add_v_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }

    float* res = add(a->array, b->array, &a->size);

    v_f vec;
    vec.size = a->size;
    vec.array = res;
    return vec;
}

v_f sub_v_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    float* res = sub(a->array, b->array, &a->size);

    v_f vec;
    vec.size = a->size;
    vec.array = res;
    return vec;
}

v_f mul_v_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    float* res = mul(a->array, b->array, &a->size);

    v_f vec;
    vec.size = a->size;
    vec.array = res;
    return vec;
}

v_f div_v_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
	    exit(1);
    }

    float* res = div(a->array, b->array, &a->size);

    v_f vec;
    vec.size = a->size;
    vec.array = res;
    return vec;
}
