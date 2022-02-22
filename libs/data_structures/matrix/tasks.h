#ifndef LABA5B_5D_TASKS_H
#define LABA5B_5D_TASKS_H

#include "matrix.h"

void swapRowsWithMaxAndMinElement(matrix m);

int getMax(int *a, int n);

void sortRowsByMaxElements(matrix m);

int getMin(int *a, int n);

void sortColsByMnElements(matrix m);

matrix mulMatrices(matrix m1, matrix m2);

void getSquareOfMatrixIfSymmetric(matrix *m);

long long getSum(int *a, int size);

bool isUnique(long long *a, int n);

void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

int max2(int a, int b);

long long findSumOfMaxesOfPseudoDiagonal(matrix m);

int min2(int a, int b);

int getMinInArea(matrix m);





#endif //LABA5B_5D_TASKS_H
