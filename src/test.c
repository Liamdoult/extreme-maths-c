#include <stdbool.h>

#include "extreme_maths.h"

void print_vector(struct Vector *a) {
   printf("[");
   for (int i = 0; i < a->size; i++) {
      printf(" %f,", a->array[i]);
   }
   printf(" ]\n");
}

bool test_vector_add() {
    bool passed = true;

    float x[3*sizeof(float)] = {10.0f, 20.0f, 40.0f};
    float y[3*sizeof(float)] = {10.0f, 20.0f, 40.0f};

    struct Vector vec_x = create_vector(x, 3);
    struct Vector vec_y = create_vector(y, 3);

    struct Vector vec_z = vector_add(&vec_x, &vec_y);

    float* z = get_result(&vec_z); 

    if (z[0] != 20.0f || z[1] != 40.0f || z[2] != 80.0f) {
        passed = false;
        printf("[20.0, 40.0, 80.0] != [%f, %f, %f]\n", z[0], z[1], z[2]);
    }

    clean_vector(vec_x);
    clean_vector(vec_y);
    clean_vector(vec_z);

    if (passed) {
        printf("test_vector_add ... passed\n");
    } else {
        printf("test_vector_add ... failed\n");
    }
    return passed;
}

bool test_vector_iadd() {
    bool passed = true;

    float x[3*sizeof(float)] = {10.0f, 20.0f, 40.0f};
    float y[3*sizeof(float)] = {10.0f, 20.0f, 40.0f};

    struct Vector vec_x = create_vector(x, 3);
    struct Vector vec_y = create_vector(y, 3);

    vector_iadd(&vec_x, &vec_y);

    float* z = get_result(&vec_x); 

    if (z[0] != 20.0f || z[1] != 40.0f || z[2] != 80.0f) {
        passed = false;
        printf("[20.0, 40.0, 80.0] != [%f, %f, %f]\n", z[0], z[1], z[2]);
    }

    clean_vector(vec_x);
    clean_vector(vec_y);

    if (passed) {
        printf("test_vector_iadd ... passed\n");
    } else {
        printf("test_vector_iadd ... failed\n");
    }
    return passed;
}

bool test_vector_sub() {
    bool passed = true;

    float x[3*sizeof(float)] = {30.0f, 60.0f, 120.0f};
    float y[3*sizeof(float)] = {10.0f, 20.0f, 40.0f};

    struct Vector vec_x = create_vector(x, 3);
    struct Vector vec_y = create_vector(y, 3);

    struct Vector vec_z = vector_sub(&vec_x, &vec_y);

    float* z = get_result(&vec_z); 

    if (z[0] != 20.0f || z[1] != 40.0f || z[2] != 80.0f) {
        passed = false;
        printf("[20.0, 40.0, 80.0] != [%f, %f, %f]\n", z[0], z[1], z[2]);
    }

    clean_vector(vec_x);
    clean_vector(vec_y);
    clean_vector(vec_z);

    if (passed) {
        printf("test_vector_sub ... passed\n");
    } else {
        printf("test_vector_sub ... failed\n");
    }
    return passed;
}

bool test_vector_isub() {
    bool passed = true;

    float x[3*sizeof(float)] = {30.0f, 60.0f, 120.0f};
    float y[3*sizeof(float)] = {10.0f, 20.0f, 40.0f};

    struct Vector vec_x = create_vector(x, 3);
    struct Vector vec_y = create_vector(y, 3);

    vector_isub(&vec_x, &vec_y);

    float* z = get_result(&vec_x); 

    if (z[0] != 20.0f || z[1] != 40.0f || z[2] != 80.0f) {
        passed = false;
        printf("[20.0, 40.0, 80.0] != [%f, %f, %f]\n", z[0], z[1], z[2]);
    }

    clean_vector(vec_x);
    clean_vector(vec_y);

    if (passed) {
        printf("test_vector_isub ... passed\n");
    } else {
        printf("test_vector_isub ... failed\n");
    }
    return passed;
}

