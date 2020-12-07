#ifndef EXTREME_MATHS
#define EXTREME_MATHS
#include <stdio.h>
#include <stdlib.h>
#if __cplusplus
extern "C" {
#endif

void init();
void close();

typedef struct Vector_float {
    int size;
#ifdef OPENCL
    cl_mem array;
#else
    float *array;
#endif
} v_f;

// ==============================================================================================================

void iadd_f(v_f *a, v_f *b);
void isub_f(v_f *a, v_f *b);
void imul_f(v_f *a, v_f *b);
void idiv_f(v_f *a, v_f *b);

v_f add_f(v_f *a, v_f *b);
v_f sub_f(v_f *a, v_f *b);
v_f mul_f(v_f *a, v_f *b);
v_f div_f(v_f *a, v_f *b);

#define iadd(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: iadd_f))(X, Y)
#define isub(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: isub_f))(X, Y)
#define imul(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: imul_f))(X, Y)
#define idiv(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: idiv_f))(X, Y)

#define add(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: add_f))(X, Y)
#define sub(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: sub_f))(X, Y)
#define mul(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: mul_f))(X, Y)
#define div(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: div_f))(X, Y)

float * result_f(v_f *vec);
#define result(X) _Generic((X), v_f*: result_f)(X)

void clean_f(v_f *vec);
#define clean(X) _Generic((X), v_f*: clean_f)(X)

v_f create_f(float *arr, int size);

#if __cplusplus
}
#endif
#endif

