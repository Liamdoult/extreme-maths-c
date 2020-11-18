#include <stdbool.h>

#include "extreme_maths.h"

void print_vector(struct Vector *a) {
   printf("[");
   for (int i = 0; i < a->size; i++) {
      printf(" %d,", a->vector[i]);
   }
   printf(" ]\n");
}

bool test_generate_vector() {
    bool passed = true;

    struct Vector x = generate_vector(3);
    if (x.size != 3) {
        passed = false;
        printf("Error: Generated vector of size 3 has size %d\n", x.size);
    }
    for (int i = 0; i < 3; i++) {
        x.vector[i] = 3;
    }

    struct Vector y = generate_vector(4);
    if (y.size != 4) {
        passed = false;
        printf("Error: Generated vector of size 3 has size %d\n", x.size);
    }
    for (int i = 0; i < 4; i++) {
        y.vector[i] = 4;        
    }

    clean_vector(x);
    clean_vector(y);

    if (passed) {
        printf("test_generate_vector ... passed\n");
    } else {
        printf("test_generate_vector ... failed\n");
    }
    return passed;
}

bool test_add_vectors() {
    bool passed = true;

    struct Vector x = generate_vector(3);
    struct Vector y = generate_vector(3);

    x.vector[0] = 10;
    x.vector[1] = 20;
    x.vector[2] = 40;

    y.vector[0] = 10;
    y.vector[1] = 20;
    y.vector[2] = 40;

    struct Vector z = add_vectors(&x, &y);

    if (z.vector[0] != 20 || z.vector[1] != 40 || z.vector[2] != 80) {
        passed = false;
        printf("[20, 40, 80] != [%d, %d, %d]\n", z.vector[0], z.vector[1], z.vector[2]);
    }

    clean_vector(x);
    clean_vector(y);
    clean_vector(z);

    if (passed) {
        printf("test_add_vectors ... passed\n");
    } else {
        printf("test_add_vectors ... failed\n");
    }
    return passed;
}

bool test_add_to_vector() {
    bool passed = true;

    struct Vector x = generate_vector(3);
    struct Vector y = generate_vector(3);

    x.vector[0] = 10;
    x.vector[1] = 20;
    x.vector[2] = 40;

    y.vector[0] = 10;
    y.vector[1] = 20;
    y.vector[2] = 40;

    add_to_vector(&x, &y);

    if (x.vector[0] != 20 || x.vector[1] != 40 || x.vector[2] != 80) {
        passed = false;
        printf("[20, 40, 80] != [%d, %d, %d]\n", x.vector[0], x.vector[1], x.vector[2]);
    }

    clean_vector(x);
    clean_vector(y);

    if (passed) {
        printf("test_add_to_vector ... passed\n");
    } else {
        printf("test_add_to_vector ... failed\n");
    }
    return passed;
}

bool test_sub_vectors() {
    bool passed = true;

    struct Vector x = generate_vector(3);
    struct Vector y = generate_vector(3);

    x.vector[0] = 10;
    x.vector[1] = 20;
    x.vector[2] = 40;

    y.vector[0] = 10;
    y.vector[1] = 20;
    y.vector[2] = 40;

    struct Vector z = sub_vectors(&x, &y);

    if (z.vector[0] != 0 || z.vector[1] != 0 || z.vector[2] != 0) {
        passed = false;
        printf("[0, 0, 0] != [%d, %d, %d]\n", z.vector[0], z.vector[1], z.vector[2]);
    }

    clean_vector(x);
    clean_vector(y);
    clean_vector(z);

    if (passed) {
        printf("test_sub_vectors ... passed\n");
    } else {
        printf("test_sub_vectors ... failed\n");
    }
    return passed;
}

bool test_sub_from_vector() {
    bool passed = true;

    struct Vector x = generate_vector(3);
    struct Vector y = generate_vector(3);

    x.vector[0] = 10;
    x.vector[1] = 20;
    x.vector[2] = 40;

    y.vector[0] = 10;
    y.vector[1] = 20;
    y.vector[2] = 40;

    sub_from_vector(&x, &y);

    if (x.vector[0] != 0 || x.vector[1] != 0 || x.vector[2] != 0) {
        passed = false;
        printf("[0, 0, 0] != [%d, %d, %d]\n", x.vector[0], x.vector[1], x.vector[2]);
    }

    clean_vector(x);
    clean_vector(y);

    if (passed) {
        printf("test_sub_from_vector ... passed\n");
    } else {
        printf("test_sub_from_vector ... failed\n");
    }
    return passed;
}

bool test_mul_vectors() {
    bool passed = true;

    struct Vector x = generate_vector(3);
    struct Vector y = generate_vector(3);

    x.vector[0] = 10;
    x.vector[1] = 20;
    x.vector[2] = 40;

    y.vector[0] = 2;
    y.vector[1] = 2;
    y.vector[2] = 2;

    struct Vector z = mul_vectors(&x, &y);

    if (z.vector[0] != 20 || z.vector[1] != 40 || z.vector[2] != 80) {
        passed = false;
        printf("[20, 40, 80] != [%d, %d, %d]\n", z.vector[0], z.vector[1], z.vector[2]);
    }

    clean_vector(x);
    clean_vector(y);
    clean_vector(z);

    if (passed) {
        printf("test_mul_vectors ... passed\n");
    } else {
        printf("test_mul_vectors ... failed\n");
    }

    return passed;
}

bool test_mul_to_vector() {
    bool passed = true;

    struct Vector x = generate_vector(3);
    struct Vector y = generate_vector(3);

    x.vector[0] = 10;
    x.vector[1] = 20;
    x.vector[2] = 40;

    y.vector[0] = 2;
    y.vector[1] = 2;
    y.vector[2] = 2;

    mul_to_vector(&x, &y);

    if (x.vector[0] != 20 || x.vector[1] != 40 || x.vector[2] != 80) {
        passed = false;
        printf("[20, 40, 80] != [%d, %d, %d]\n", x.vector[0], x.vector[1], x.vector[2]);
    }

    clean_vector(x);
    clean_vector(y);

    if (passed) {
        printf("test_mul_to_vector ... passed\n");
    } else {
        printf("test_mul_to_vector ... failed\n");
    }
    return passed;
}


int main() {
    bool passed = true;

    passed = test_generate_vector();

    if (!passed) {
        printf("Foundation tests passed. Any further tests not run.\n");
        return 1;
    }

    passed = test_add_vectors();
    passed = test_add_to_vector();
    passed = test_sub_vectors();
    passed = test_sub_from_vector();
    passed = test_mul_vectors();
    passed = test_mul_to_vector();

    if (passed) {
        printf("all tests passed\n");
        return 0;
    }
    printf("1 or more test failed\n");
    return 1;
}
