#include <stdbool.h>

#include "extreme_maths.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void print_vector(struct Vector_float *a) {
   float *res;
   res = Vector_get_result_float(a);
   printf("[");
   for (int i = 0; i < a->size; i++) {
      printf(" %f,", res[i]);
   }
   printf(" ]\n");
}


bool test_Vector_op(char *name, struct Vector_float (*fn)(struct Vector_float *, struct Vector_float *), float (*op)(float a, float b), int n) {
    bool passed = true;

    float x[n*sizeof(float)];
    float y[n*sizeof(float)];

    for (int i=0; i <= n; i++) {
        x[i] = (float)(i+1)/10;
        y[i] = (float)(i+1)/10;
    }

    struct Vector_float vec_x = Vector_create_float(x, n);
    struct Vector_float vec_y = Vector_create_float(y, n);

    struct Vector_float vec_z = fn(&vec_x, &vec_y);

    float* z = Vector_get_result_float(&vec_z); 

    int count = 0;
    for (int i=0;i<n;i++) {
        if (op(x[i], y[i]) != z[i]) {
            passed = false;
            count += 1;
        }
    }

    Vector_clean_float(vec_x);
    Vector_clean_float(vec_y);

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

bool test_Vector_iop(char *name, void (*fn)(struct Vector_float *, struct Vector_float *), float (*op)(float a, float b), int n) {
    bool passed = true;

    float x[n*sizeof(float)];
    float y[n*sizeof(float)];

    for (int i=0; i <= n; i++) {
        x[i] = (float)(i+1)/10;
        y[i] = (float)(i+1)/10;
    }

    struct Vector_float vec_x = Vector_create_float(x, n);
    struct Vector_float vec_y = Vector_create_float(y, n);

    fn(&vec_x, &vec_y);

    float* z = Vector_get_result_float(&vec_x); 

    for (int i=0;i<n;i++) {
        if (op(x[i], y[i]) != z[i]) {
            passed = false;
        }
    }

    Vector_clean_float(vec_x);
    Vector_clean_float(vec_y);

    if (passed) {
        printf("test_%s\t..." ANSI_COLOR_GREEN "passed\n" ANSI_COLOR_RESET , name);
    } else {
        printf("test_%s\t..." ANSI_COLOR_RED "failed\n" ANSI_COLOR_RESET, name);
    }

    return passed;
}

bool test_Vector_PreOwnedVector_op(char *name, struct Vector_float (*fn)(struct Vector_float *, struct PreOwnedVector_float *), float (*op)(float a, float b), int n) {
    bool passed = true;

    float x[n*sizeof(float)];
    float y[n*sizeof(float)];

    for (int i=0; i <= n; i++) {
        x[i] = (float)(i+1)/10;
        y[i] = (float)(i+1)/10;
    }

    struct Vector_float vec_x = Vector_create_float(x, n);
    struct PreOwnedVector_float vec_y = PreOwnedVector_create_float(y, n);

    struct Vector_float vec_z = fn(&vec_x, &vec_y);

    float* z = Vector_get_result_float(&vec_z); 

    int count = 0;
    for (int i=0;i<n;i++) {
        if (op(x[i], y[i]) != z[i]) {
            passed = false;
            count += 1;
        }
    }

    Vector_clean_float(vec_x);
    PreOwnedVector_clean_float(vec_y);
    Vector_clean_float(vec_z);

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

bool test_Vector_PreOwnedVector_iop(char *name, void (*fn)(struct Vector_float *, struct PreOwnedVector_float *), float (*op)(float a, float b), int n) {
    bool passed = true;

    float x[n*sizeof(float)];
    float y[n*sizeof(float)];

    for (int i=0; i <= n; i++) {
        x[i] = (float)(i+1)/10;
        y[i] = (float)(i+1)/10;
    }

    struct Vector_float vec_x = Vector_create_float(x, n);
    struct PreOwnedVector_float vec_y = PreOwnedVector_create_float(y, n);

    fn(&vec_x, &vec_y);

    float* z = Vector_get_result_float(&vec_x); 

    for (int i=0;i<n;i++) {
        if (op(x[i], y[i]) != z[i]) {
            passed = false;
        }
    }

    Vector_clean_float(vec_x);
    PreOwnedVector_clean_float(vec_y);

    if (passed) {
        printf("test_%s\t..." ANSI_COLOR_GREEN "passed\n" ANSI_COLOR_RESET , name);
    } else {
        printf("test_%s\t..." ANSI_COLOR_RED "failed\n" ANSI_COLOR_RESET, name);
    }

    return passed;
}

bool test_PreOwnedVector_op(char *name, struct Vector_float (*fn)(struct PreOwnedVector_float *, struct PreOwnedVector_float *), float (*op)(float a, float b), int n) {
    bool passed = true;

    float x[n*sizeof(float)];
    float y[n*sizeof(float)];

    for (int i=0; i <= n; i++) {
        x[i] = (float)(i+1)/10;
        y[i] = (float)(i+1)/10;
    }

    struct PreOwnedVector_float vec_x = PreOwnedVector_create_float(x, n);
    struct PreOwnedVector_float vec_y = PreOwnedVector_create_float(y, n);

    struct Vector_float vec_z = fn(&vec_x, &vec_y);

    float* z = Vector_get_result_float(&vec_z); 

    int count = 0;
    for (int i=0;i<n;i++) {
        if (op(x[i], y[i]) != z[i]) {
            passed = false;
            count += 1;
        }
    }

    PreOwnedVector_clean_float(vec_x);
    PreOwnedVector_clean_float(vec_y);

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

bool test_PreOwnedVector_iop(char *name, struct Vector_float (*fn)(struct PreOwnedVector_float, struct PreOwnedVector_float *), float (*op)(float a, float b), int n) {
    bool passed = true;

    float x[n*sizeof(float)];
    float y[n*sizeof(float)];

    for (int i=0; i <= n; i++) {
        x[i] = (float)(i+1)/10;
        y[i] = (float)(i+1)/10;
    }

    struct PreOwnedVector_float vec_x = PreOwnedVector_create_float(x, n);
    struct PreOwnedVector_float vec_y = PreOwnedVector_create_float(y, n);

    struct Vector_float vec_z = fn(vec_x, &vec_y);

    float* z = Vector_get_result_float(&vec_z); 

    for (int i=0;i<n;i++) {
        if (op(x[i], y[i]) != z[i]) {
            passed = false;
        }
    }

    PreOwnedVector_clean_float(vec_y);
    Vector_clean_float(vec_z);

    if (passed) {
        printf("test_%s\t..." ANSI_COLOR_GREEN "passed\n" ANSI_COLOR_RESET , name);
    } else {
        printf("test_%s\t..." ANSI_COLOR_RED "failed\n" ANSI_COLOR_RESET, name);
    }

    return passed;
}

bool test_PreOwnedVector_Vector_op(char *name, struct Vector_float (*fn)(struct PreOwnedVector_float *, struct Vector_float *), float (*op)(float a, float b), int n) {
    bool passed = true;

    float x[n*sizeof(float)];
    float y[n*sizeof(float)];

    for (int i=0; i <= n; i++) {
        x[i] = (float)(i+1)/10;
        y[i] = (float)(i+1)/10;
    }

    struct PreOwnedVector_float vec_x = PreOwnedVector_create_float(x, n);
    struct Vector_float vec_y = Vector_create_float(y, n);

    struct Vector_float vec_z = fn(&vec_x, &vec_y);

    float* z = Vector_get_result_float(&vec_z); 

    int count = 0;
    for (int i=0;i<n;i++) {
        if (op(x[i], y[i]) != z[i]) {
            passed = false;
            count += 1;
        }
    }

    PreOwnedVector_clean_float(vec_x);
    Vector_clean_float(vec_y);
    Vector_clean_float(vec_z);

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

bool test_PreOwnedVector_Vector_iop(char *name, struct Vector_float (*fn)(struct PreOwnedVector_float, struct Vector_float *), float (*op)(float a, float b), int n) {
    bool passed = true;

    float x[n*sizeof(float)];
    float y[n*sizeof(float)];

    for (int i=0; i <= n; i++) {
        x[i] = (float)(i+1)/10;
        y[i] = (float)(i+1)/10;
    }

    struct PreOwnedVector_float vec_x = PreOwnedVector_create_float(x, n);
    struct Vector_float vec_y = Vector_create_float(y, n);

    struct Vector_float vec_z = fn(vec_x, &vec_y);

    float* z = Vector_get_result_float(&vec_z); 

    for (int i=0;i<n;i++) {
        if (op(x[i], y[i]) != z[i]) {
            passed = false;
        }
    }

    Vector_clean_float(vec_y);
    Vector_clean_float(vec_z);

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

    passed = test_Vector_op("Vector_add_float", Vector_add_float, add, 10);
    passed = test_Vector_iop("Vector_iadd_float", Vector_iadd_float, add, 10);
    passed = test_Vector_op("Vector_sub_float", Vector_sub_float, sub, 10);
    passed = test_Vector_iop("Vector_isub_float", Vector_isub_float, sub, 10);
    passed = test_Vector_op("Vector_mul_float", Vector_mul_float, mul, 10);
    passed = test_Vector_iop("Vector_imul_float", Vector_imul_float, mul, 10);
    passed = test_Vector_op("Vector_div_float", Vector_div_float, ndiv, 10);
    passed = test_Vector_iop("Vector_idiv_float", Vector_idiv_float, ndiv, 10);

    passed = test_Vector_PreOwnedVector_op("Vector_add_PreOwnedVector_float", Vector_add_PreOwnedVector_float, add, 10);
    passed = test_Vector_PreOwnedVector_iop("Vector_iadd_PreOwnedVector_float", Vector_iadd_PreOwnedVector_float, add, 10);
    passed = test_Vector_PreOwnedVector_op("Vector_sub_PreOwnedVector_float", Vector_sub_PreOwnedVector_float, sub, 10);
    passed = test_Vector_PreOwnedVector_iop("Vector_isub_PreOwnedVector_float", Vector_isub_PreOwnedVector_float, sub, 10);
    passed = test_Vector_PreOwnedVector_op("Vector_mul_PreOwnedVector_float", Vector_mul_PreOwnedVector_float, mul, 10);
    passed = test_Vector_PreOwnedVector_iop("Vector_imul_PreOwnedVector_float", Vector_imul_PreOwnedVector_float, mul, 10);
    passed = test_Vector_PreOwnedVector_op("Vector_div_PreOwnedVector_float", Vector_div_PreOwnedVector_float, ndiv, 10);
    passed = test_Vector_PreOwnedVector_iop("Vector_idiv_PreOwnedVector_float", Vector_idiv_PreOwnedVector_float, ndiv, 10);

    passed = test_PreOwnedVector_op("PreOwnedVector_add_float", PreOwnedVector_add_float, add, 10);
    passed = test_PreOwnedVector_iop("PreOwnedVector_iadd_float", PreOwnedVector_iadd_float, add, 10);
    passed = test_PreOwnedVector_op("PreOwnedVector_sub_float", PreOwnedVector_sub_float, sub, 10);
    passed = test_PreOwnedVector_iop("PreOwnedVector_isub_float", PreOwnedVector_isub_float, sub, 10);
    passed = test_PreOwnedVector_op("PreOwnedVector_mul_float", PreOwnedVector_mul_float, mul, 10);
    passed = test_PreOwnedVector_iop("PreOwnedVector_imul_float", PreOwnedVector_imul_float, mul, 10);
    passed = test_PreOwnedVector_op("PreOwnedVector_div_float", PreOwnedVector_div_float, ndiv, 10);
    passed = test_PreOwnedVector_iop("PreOwnedVector_idiv_float", PreOwnedVector_idiv_float, ndiv, 10);

    passed = test_PreOwnedVector_Vector_op("PreOwnedVector_add_Vector_float", PreOwnedVector_add_Vector_float, add, 10);
    passed = test_PreOwnedVector_Vector_iop("PreOwnedVector_iadd_Vector_float", PreOwnedVector_iadd_Vector_float, add, 10);
    passed = test_PreOwnedVector_Vector_op("PreOwnedVector_sub_Vector_float", PreOwnedVector_sub_Vector_float, sub, 10);
    passed = test_PreOwnedVector_Vector_iop("PreOwnedVector_isub_Vector_float", PreOwnedVector_isub_Vector_float, sub, 10);
    passed = test_PreOwnedVector_Vector_op("PreOwnedVector_mul_Vector_float", PreOwnedVector_mul_Vector_float, mul, 10);
    passed = test_PreOwnedVector_Vector_iop("PreOwnedVector_imul_Vector_float", PreOwnedVector_imul_Vector_float, mul, 10);
    passed = test_PreOwnedVector_Vector_op("PreOwnedVector_div_Vector_float", PreOwnedVector_div_Vector_float, ndiv, 10);
    passed = test_PreOwnedVector_Vector_iop("PreOwnedVector_idiv_Vector_float", PreOwnedVector_idiv_Vector_float, ndiv, 10);

    clean();
    if (passed) {
        printf("all tests passed\n");
        return 0;
    }
    printf("1 or more test failed\n");
    return 1;
}
