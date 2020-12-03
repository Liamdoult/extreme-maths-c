#include <string.h>
#include <sys/mman.h>
#include "extreme_maths.h"

void init() {}
void clean() {}

// ===================================================== VECTOR ============================================

/**
 * Create an empty vector.
 */
struct Vector_float _Vector_generate_float(int size) {
    float *array; 

    array = (float*)malloc(sizeof(float) * size);

    struct Vector_float vec;
    vec.size = size;
    vec.array = array;
    return vec;
}

/**
 * Create memory space and copy values from *a.
 *
 * This is a slow function and should be avoided.
 *
 * Try use `PreOwnedVector_create` or `SingleValueVector_create` if possible.
 */
struct Vector_float Vector_create_float(float *a, int size) {
    struct Vector_float vec = _Vector_generate_float(size);

    memcpy(vec.array, a, sizeof(float) * size);

    return vec;
}


float* Vector_get_result_float(struct Vector_float *a) {
    return a->array;
}


void Vector_clean_float(struct Vector_float a) {
    free(a.array);
}

// iOperations

void Vector_iadd_float(struct Vector_float *a, struct Vector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] += b->array[i];
    }
}

void Vector_iadd_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] += b->array[i];
    }
}

void Vector_isub_float(struct Vector_float *a, struct Vector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] -= b->array[i];
    }
}

void Vector_isub_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] -= b->array[i];
    }
}

void Vector_imul_float(struct Vector_float *a, struct Vector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] *= b->array[i];
    }
}

void Vector_imul_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] *= b->array[i];
    }
}

void Vector_idiv_float(struct Vector_float *a, struct Vector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] /= b->array[i];
    }
}

void Vector_idiv_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    for (int i = 0; i < a->size; i++) {
        a->array[i] /= b->array[i];
    }
}


// Normal Operations 

struct Vector_float Vector_add_float(struct Vector_float *a, struct Vector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    struct Vector_float c = _Vector_generate_float(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.array[i] = a->array[i] + b->array[i];
    }
    return c;
}

struct Vector_float Vector_add_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    struct Vector_float c = _Vector_generate_float(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.array[i] = a->array[i] + b->array[i];
    }
    return c;
}

struct Vector_float Vector_sub_float(struct Vector_float *a, struct Vector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    struct Vector_float c = _Vector_generate_float(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.array[i] = a->array[i] - b->array[i];
    }
    return c;
}

struct Vector_float Vector_sub_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    struct Vector_float c = _Vector_generate_float(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.array[i] = a->array[i] - b->array[i];
    }
    return c;
}

struct Vector_float Vector_mul_float(struct Vector_float *a, struct Vector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    struct Vector_float c = _Vector_generate_float(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.array[i] = a->array[i] * b->array[i];
    }
    return c;
}

struct Vector_float Vector_mul_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    struct Vector_float c = _Vector_generate_float(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.array[i] = a->array[i] * b->array[i];
    }
    return c;
}

struct Vector_float Vector_div_float(struct Vector_float *a, struct Vector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    struct Vector_float c = _Vector_generate_float(a->size);
    for (int i = 0; i < a -> size; i++) {
        c.array[i] = a->array[i] / b->array[i];
    }
    return c;
}

struct Vector_float Vector_div_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b) {
    if (a->size != b->size) {
        printf("Invalid sizes");
        exit(1);
    }
    struct Vector_float c = _Vector_generate_float(a->size);
    for (int i = 0; i < a->size; i++) {
        c.array[i] = a->array[i] / b->array[i];
    }
    return c;
}


// ===================================================== PreOwnedVector ============================================


/**
 * Create Vector and point to existing space *a.
 */
struct PreOwnedVector_float PreOwnedVector_create_float(float *array, int size) {
    struct PreOwnedVector_float vec;
    vec.size = size;
    vec.array = array;
    return vec;
}


float* PreOwnedVector_get_result_float(struct PreOwnedVector_float *a) {
    return a->array;
}


void PreOwnedVector_clean_float(struct PreOwnedVector_float a) {
}

struct Vector_float PreOwnedVector_to_Vector_float(struct PreOwnedVector_float a) {
    return Vector_create_float(a.array, a.size);
}

// iOperations

