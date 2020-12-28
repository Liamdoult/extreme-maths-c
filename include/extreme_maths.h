#ifndef EXTREME_MATHS
#define EXTREME_MATHS
#include <stdio.h>
#include <stdlib.h>
#if __cplusplus
extern "C" {
#endif

void init();

typedef struct Vector_float {
    int size;
    float* array;
} v_f;

// ==============================================================================================================

void iadd_f(float *a, float *b, int *s);
void isub_f(float *a, float *b, int *s);
void imul_f(float *a, float *b, int *s);
void idiv_f(float *a, float *b, int *s);

float* add_f(float *a, float *b, int *s);
float* sub_f(float *a, float *b, int *s);
float* mul_f(float *a, float *b, int *s);
float* div_f(float *a, float *b, int *s);

#define iadd(X, Y, s) _Generic((X), float*: _Generic((Y), float*: iadd_f))(X, Y, s)
#define isub(X, Y, s) _Generic((X), float*: _Generic((Y), float*: isub_f))(X, Y, s)
#define imul(X, Y, s) _Generic((X), float*: _Generic((Y), float*: imul_f))(X, Y, s)
#define idiv(X, Y, s) _Generic((X), float*: _Generic((Y), float*: idiv_f))(X, Y, s)

#define add(X, Y, s) _Generic((X), float*: _Generic((Y), float*: add_f))(X, Y, s)
#define sub(X, Y, s) _Generic((X), float*: _Generic((Y), float*: sub_f))(X, Y, s)
#define mul(X, Y, s) _Generic((X), float*: _Generic((Y), float*: mul_f))(X, Y, s)
#define div(X, Y, s) _Generic((X), float*: _Generic((Y), float*: div_f))(X, Y, s)

void iadd_v_f(v_f *a, v_f *b);
void isub_v_f(v_f *a, v_f *b);
void imul_v_f(v_f *a, v_f *b);
void idiv_v_f(v_f *a, v_f *b);

v_f add_v_f(v_f *a, v_f *b);
v_f sub_v_f(v_f *a, v_f *b);
v_f mul_v_f(v_f *a, v_f *b);
v_f div_v_f(v_f *a, v_f *b);

#define iadd_v(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: iadd_v_f))(X, Y)
#define isub_v(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: isub_v_f))(X, Y)
#define imul_v(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: imul_v_f))(X, Y)
#define idiv_v(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: idiv_v_f))(X, Y)

#define add_v(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: add_v_f))(X, Y)
#define sub_v(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: sub_v_f))(X, Y)
#define mul_v(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: mul_v_f))(X, Y)
#define div_v(X, Y) _Generic((X), v_f*: _Generic((Y), v_f*: div_v_f))(X, Y)

float * result_f(v_f *vec);
#define result(X) _Generic((X), v_f*: result_f)(X)

void clean_f(v_f *vec);
#define clean(X) _Generic((X), v_f*: clean_f)(X)

v_f copy_f(float *arr, int size);
v_f point_f(float *arr, int size);

#if __cplusplus
}
#endif
#endif

