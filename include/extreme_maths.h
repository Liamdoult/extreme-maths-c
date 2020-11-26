#ifndef EXTREME_MATHS
#define EXTREME_MATHS
#include <stdio.h>
#include <stdlib.h>
#if __cplusplus
extern "C" {
#endif

struct Vector {
    int size;
    float *array;
};

struct Vector create_vector(float *a, int size);
float* get_result(struct Vector *a);

void vector_iadd(struct Vector *a, struct Vector *b);
struct Vector vector_add(struct Vector *a, struct Vector *b);

void vector_isub(struct Vector *a, struct Vector *b);
struct Vector vector_sub(struct Vector *a, struct Vector *b);

void vector_imul(struct Vector *a, struct Vector *b);
struct Vector vector_mul(struct Vector *a, struct Vector *b);

void vector_idiv(struct Vector *a, struct Vector *b);
struct Vector vector_div(struct Vector *a, struct Vector *b);

void clean_vector(struct Vector a);

#if __cplusplus
}
#endif
#endif

