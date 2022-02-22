#include <stdio.h>

#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/matrix/tasks.h"
#include "libs/data_structures/tests/matrix/test_matrix_tasks.h"
#include "libs/data_structures/tests/matrix/testFunctionsOfMatrix.h"

int main() {
    testsOfTasks();
    testMatrix();

    float a[] = {1.2f, 2.1f,
                 3.545f, 1.2f,

                 7.6f, 3.3f,
                 5.2231f, 0.6f,

                 0.5f, 0.77f,
                 0.313f, 3.545f};
    matrixF *m = createArrayOfMatrixFromArrayF(a, 3, 2, 2);


    printMatricesWithMinimumNorm(m, 3, getMaxAbsF);

    return 0;
}
