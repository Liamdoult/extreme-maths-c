#ifndef EXTREME_MATHS
#define EXTREME_MATHS
#include <stdio.h>
#include <stdlib.h>
#if __cplusplus
extern "C" {
#endif

void init();
void clean();


struct Vector_float {
    int size;
#ifdef OPENCL
    cl_mem array;
#else
    float *array;
#endif
};

struct PreOwnedVector_float {
    int size;
    float *array;
};

// ==============================================================================================================

struct Vector_float Vector_create_float(float *a, int size);
float* Vector_get_result_float(struct Vector_float *a);
void Vector_clean_float(struct Vector_float a);

/**
 * iOperations will overwrite values in the Vector_float array. This should ALWAYS be
 * preferred over normal Operations for performance reasons. value of vector a
 * will be overwritten.
 */
void Vector_iadd_float(struct Vector_float *a, struct Vector_float *b);
void Vector_iadd_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b);
void Vector_isub_float(struct Vector_float *a, struct Vector_float *b);
void Vector_isub_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b);
void Vector_imul_float(struct Vector_float *a, struct Vector_float *b);
void Vector_imul_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b);
void Vector_idiv_float(struct Vector_float *a, struct Vector_float *b);
void Vector_idiv_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b);

struct Vector_float Vector_add_float(struct Vector_float *a, struct Vector_float *b);
struct Vector_float Vector_add_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b);
struct Vector_float Vector_sub_float(struct Vector_float *a, struct Vector_float *b);
struct Vector_float Vector_sub_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b);
struct Vector_float Vector_mul_float(struct Vector_float *a, struct Vector_float *b);
struct Vector_float Vector_mul_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b);
struct Vector_float Vector_div_float(struct Vector_float *a, struct Vector_float *b);
struct Vector_float Vector_div_PreOwnedVector_float(struct Vector_float *a, struct PreOwnedVector_float *b);

// ==============================================================================================================

struct PreOwnedVector_float PreOwnedVector_create_float(float *array, int size);
float* PreOwnedVector_get_result_float(struct PreOwnedVector_float *a);
void PreOwnedVector_clean_float(struct PreOwnedVector_float a);

/*
 * Promote a PreOwnedVector_float into a full vector.
 *
 * This will result in memory assignment and copying values to memory.
 * This should only be used if the referenced array is going to be destroyed
 * and changing ownership is not possible.
 *
 * If ownership change is possible, use reference ownership transfer.
 */
struct Vector_float PreOwnedVector_to_Vector_float(struct PreOwnedVector_float a);

// TODO Transfer ownership of vector

/*
 * PreOwnedVector_float change operators.
 *
 * These operators will result in the promotion of the PreOwnedVector_float to a full
 * vector.
 */
struct Vector_float PreOwnedVector_iadd_float(struct PreOwnedVector_float a, struct PreOwnedVector_float *b);
struct Vector_float PreOwnedVector_iadd_Vector_float(struct PreOwnedVector_float a, struct Vector_float *b);
struct Vector_float PreOwnedVector_isub_float(struct PreOwnedVector_float a, struct PreOwnedVector_float *b);
struct Vector_float PreOwnedVector_isub_Vector_float(struct PreOwnedVector_float a, struct Vector_float *b);
struct Vector_float PreOwnedVector_imul_float(struct PreOwnedVector_float a, struct PreOwnedVector_float *b);
struct Vector_float PreOwnedVector_imul_Vector_float(struct PreOwnedVector_float a, struct Vector_float *b);
struct Vector_float PreOwnedVector_idiv_float(struct PreOwnedVector_float a, struct PreOwnedVector_float *b);
struct Vector_float PreOwnedVector_idiv_Vector_float(struct PreOwnedVector_float a, struct Vector_float *b);

/*
 * PreOwnedVector_float operations that will not result in promotion to a full vector.
 */
struct Vector_float PreOwnedVector_add_float(struct PreOwnedVector_float *a, struct PreOwnedVector_float *b);
struct Vector_float PreOwnedVector_add_Vector_float(struct PreOwnedVector_float *a, struct Vector_float *b);
struct Vector_float PreOwnedVector_sub_float(struct PreOwnedVector_float *a, struct PreOwnedVector_float *b);
struct Vector_float PreOwnedVector_sub_Vector_float(struct PreOwnedVector_float *a, struct Vector_float *b);
struct Vector_float PreOwnedVector_mul_float(struct PreOwnedVector_float *a, struct PreOwnedVector_float *b);
struct Vector_float PreOwnedVector_mul_Vector_float(struct PreOwnedVector_float *a, struct Vector_float *b);
struct Vector_float PreOwnedVector_div_float(struct PreOwnedVector_float *a, struct PreOwnedVector_float *b);
struct Vector_float PreOwnedVector_div_Vector_float(struct PreOwnedVector_float *a, struct Vector_float *b);

// ==============================================================================================================

struct SingleValueVector_float {
    int size;
    float value;
};

#if __cplusplus
}
#endif
#endif

