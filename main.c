#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "libs/data_structures/matrix/matrix.h"

long long getSum(int *a, int size) {
    long long sum = 0;
    for (int i = 0; i < size; ++i)
        sum += a[i];
    return sum;
}

void test_swapRows() {
    int a[] = {1, 2,
               3, 4};
    matrix m = createMatrixFromArray(a, 2, 2);

    swapRows(m, 0, 1);

    assert(m.values[0][0] == 3 && m.values[0][1] == 4 && m.values[1][0] == 1 && m.values[1][1] == 2);

    freeMemMatrix(m);
}

void test_swapColumns() {
    int a[] = {1, 2,
               3, 4};
    matrix m = createMatrixFromArray(a, 2, 2);

    swapColumns(m, 0, 1);

    assert(m.values[0][0] == 2 && m.values[0][1] == 1 && m.values[1][0] == 4 && m.values[1][1] == 3);

    freeMemMatrix(m);
}

void test_insertionSortRowsMatrixByRowCriteria() {
    int a[] = {3, 4,
               1, 2};
    matrix m = createMatrixFromArray(a, 2, 2);

    insertionSortRowsMatrixByRowCriteria(m, getSum);

    assert(m.values[0][0] == 1 && m.values[0][1] == 2 && m.values[1][0] == 3 && m.values[1][1] == 4);

    freeMemMatrix(m);
}

void test_insertionSortColsMatrixByColCriteria() {
    int a[] = {3, 1,
               4, 2};
    matrix m = createMatrixFromArray(a, 2, 2);

    insertionSortColsMatrixByColCriteria(m, getSum);

    assert(m.values[0][0] == 1 && m.values[0][1] == 3 && m.values[1][0] == 2 && m.values[1][1] == 4);

    freeMemMatrix(m);
}

void test_isSquareMatrix() {
    int a[] = {1, 2,
               3, 4};
    matrix m = createMatrixFromArray(a, 2, 2);

    assert(isSquareMatrix(m));

    freeMemMatrix(m);
}

void test_isSquareMatrix_NotSquareMatrix() {
    int a[] = {1, 2,
               3, 4,
               5, 6};
    matrix m = createMatrixFromArray(a, 3, 2);

    assert(!isSquareMatrix(m));

    freeMemMatrix(m);
}

