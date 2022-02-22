#include "test_matrix_tasks.h"

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

void test_getSquareOfMatrixIfSymmetric() {
    int a[] = {1, 3, 0,
               3, 2, 6,
               0, 6, 5};
    matrix m1 = createMatrixFromArray(a, 3, 3);

    int b[] = {10, 9, 18,
               9, 49, 42,
               18, 42, 61};
    matrix m2 = createMatrixFromArray(b, 3, 3);

    getSquareOfMatrixIfSymmetric(&m1);

    assert(areTwoMatricesEqual(m1, m2));

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

    getSquareOfMatrixIfSymmetric(&m1);

    assert(!areTwoMatricesEqual(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
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

void test_isMutuallyInverseMatrices() {
    int a[] = {2, 1,
               1, 1};
    matrix m1 = createMatrixFromArray(a, 2, 2);

    int b[] = {1, -1,
               -1, 2};
    matrix m2 = createMatrixFromArray(b, 2, 2);

    assert(isMutuallyInverseMatrices(m1, m2));

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}


void test_findSumOfMaxesOfPseudoDiagonal() {
    int a[] = {3, 2, 5, 4,
               1, 3, 6, 3,
               3, 2, 1, 2};
    matrix m1 = createMatrixFromArray(a, 3, 4);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 20);

    freeMemMatrix(m1);
}

void test_findSumOfMaxesOfPseudoDiagonal2() {
    int a[] = {3, 1, 3,
               2, 3, 2,
               1, 6, 5,
               2, 3, 4};
    matrix m1 = createMatrixFromArray(a, 4, 3);

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 16);

    freeMemMatrix(m1);
}

void test_getMinInArea() {
    int a[] = {10, 7, 5, 6,
               3, 11, 8, 9,
               4, 1, 12, 2};
    matrix m1 = createMatrixFromArray(a, 3, 4);

    assert(getMinInArea(m1) == 5);

    freeMemMatrix(m1);
}

void test_getMinInArea2() {
    int a[] = {6, 8, 9, 2,
               7, 12, 3, 4,
               10, 11, 5, 1};
    matrix m1 = createMatrixFromArray(a, 3, 4);

    assert(getMinInArea(m1) == 6);

    freeMemMatrix(m1);
}

void test_getMinInArea3() {
    int a[] = {100, 1, 2,
               3, 4, 5,
               6, 7, 8};
    matrix m1 = createMatrixFromArray(a, 3, 3);

    assert(getMinInArea(m1) == 100);

    freeMemMatrix(m1);
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
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_findSumOfMaxesOfPseudoDiagonal2();
    test_getMinInArea();
    test_getMinInArea2();
    test_getMinInArea3();
}