#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <pthread.h>

#include "vector_add.h"


struct ThreadArgs {
    float *out;
    float *a;
    float *b;
    int c;
    int i;
};

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
    
    // printf("i:  %d\n", i);
    // printf("Start:  %d\n", s);
    // printf("End: %d\n", e);

    for(int i = s; i < e; i++){
        out[i] = a[i] + b[i];
    }
}

struct Vector create_vector(float *a, int size) {
    float *array; 

    array = (float*)malloc(sizeof(float) * size);

    memcpy(array, a, sizeof(float) * size);
    
    struct Vector vec;
    vec.size = size;
    vec.array = array;
    return vec;
}

float* get_result(struct Vector a) {
    return a.array;
}

void vector_add(struct Vector a, struct Vector b, struct Vector res) {
    int THREADS =  8;
    // printf("THREADS %d\n", THREADS);
    int chunk_size = a.size/THREADS;
    // printf("chunk size: %d\n", chunk_size);

    pthread_t threads[THREADS];
    
    struct ThreadArgs vas[THREADS];

    int i;
    for (i = 0; i < THREADS; i++) {
        vas[i].out = res.array;
        vas[i].a = a.array;
        vas[i].b = b.array;
        vas[i].c = chunk_size;
        vas[i].i = i;
        pthread_create(&threads[i], NULL, _vector_add, (void *)&vas[i]); 
    }
    for (i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
}