void test_twoMatricesEqual_EqualMatrices() {
    int a[] = {1, 2,
               3, 4};
    int b[] = {1, 2,
               3, 4};
    matrix m1 = createMatrixFromArray(a, 2, 2);
    matrix m2 = createMatrixFromArray(b, 2, 2);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_twoMatricesEqual_NotEqualMatrices() {
    int a[] = {1, 2,
               3, 4};
    int b[] = {1, 2,
               3, 5};
    matrix m1 = createMatrixFromArray(a, 2, 2);
    matrix m2 = createMatrixFromArray(b, 2, 2);

    assert(!areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isEMatrix() {
    int a[] = {1, 0,
               0, 1};
    matrix m = createMatrixFromArray(a, 2, 2);

    assert(isEMatrix(m));

    freeMemMatrix(m);
}

void test_isEMatrix_NotEMatrix() {
    int a[] = {1, 1,
               1, 0};
    matrix m = createMatrixFromArray(a, 2, 2);

    assert(!isEMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix() {
    int a[] = {2, 1,
               1, 2};
    matrix m = createMatrixFromArray(a, 2, 2);

    assert(isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_isSymmetricMatrix_NotSymmetric() {
    int a[] = {1, 2,
               3, 4};
    matrix m = createMatrixFromArray(a, 2, 2);

    assert(!isSymmetricMatrix(m));

    freeMemMatrix(m);
}

void test_transposeSquareMatrix() {
    int a[] = {1, 2,
               3, 4};
    matrix m1 = createMatrixFromArray(a, 2, 2);
    int b[] = {1, 3,
               2, 4};
    matrix m2 = createMatrixFromArray(b, 2, 2);

    transposeSquareMatrix(m1);
    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getMinValuePos() {
    int a[] = {2, 1,
               3, 4};
    matrix m = createMatrixFromArray(a, 2, 2);

    position p = getMinValuePos(m);
    assert(m.values[p.rowIndex][p.colIndex] == 1);

    freeMemMatrix(m);
}

void test_getMaxValuePos() {
    int a[] = {1, 5,
               3, 4};
    matrix m = createMatrixFromArray(a, 2, 2);

    position p = getMaxValuePos(m);
    assert(m.values[p.rowIndex][p.colIndex] == 5);

    freeMemMatrix(m);
}

void testMatrix() {
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
    test_isSquareMatrix();
    test_isSquareMatrix_NotSquareMatrix();
    test_twoMatricesEqual_EqualMatrices();
    test_twoMatricesEqual_NotEqualMatrices();
    test_isEMatrix();
    test_isEMatrix_NotEMatrix();
    test_isSymmetricMatrix();
    test_isSymmetricMatrix_NotSymmetric();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

void swapRowsWithMaxAndMinElement(matrix m) {
    position max = getMaxValuePos(m);
    position min = getMinValuePos(m);

    swapRows(m, max.rowIndex, min.rowIndex);
}

void test_swapRowsWithMaxAndMinElement() {
    int a[] = {1, 2, 3,
               4, 5, 6,
               7, 8, 9};
    matrix m = createMatrixFromArray(a, 3, 3);

    int b[] = {7, 8, 9,
               4, 5, 6,
               1, 2, 3};
    matrix ml = createMatrixFromArray(b, 3, 3);

    swapRowsWithMaxAndMinElement(m);
    assert(areTwoMatricesEqual(m, ml));

    freeMemMatrix(m);
    freeMemMatrix(ml);
}

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] > max)
            max = a[i];

    return max;
}

void sortRowsByMaxElements(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void test_sortRowsByMaxElements() {
    int a[] = {7, 1, 2,
               1, 8, 1,
               3, 2, 3};
    matrix m = createMatrixFromArray(a, 3, 3);

    int b[] = {3, 2, 3,
               7, 1, 2,
               1, 8, 1};
    matrix ml = createMatrixFromArray(b, 3, 3);

    sortRowsByMaxElements(m);
    assert(areTwoMatricesEqual(m, ml));

    freeMemMatrix(m);
    freeMemMatrix(ml);
}

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; ++i)
        if (a[i] < min)
            min = a[i];

    return min;
}

void sortColsByMnElements(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void test_sortColsByMnElements() {
    int a[] = {3, 5, 2, 4, 3, 3,
               2, 5, 1, 8, 2, 7,
               6, 1, 4, 4, 8, 3};
    matrix m = createMatrixFromArray(a, 3, 6);

    int b[] = {5, 2, 3, 3, 3, 4,
               5, 1, 2, 2, 7, 8,
               1, 4, 6, 8, 3, 4};
    matrix ml = createMatrixFromArray(b, 3, 6);

    sortColsByMnElements(m);

    assert(areTwoMatricesEqual(m, ml));

    freeMemMatrix(m);
    freeMemMatrix(ml);
}

matrix mulMatrices(matrix m1, matrix m2) {
    if (m1.nCols != m2.nRows) {
        printf("the number of columns is not equal to the number of rows");
        exit(1);
    }

    matrix mul = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; ++i) {
        for (int j = 0; j < m2.nCols; ++j) {
            int element = 0;
            for (int k = 0; k < m1.nCols; ++k)
                element += m1.values[i][k] * m2.values[k][j];
            mul.values[i][j] = element;
        }
    }

    return mul;
}

void test_mulMatrices() {
    int a[] = {5, -1, 0,
               2, 1, 1};
    matrix m1 = createMatrixFromArray(a, 2, 3);

    int b[] = {0, 2,
               3, 1,
               -1, -2};
    matrix m2 = createMatrixFromArray(b, 3, 2);

    int mul[] = {-3, 9,
                 2, 3};
    matrix m3 = createMatrixFromArray(mul, 2, 2);

    assert(areTwoMatricesEqual(mulMatrices(m1, m2), m3));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
    freeMemMatrix(m3);
}

void test_mulMatrices2() {
    int a[] = {0, 2,
               3, 1,
               -1, -2};
    matrix m1 = createMatrixFromArray(a, 3, 2);

    int b[] = {5, -1, 0,
               2, 1, 1};
    matrix m2 = createMatrixFromArray(b, 2, 3);

    int mul[] = {4, 2, 2,
                 17, -2, 1,
                 -9, -1, -2};
    matrix m3 = createMatrixFromArray(mul, 3, 3);

    assert(areTwoMatricesEqual(mulMatrices(m1, m2), m3));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
    freeMemMatrix(m3);
}

void test_mulMatrices3() {
    int a[] = {1, 2,
               3, 4};
    matrix m1 = createMatrixFromArray(a, 2, 2);

    int b[] = {1, 0,
               2, 3};
    matrix m2 = createMatrixFromArray(b, 2, 2);

    int mul[] = {5, 6,
                 11, 12};
    matrix m3 = createMatrixFromArray(mul, 2, 2);

    assert(areTwoMatricesEqual(mulMatrices(m1, m2), m3));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
    freeMemMatrix(m3);
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        mulMatrices(*m, *m);
}

void test_getSquareOfMatrixIfSymmetric() {
    int a[] = {1, 3, 0,
               3, 2, 6,
               0, 6, 5};
    matrix m1 = createMatrixFromArray(a, 3, 3);

    int b[] = {10, 9, 18,
               9, 49, 42,
               18, 42, 61};
    matrix m2 = createMatrixFromArray(b, 3, 3);

    assert(areTwoMatricesEqual(mulMatrices(m1, m1), m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getSquareOfMatrixIfSymmetric_notSymmetric() {
    int a[] = {1, 3, 1,
               3, 2, 6,
               0, 6, 5};
    matrix m1 = createMatrixFromArray(a, 3, 3);

    int b[] = {10, 9, 18,
               9, 49, 42,
               18, 42, 61};
    matrix m2 = createMatrixFromArray(b, 3, 3);

    assert(!areTwoMatricesEqual(mulMatrices(m1, m1), m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

bool isUnique(long long *a, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (a[i] == a[j])
                return false;

    return true;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long *sums = (long long *) malloc(sizeof(long long) * m.nRows);
    for (int i = 0; i < m.nRows; ++i)
        sums[i] = getSum(m.values[i], m.nCols);

    if (isUnique(sums, m.nRows))
        transposeSquareMatrix(m);
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    int a[] = {1, 2,
               3, 4};
    matrix m1 = createMatrixFromArray(a, 2, 2);

    int b[] = {1, 3,
               2, 4};
    matrix m2 = createMatrixFromArray(b, 2, 2);

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    assert(areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_transposeIfMatrixHasNotEqualSumOfRows2() {
    int a[] = {2, 4,
               3, 3};
    matrix m1 = createMatrixFromArray(a, 2, 2);

    int b[] = {2, 3,
               4, 3};
    matrix m2 = createMatrixFromArray(b, 2, 2);

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    assert(!areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void testsOfTasks() {
    test_swapRowsWithMaxAndMinElement();
    test_sortRowsByMaxElements();
    test_sortColsByMnElements();
    test_mulMatrices();
    test_mulMatrices2();
    test_mulMatrices3();
    test_getSquareOfMatrixIfSymmetric();
    test_getSquareOfMatrixIfSymmetric_notSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_transposeIfMatrixHasNotEqualSumOfRows2();
}

int main() {
    testMatrix();
    testsOfTasks();

    return 0;
}