struct Vector_float PreOwnedVector_iadd_float(struct PreOwnedVector_float a, struct PreOwnedVector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a.size);

    for (int i=0; i < a.size; i++)
        vec.array[i] = a.array[i] + b->array[i];

    PreOwnedVector_clean_float(a);
    return vec;
}

struct Vector_float PreOwnedVector_iadd_Vector_float(struct PreOwnedVector_float a, struct Vector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a.size);

    for (int i=0; i < a.size; i++)
        vec.array[i] = a.array[i] + b->array[i];

    PreOwnedVector_clean_float(a);
    return vec;
}

struct Vector_float PreOwnedVector_isub_float(struct PreOwnedVector_float a, struct PreOwnedVector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a.size);

    for (int i=0; i < a.size; i++)
        vec.array[i] = a.array[i] - b->array[i];

    PreOwnedVector_clean_float(a);
    return vec;
}

struct Vector_float PreOwnedVector_isub_Vector_float(struct PreOwnedVector_float a, struct Vector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a.size);

    for (int i=0; i < a.size; i++)
        vec.array[i] = a.array[i] - b->array[i];

    PreOwnedVector_clean_float(a);
    return vec;
}

struct Vector_float PreOwnedVector_imul_float(struct PreOwnedVector_float a, struct PreOwnedVector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a.size);

    for (int i=0; i < a.size; i++)
        vec.array[i] = a.array[i] * b->array[i];

    PreOwnedVector_clean_float(a);
    return vec;
}

struct Vector_float PreOwnedVector_imul_Vector_float(struct PreOwnedVector_float a, struct Vector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a.size);

    for (int i=0; i < a.size; i++)
        vec.array[i] = a.array[i] * b->array[i];

    PreOwnedVector_clean_float(a);
    return vec;
}

struct Vector_float PreOwnedVector_idiv_float(struct PreOwnedVector_float a, struct PreOwnedVector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a.size);

    for (int i=0; i < a.size; i++)
        vec.array[i] = a.array[i] / b->array[i];

    PreOwnedVector_clean_float(a);
    return vec;
}

struct Vector_float PreOwnedVector_idiv_Vector_float(struct PreOwnedVector_float a, struct Vector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a.size);

    for (int i=0; i < a.size; i++)
        vec.array[i] = a.array[i] / b->array[i];

    PreOwnedVector_clean_float(a);
    return vec;
}

// Normal Operations

struct Vector_float PreOwnedVector_add_float(struct PreOwnedVector_float *a, struct PreOwnedVector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a->size);

    for (int i=0; i < a->size; i++)
        vec.array[i] = a->array[i] + b->array[i];

    return vec;
}

struct Vector_float PreOwnedVector_add_Vector_float(struct PreOwnedVector_float *a, struct Vector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a->size);

    for (int i=0; i < a->size; i++)
        vec.array[i] = a->array[i] + b->array[i];

    return vec;
}

struct Vector_float PreOwnedVector_sub_float(struct PreOwnedVector_float *a, struct PreOwnedVector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a->size);

    for (int i=0; i < a->size; i++)
        vec.array[i] = a->array[i] - b->array[i];

    return vec;
}

struct Vector_float PreOwnedVector_sub_Vector_float(struct PreOwnedVector_float *a, struct Vector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a->size);

    for (int i=0; i < a->size; i++)
        vec.array[i] = a->array[i] - b->array[i];

    return vec;
}

struct Vector_float PreOwnedVector_mul_float(struct PreOwnedVector_float *a, struct PreOwnedVector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a->size);

    for (int i=0; i < a->size; i++)
        vec.array[i] = a->array[i] * b->array[i];

    return vec;
}

struct Vector_float PreOwnedVector_mul_Vector_float(struct PreOwnedVector_float *a, struct Vector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a->size);

    for (int i=0; i < a->size; i++)
        vec.array[i] = a->array[i] * b->array[i];

    return vec;
}

struct Vector_float PreOwnedVector_div_float(struct PreOwnedVector_float *a, struct PreOwnedVector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a->size);

    for (int i=0; i < a->size; i++)
        vec.array[i] = a->array[i] / b->array[i];

    return vec;
}

struct Vector_float PreOwnedVector_div_Vector_float(struct PreOwnedVector_float *a, struct Vector_float *b) {
    struct Vector_float vec = _Vector_generate_float(a->size);

    for (int i=0; i < a->size; i++)
        vec.array[i] = a->array[i] / b->array[i];

    return vec;
}