bool test_vector_mul() {
    bool passed = true;

    float x[3*sizeof(float)] = {2.0f, 2.0f, 2.0f};
    float y[3*sizeof(float)] = {10.0f, 20.0f, 40.0f};

    struct Vector vec_x = create_vector(x, 3);
    struct Vector vec_y = create_vector(y, 3);

    struct Vector vec_z = vector_mul(&vec_x, &vec_y);

    float* z = get_result(&vec_z); 

    if (z[0] != 20.0f || z[1] != 40.0f || z[2] != 80.0f) {
        passed = false;
        printf("[20.0, 40.0, 80.0] != [%f, %f, %f]\n", z[0], z[1], z[2]);
    }

    clean_vector(vec_x);
    clean_vector(vec_y);
    clean_vector(vec_z);

    if (passed) {
        printf("test_vector_mul ... passed\n");
    } else {
        printf("test_vector_mul ... failed\n");
    }
    return passed;
}

bool test_vector_imul() {
    bool passed = true;

    float x[3*sizeof(float)] = {2.0f, 2.0f, 2.0f};
    float y[3*sizeof(float)] = {10.0f, 20.0f, 40.0f};

    struct Vector vec_x = create_vector(x, 3);
    struct Vector vec_y = create_vector(y, 3);

    vector_imul(&vec_x, &vec_y);

    float* z = get_result(&vec_x); 

    if (z[0] != 20.0f || z[1] != 40.0f || z[2] != 80.0f) {
        passed = false;
        printf("[20.0, 40.0, 80.0] != [%f, %f, %f]\n", z[0], z[1], z[2]);
    }

    clean_vector(vec_x);
    clean_vector(vec_y);

    if (passed) {
        printf("test_vector_imul ... passed\n");
    } else {
        printf("test_vector_imul ... failed\n");
    }
    return passed;
}

bool test_vector_div() {
    bool passed = true;

    float x[3*sizeof(float)] = {200.0f, 800.0f, 3200.0f};
    float y[3*sizeof(float)] = {10.0f, 20.0f, 40.0f};

    struct Vector vec_x = create_vector(x, 3);
    struct Vector vec_y = create_vector(y, 3);

    struct Vector vec_z = vector_div(&vec_x, &vec_y);

    float* z = get_result(&vec_z); 

    if (z[0] != 20.0f || z[1] != 40.0f || z[2] != 80.0f) {
        passed = false;
        printf("[20.0, 40.0, 80.0] != [%f, %f, %f]\n", z[0], z[1], z[2]);
    }

    clean_vector(vec_x);
    clean_vector(vec_y);
    clean_vector(vec_z);

    if (passed) {
        printf("test_vector_div ... passed\n");
    } else {
        printf("test_vector_div ... failed\n");
    }
    return passed;
}

bool test_vector_idiv() {
    bool passed = true;

    float x[3*sizeof(float)] = {200.0f, 800.0f, 3200.0f};
    float y[3*sizeof(float)] = {10.0f, 20.0f, 40.0f};

    struct Vector vec_x = create_vector(x, 3);
    struct Vector vec_y = create_vector(y, 3);

    vector_idiv(&vec_x, &vec_y);

    float* z = get_result(&vec_x); 

    if (z[0] != 20.0f || z[1] != 40.0f || z[2] != 80.0f) {
        passed = false;
        printf("[20.0, 40.0, 80.0] != [%f, %f, %f]\n", z[0], z[1], z[2]);
    }

    clean_vector(vec_x);
    clean_vector(vec_y);

    if (passed) {
        printf("test_vector_idiv ... passed\n");
    } else {
        printf("test_vector_idiv ... failed\n");
    }
    return passed;
}

int main() {
    bool passed = true;

    if (!passed) {
        printf("Foundation tests passed. Any further tests not run.\n");
        return 1;
    }

    passed = test_vector_add();
    passed = test_vector_iadd();
    passed = test_vector_sub();
    passed = test_vector_isub();
    passed = test_vector_mul();
    passed = test_vector_imul();
    passed = test_vector_div();
    passed = test_vector_idiv();
    
    if (passed) {
        printf("all tests passed\n");
        return 0;
    }
    printf("1 or more test failed\n");
    return 1;
}
