#ifndef EXTREME_MATHS
#define EXTREME_MATHS
#include <stdio.h>
#include <stdlib.h>

struct Vector {
    int size;
    int* vector;
};

// add.c
int add(int *a, int *b);

// vector.c
struct Vector generate_vector(int size);
struct Vector add_vectors(struct Vector *a, struct Vector *b);
void add_to_vector(struct Vector *a, struct Vector *b);
struct Vector sub_vectors(struct Vector *a, struct Vector *b);
void sub_from_vector(struct Vector *a, struct Vector *b);
struct Vector mul_vectors(struct Vector *a, struct Vector *b);
void mul_to_vector(struct Vector *a, struct Vector *b);
void clean_vector(struct Vector a);
#endif

