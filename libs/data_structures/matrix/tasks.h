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

bool isUnique(long long *a, int n);

void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

int max2(int a, int b);

long long findSumOfMaxesOfPseudoDiagonal(matrix m);

int min2(int a, int b);

int getMinInArea(matrix m);

float getDistance(int *a, int n);

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int));

void sortByDistances(matrix m);

int cmp_long_long(const void *pa, const void *pb);

int countNUnique(long long *a, int n);

int countEqClassesByRowsSum(matrix m);

int getNSpecialElement(matrix m);

position getLeftMin(matrix m);

void swapPenultimateRow(matrix m, int n);

bool isNonDescendingSorted(int *a, int n);

bool hasAllNonDescendingRows(matrix m);

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix);

int countValues(const int *a, int n, int value);

int countZeroRows(matrix m);

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix);

float getMaxAbsF(matrixF m);

#endif //LABA5B_5D_TASKS_H
