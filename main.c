#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "libs/data_structures/matrix/matrix.h"


int main() {
    matrix m = getMemMatrix(4, 3);
    inputMatrix(m);
    outputMatrix(m);
    printf("\n");
    swapColumns(m, 1, 2);
    outputMatrix(m);

    return 0;
}