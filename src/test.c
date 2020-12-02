#include <stdbool.h>

#include "extreme_maths.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void print_vector(struct Vector *a) {
   float *res;
   res = get_result(a);
   printf("[");
   for (int i = 0; i < a->size; i++) {
      printf(" %f,", res[i]);
   }
   printf(" ]\n");
}


bool test_vector_op(char *name, struct Vector (*fn)(struct Vector *, struct Vector *), float (*op)(float a, float b), int n) {
    bool passed = true;

    float x[n*sizeof(float)];
    float y[n*sizeof(float)];

    for (int i = 1; i <= n; i++) {
        x[i] = (float)i/10;
        y[i] = (float)i/10;
    }

    struct Vector vec_x = create_vector(x, n);
    struct Vector vec_y = create_vector(y, n);

    struct Vector vec_z = fn(&vec_x, &vec_y);

    float* z = get_result(&vec_z); 

    int count = 0;
    for (int i=0;i<n;i++) {
        if (op(x[i], y[i]) != z[i]) {
            passed = false;
            count += 1;
        }
    }

    clean_vector(vec_x);
    clean_vector(vec_y);

    if (passed) {
        printf("test_%s\t..." ANSI_COLOR_GREEN "passed\n" ANSI_COLOR_RESET , name);
    } else {
        printf("test_%s\t..." ANSI_COLOR_RED "failed\n" ANSI_COLOR_RESET, name);
    }

    if (!passed) {
        printf(ANSI_COLOR_RED "%d/%d miss-matched\n\n" ANSI_COLOR_RED, count, n);
    }

    return passed;
}




bool test_vector_iop(char *name, void (*fn)(struct Vector *, struct Vector *), float (*op)(float a, float b), int n) {
    bool passed = true;

    float x[n*sizeof(float)];
    float y[n*sizeof(float)];

    for (int i = 1; i <= n; i++) {
        x[i] = (float)i/10;
        y[i] = (float)i/10;
    }

    struct Vector vec_x = create_vector(x, n);
    struct Vector vec_y = create_vector(y, n);

    fn(&vec_x, &vec_y);

    float* z = get_result(&vec_x); 

    for (int i=0;i<n;i++) {
        if (op(x[i], y[i]) != z[i]) {
            passed = false;
        }
    }

    clean_vector(vec_x);
    clean_vector(vec_y);

    if (passed) {
        printf("test_%s\t..." ANSI_COLOR_GREEN "passed\n" ANSI_COLOR_RESET , name);
    } else {
        printf("test_%s\t..." ANSI_COLOR_RED "failed\n" ANSI_COLOR_RESET, name);
    }

    return passed;
}

float add(float a, float b) { return a + b; };
float sub(float a, float b) { return a - b; };
float mul(float a, float b) { return a * b; };
float ndiv(float a, float b) { return a / b; };

int main() {
    bool passed = true;
    init();

    if (!passed) {
        printf("Foundation tests passed. Any further tests not run.\n");
        return 1;
    }

    passed = test_vector_op("test_vector_add", vector_add, add, 10);
    passed = test_vector_iop("test_vector_iadd", vector_iadd, add, 10);
    passed = test_vector_op("test_vector_sub", vector_sub, sub, 10);
    passed = test_vector_iop("test_vector_isub", vector_isub, sub, 10);
    passed = test_vector_op("test_vector_mul", vector_mul, mul, 10);
    passed = test_vector_iop("test_vector_imul", vector_imul, mul, 10);
    passed = test_vector_op("test_vector_div", vector_div, ndiv, 10);
    passed = test_vector_iop("test_vector_idiv", vector_idiv, ndiv, 10);
    
    clean();
    if (passed) {
        printf("all tests passed\n");
        return 0;
    }
    printf("1 or more test failed\n");
    return 1;
}
