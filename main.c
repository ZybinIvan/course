#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "libs/data_structures/matrix/matrix.h"

int getSum(int *a, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i)
        sum += a[i];
    return sum;
}

int main() {
    matrix m = getMemMatrix(3, 3);
    inputMatrix(m);
    outputMatrix(m);
    printf("\n");
    printf("%d %d\n", getMinValuePos(m).rowIndex, getMinValuePos(m).colIndex);

    return 0;
}
