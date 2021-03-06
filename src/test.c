#include <stdbool.h>

#include "extreme_maths.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void print_vector(v_f *a) {
   float *res;
   res = result(a);
   printf("[");
   for (int i = 0; i < a->size; i++) {
      printf(" %f,", res[i]);
   }
   printf(" ]\n");
}

bool test_Vector_copy_f(int size) {
    float x[size*sizeof(float)];

    for (int i=0; i < size; i++) {
        x[i] = (float)(i+1)/10;
    }

    v_f vec_x = copy_f(x, size);

    if (vec_x.size != size) {
        printf("test_%s\t..." ANSI_COLOR_RED "failed\n" ANSI_COLOR_RESET, "Vector_copy_f");
        printf(ANSI_COLOR_RED "\tVector size miss match: %d != %d\n" ANSI_COLOR_RESET, size, vec_x.size);
        return false;
    }

    for (int i=0; i < size; i++) {
        if (x[i] != vec_x.array[i]) {
            printf("test_%s\t..." ANSI_COLOR_RED "failed\n" ANSI_COLOR_RESET, "Vector_copy_f");
            printf(ANSI_COLOR_RED "\tCopied value at %d miss match: %f != %f\n" ANSI_COLOR_RESET, i, x[i], vec_x.array[i]);
            return false;
        }
    }

    printf("test_Vector_copy_f\t..." ANSI_COLOR_GREEN "passed\n" ANSI_COLOR_RESET);
    return true;
}

bool test_Vector_point_f(int size) {
    float x[size*sizeof(float)];

    for (int i=0; i < size; i++) {
        x[i] = (float)(i+1)/10;
    }

    v_f vec_x = point_f(x, size);

    if (vec_x.array != x) {
        printf("test_%s\t..." ANSI_COLOR_RED "failed\n" ANSI_COLOR_RESET, "Vector_point_f");
        return false;
    }

    printf("test_Vector_point_f\t..." ANSI_COLOR_GREEN "passed\n" ANSI_COLOR_RESET);
    return true;
}


bool test_Vector_op(char *name, v_f (*fn)(v_f *, v_f *), float (*op)(float a, float b), int n) {
    bool passed = true;

    float check[n*sizeof(float)];
    float x[n*sizeof(float)];
    float y[n*sizeof(float)];

    for (int i=0; i < n; i++) {
        check[i] = (float)(i+1)/10;
        x[i] = (float)(i+1)/10;
        y[i] = (float)(i+1)/10;
    }

    v_f vec_x = copy_f(x, n);
    v_f vec_y = copy_f(y, n);

    v_f vec_z = fn(&vec_x, &vec_y);

    float* z = result(&vec_z); 

    for (int i=0;i<n;i++) {
        if (op(check[i], check[i]) != z[i]) {
            passed = false;
        }
    }

    clean(&vec_x);
    clean(&vec_y);

    v_f vec_a = point_f(x, n);
    v_f vec_b = point_f(y, n);

    v_f vec_c = fn(&vec_a, &vec_b);

    float* c = result(&vec_c); 

    for (int i=0;i<n;i++) {
        if (op(check[i], check[i]) != c[i]) {
            passed = false;
        }
    }

    if (passed) {
        printf("test_%s\t..." ANSI_COLOR_GREEN "passed\n" ANSI_COLOR_RESET , name);
    } else {
        printf("test_%s\t..." ANSI_COLOR_RED "failed\n" ANSI_COLOR_RESET, name);
    }

    return passed;

}


bool test_Vector_iop(char *name, void (*fn)(v_f *, v_f *), float (*op)(float a, float b), int n) {
    bool passed = true;

    float check[n*sizeof(float)];
    float x[n*sizeof(float)];
    float y[n*sizeof(float)];

    for (int i = 1; i <= n; i++) {
        check[i] = (float)i/10;
        x[i] = (float)i/10;
        y[i] = (float)i/10;
    }

    v_f vec_x = copy_f(x, n);
    v_f vec_y = copy_f(y, n);

    fn(&vec_x, &vec_y);

    float* z = result(&vec_x); 

    for (int i=0;i<n;i++) {
        if (op(check[i], check[i]) != z[i]) {
            passed = false;
        }
    }

    clean(&vec_x);
    clean(&vec_y);

    v_f vec_a = point_f(x, n);
    v_f vec_b = point_f(y, n);

    fn(&vec_a, &vec_b);

    float* c = result(&vec_a); 

    for (int i=0;i<n;i++) {
        if (op(check[i], check[i]) != c[i]) {
            printf("%f op %f => %f == %f == %f | %f\n", check[i], check[i], op(check[i], check[i]), x[i], c[i], y[i]);
            passed = false;
        }
    }

    if (passed) {
        printf("test_%s\t..." ANSI_COLOR_GREEN "passed\n" ANSI_COLOR_RESET , name);
    } else {
        printf("test_%s\t..." ANSI_COLOR_RED "failed\n" ANSI_COLOR_RESET, name);
    }

    return passed;
}

float val_add(float a, float b) { return a + b; };
float val_sub(float a, float b) { return a - b; };
float val_mul(float a, float b) { return a * b; };
float val_div(float a, float b) { return a / b; };

/**
 * Wrapper for _Generics.
 *
 * Pre-processor cannot swap functions for auto testing tools
 */
v_f w_add_f(v_f *a, v_f *b) {
    return add_v(a, b);
}

void w_iadd_f(v_f *a, v_f *b) {
    iadd_v(a, b);
}

v_f w_sub_f(v_f *a, v_f *b) {
    return sub_v(a, b);
}

void w_isub_f(v_f *a, v_f *b) {
    isub_v(a, b);
}

v_f w_mul_f(v_f *a, v_f *b) {
    return mul_v(a, b);
}

void w_imul_f(v_f *a, v_f *b) {
    imul_v(a, b);
}

v_f w_div_f(v_f *a, v_f *b) {
    return div_v(a, b);
}

void w_idiv_f(v_f *a, v_f *b) {
    idiv_v(a, b);
}


int main() {
    bool passed = true;
    init();

    passed = test_Vector_copy_f(50);
    passed = test_Vector_point_f(50);

    if (!passed) {
        printf("Foundation tests passed. Any further tests not run.\n");
        return 1;
    }

    passed = test_Vector_op("add", &w_add_f, val_add, 10);
    passed = test_Vector_iop("iadd", &w_iadd_f, val_add, 10);
    passed = test_Vector_op("sub", &w_sub_f, val_sub, 10);
    passed = test_Vector_iop("isub", &w_isub_f, val_sub, 10);
    passed = test_Vector_op("mul", &w_mul_f, val_mul, 10);
    passed = test_Vector_iop("imul", &w_imul_f, val_mul, 10);
    passed = test_Vector_op("div", &w_div_f, val_div, 10);
    passed = test_Vector_iop("idv", &w_idiv_f, val_div, 10);

    close();
    if (passed) {
        printf("all tests passed\n");
        return 0;
    }
    printf("1 or more test failed\n");
    return 1;
}
