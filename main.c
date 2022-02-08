#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"

int main() {
    vector v = {(int[]) {1, 2, 3, 4, 5}, 5, 5};
    printf("%llu", sizeof(v));
    printf("\n%llu", v.capacity);
    deleteVector(&v);

    printf("\n%llu", sizeof(v));
    printf("\n%llu", v.capacity);

    printf("\n%llu", sizeof(NULL));
    return 0;
}
