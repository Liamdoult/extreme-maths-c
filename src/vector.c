#include <string.h>
#include "extreme_maths.h"

void init() {}
void clean() {}

struct Vector create_vector(float *a, int size) {
    float *array; 

    array = (float*)malloc(sizeof(float) * size);

    memcpy(array, a, sizeof(float) * size);
    
    struct Vector vec;
    vec.size = size;
    vec.array = array;
    return vec;
}

struct Vector generate_vector(int size) {
    float *array; 

    array = (float*)malloc(sizeof(float) * size);

    struct Vector vec;
    vec.size = size;
    vec.array = array;
    return vec;
}


float* get_result(struct Vector *a) {
    return a->array;
}


void clean_vector(struct Vector a) {
    free(a.array);
}

// Vector Addition
struct Vector vector_add(struct Vector *a, struct Vector *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    struct Vector c = generate_vector(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.array[i] = a->array[i] + b->array[i];
    }
    return c;
}

void vector_iadd(struct Vector *a, struct Vector *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
	exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] += b->array[i];
    }
}

// Vector Subtraction 
struct Vector vector_sub(struct Vector *a, struct Vector *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    struct Vector c = generate_vector(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.array[i] = a->array[i] - b->array[i];
    }
    return c;
}

void vector_isub(struct Vector *a, struct Vector *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
	exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] -= b->array[i];
    }
}

// Vector Multiplication
struct Vector vector_mul(struct Vector *a, struct Vector *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    struct Vector c = generate_vector(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.array[i] = a->array[i] * b->array[i];
    }
    return c;
}

void vector_imul(struct Vector *a, struct Vector *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
	    exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] *= b->array[i];
    }
}

// Vector Division 
struct Vector vector_div(struct Vector *a, struct Vector *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    struct Vector c = generate_vector(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.array[i] = a->array[i] / b->array[i];
    }
    return c;
}

void vector_idiv(struct Vector *a, struct Vector *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
	    exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] /= b->array[i];
    }
}
