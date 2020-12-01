#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <pthread.h>

#include "extreme_maths.h"

int THREADS =  8;

struct ThreadArgs {
    float *out;
    float *a;
    float *b;
    int c;
    int i;
};

struct ThreadiArgs {
    float *a;
    float *b;
    int c;
    int i;
};

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

void init() {};
void clean() {};

void clean_vector(struct Vector a) {
    free(a.array);
}

void *_vector_add(void *ptr) {
    struct ThreadArgs *args = (struct ThreadArgs *)ptr;
    float *out, *a, *b;
    int s, e, c, i;

    out = args->out;
    a = args->a;
    b = args->b;
    c = args->c;
    i = args->i;

    s = i * c;
    e = (i + 1) * c;

    for(int i = s; i < e; i++){
        out[i] = a[i] + b[i];
    }
}

void *_vector_iadd(void *ptr) {
    struct ThreadiArgs *args = (struct ThreadiArgs *)ptr;
    float *a, *b;
    int s, e, c, i;

    a = args->a;
    b = args->b;
    c = args->c;
    i = args->i;

    s = i * c;
    e = (i + 1) * c;

    for(int i = s; i < e; i++){
        a[i] += b[i];
    }
}

struct Vector vector_add(struct Vector *a, struct Vector *b) {
    struct Vector res = generate_vector(a->size);

    int _threads = THREADS < a->size? THREADS : a->size;

    int chunk_size = a->size/_threads;

    pthread_t threads[_threads];
    
    struct ThreadArgs vas[_threads];

