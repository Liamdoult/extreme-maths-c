#include "extreme_maths.h"

struct Vector generate_vector(int size) {
    struct Vector a;
    a.size = size;
    a.vector = calloc(size, sizeof(int));
    return a;
}

void clean_vector(struct Vector a) {
    free(a.vector);
}

// Vector Addition
struct Vector add_vectors(struct Vector *a, struct Vector *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    struct Vector c = generate_vector(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.vector[i] = a->vector[i] + b->vector[i];
    }
    return c;
}

void add_to_vector(struct Vector *a, struct Vector *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
	exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->vector[i] += b->vector[i];
    }
}

// Vector Subtraction 
struct Vector sub_vectors(struct Vector *a, struct Vector *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    struct Vector c = generate_vector(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.vector[i] = a->vector[i] - b->vector[i];
    }
    return c;
}

void sub_from_vector(struct Vector *a, struct Vector *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
	exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->vector[i] -= b->vector[i];
    }
}

// Vector Multiplication
struct Vector mul_vectors(struct Vector *a, struct Vector *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    struct Vector c = generate_vector(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.vector[i] = a->vector[i] * b->vector[i];
    }
    return c;
}

void mul_to_vector(struct Vector *a, struct Vector *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
	exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->vector[i] *= b->vector[i];
    }
}
