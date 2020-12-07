#include <string.h>
#include "extreme_maths.h"

void init() {}
void close() {}

v_f _generate_f(int size) {
    float *array; 

    array = (float*)malloc(sizeof(float) * size);

    v_f vec;
    vec.size = size;
    vec.array = array;
    return vec;
}

v_f create_f(float *arr, int size) {
    v_f vec = _generate_f(size);

    memcpy(vec.array, arr, sizeof(float) * size);

    struct Vector vec;
    vec.size = size;
    vec.array = array;
    return vec;
}

float* result_f(v_f *vec) {
    return vec->array;
}

void clean_f(v_f *vec) {
    free(vec->array);
}

void iadd_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] += b->array[i];
    }
}

void isub_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] -= b->array[i];
    }
}

void imul_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] *= b->array[i];
    }
}

void idiv_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] /= b->array[i];
    }
}

// Normal Operations 

v_f add_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
	exit(1);
    }
    v_f c = _generate_f(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.array[i] = a->array[i] + b->array[i];
    }
}

v_f sub_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    v_f c = _generate_f(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.array[i] = a->array[i] - b->array[i];
    }
    return c;
}

v_f mul_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
	exit(1);
    }
    v_f c = _generate_f(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.array[i] = a->array[i] * b->array[i];
    }
    return c;
}

v_f div_f(v_f *a, v_f *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
	    exit(1);
    }
    v_f c = _generate_f(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.array[i] = a->array[i] / b->array[i];
    }
    return c;
}