    int i;
    for (i = 0; i < _threads; i++) {
        vas[i].out = res.array;
        vas[i].a = a->array;
        vas[i].b = b->array;
        vas[i].c = chunk_size;
        vas[i].i = i;
        pthread_create(&threads[i], NULL, _vector_add, (void *)&vas[i]); 
    }
    for (i = 0; i < _threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return res;
}

void vector_iadd(struct Vector *a, struct Vector *b) {
    int _threads = THREADS < a->size? THREADS : a->size;

    int chunk_size = a->size/_threads;

    pthread_t threads[_threads];
    
    struct ThreadiArgs vas[_threads];

    int i;
    for (i = 0; i < _threads; i++) {
        vas[i].a = a->array;
        vas[i].b = b->array;
        vas[i].c = chunk_size;
        vas[i].i = i;
        pthread_create(&threads[i], NULL, _vector_iadd, (void *)&vas[i]); 
    }
    for (i = 0; i < _threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

void *_vector_sub(void *ptr) {
    struct ThreadArgs *args = (struct ThreadArgs *)ptr;
    float *out, *a, *b;
    int s, e, c, i;

    out = args->out;
    a = args->a;
    b = args->b;
    c = args->c;
    i = args->i;

    s = i * c;
    e = (i + 1) * c;

    for(int i = s; i < e; i++){
        out[i] = a[i] - b[i];
    }
}

void *_vector_isub(void *ptr) {
    struct ThreadiArgs *args = (struct ThreadiArgs *)ptr;
    float *a, *b;
    int s, e, c, i;

    a = args->a;
    b = args->b;
    c = args->c;
    i = args->i;

    s = i * c;
    e = (i + 1) * c;

    for(int i = s; i < e; i++){
        a[i] -= b[i];
    }
}

struct Vector vector_sub(struct Vector *a, struct Vector *b) {
    struct Vector res = generate_vector(a->size);

    int _threads = THREADS < a->size? THREADS : a->size;

    int chunk_size = a->size/_threads;

    pthread_t threads[_threads];
    
    struct ThreadArgs vas[_threads];

    int i;
    for (i = 0; i < _threads; i++) {
        vas[i].out = res.array;
        vas[i].a = a->array;
        vas[i].b = b->array;
        vas[i].c = chunk_size;
        vas[i].i = i;
        pthread_create(&threads[i], NULL, _vector_sub, (void *)&vas[i]); 
    }
    for (i = 0; i < _threads; i++) {
        int rval = pthread_join(threads[i], NULL);
    }

    return res;
}

void vector_isub(struct Vector *a, struct Vector *b) {
    int _threads = THREADS < a->size? THREADS : a->size;

    int chunk_size = a->size/_threads;

    pthread_t threads[_threads];
    
    struct ThreadiArgs vas[_threads];

    int i;
    for (i = 0; i < _threads; i++) {
        vas[i].a = a->array;
        vas[i].b = b->array;
        vas[i].c = chunk_size;
        vas[i].i = i;
        pthread_create(&threads[i], NULL, _vector_isub, (void *)&vas[i]); 
    }
    for (i = 0; i < _threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

void *_vector_mul(void *ptr) {
    struct ThreadArgs *args = (struct ThreadArgs *)ptr;
    float *out, *a, *b;
    int s, e, c, i;

    out = args->out;
    a = args->a;
    b = args->b;
    c = args->c;
    i = args->i;

    s = i * c;
    e = (i + 1) * c;

    for(int i = s; i < e; i++){
        out[i] = a[i] * b[i];
    }
}

void *_vector_imul(void *ptr) {
    struct ThreadiArgs *args = (struct ThreadiArgs *)ptr;
    float *a, *b;
    int s, e, c, i;

    a = args->a;
    b = args->b;
    c = args->c;
    i = args->i;

    s = i * c;
    e = (i + 1) * c;

    for(int i = s; i < e; i++){
        a[i] *= b[i];
    }
}

struct Vector vector_mul(struct Vector *a, struct Vector *b) {
    struct Vector res = generate_vector(a->size);

    int _threads = THREADS < a->size? THREADS : a->size;

    int chunk_size = a->size/_threads;

    pthread_t threads[_threads];
    
    struct ThreadArgs vas[_threads];

    int i;
    for (i = 0; i < _threads; i++) {
        vas[i].out = res.array;
        vas[i].a = a->array;
        vas[i].b = b->array;
        vas[i].c = chunk_size;
        vas[i].i = i;
        pthread_create(&threads[i], NULL, _vector_mul, (void *)&vas[i]); 
    }
    for (i = 0; i < _threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return res;
}

void vector_imul(struct Vector *a, struct Vector *b) {
    int _threads = THREADS < a->size? THREADS : a->size;

    int chunk_size = a->size/_threads;

    pthread_t threads[_threads];
    
    struct ThreadiArgs vas[_threads];

    int i;
    for (i = 0; i < _threads; i++) {
        vas[i].a = a->array;
        vas[i].b = b->array;
        vas[i].c = chunk_size;
        vas[i].i = i;
        pthread_create(&threads[i], NULL, _vector_imul, (void *)&vas[i]); 
    }
    for (i = 0; i < _threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

void *_vector_div(void *ptr) {
    struct ThreadArgs *args = (struct ThreadArgs *)ptr;
    float *out, *a, *b;
    int s, e, c, i;

    out = args->out;
    a = args->a;
    b = args->b;
    c = args->c;
    i = args->i;

    s = i * c;
    e = (i + 1) * c;

    for(int i = s; i < e; i++){
        out[i] = a[i] / b[i];
    }
}

void *_vector_idiv(void *ptr) {
    struct ThreadiArgs *args = (struct ThreadiArgs *)ptr;
    float *a, *b;
    int s, e, c, i;

    a = args->a;
    b = args->b;
    c = args->c;
    i = args->i;

    s = i * c;
    e = (i + 1) * c;

    for(int i = s; i < e; i++){
        a[i] /= b[i];
    }
}

struct Vector vector_div(struct Vector *a, struct Vector *b) {
    struct Vector res = generate_vector(a->size);

    int _threads = THREADS < a->size? THREADS : a->size;
    
    int chunk_size = a->size/_threads;

    pthread_t threads[_threads];
    
    struct ThreadArgs vas[_threads];

    int i;
    for (i = 0; i < _threads; i++) {
        vas[i].out = res.array;
        vas[i].a = a->array;
        vas[i].b = b->array;
        vas[i].c = chunk_size;
        vas[i].i = i;
        pthread_create(&threads[i], NULL, _vector_div, (void *)&vas[i]); 
    }
    for (i = 0; i < _threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return res;
}

void vector_idiv(struct Vector *a, struct Vector *b) {
    int _threads = THREADS < a->size? THREADS : a->size;

    int chunk_size = a->size/_threads;

    pthread_t threads[_threads];
    
    struct ThreadiArgs vas[_threads];

    int i;
    for (i = 0; i < _threads; i++) {
        vas[i].a = a->array;
        vas[i].b = b->array;
        vas[i].c = chunk_size;
        vas[i].i = i;
        pthread_create(&threads[i], NULL, _vector_idiv, (void *)&vas[i]); 
    }
    for (i = 0; i < _threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

