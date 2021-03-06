//
// Created by Иван on 14.02.2022.
//

#ifndef LABA5B_MATRIX_H
#define LABA5B_MATRIX_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>

#include "../../algorithms/algorithms.h"

typedef struct matrix {
    int **values;
    int nRows;
    int nCols;
} matrix;

typedef struct matrixF {
    float **values;
    int nRows;
    int nCols;
} matrixF;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;


matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix m);

void inputMatrices(matrix *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

void swapRows(matrix m, int i1, int i2);

void swapColumns(matrix m, int j1, int j2);

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int));

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int));

bool isSquareMatrix(matrix m);

bool areTwoMatricesEqual(matrix m1, matrix m2);

bool isEMatrix(matrix m);

bool isSymmetricMatrix(matrix m);

void transposeSquareMatrix(matrix m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols);

matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices, int nRows, int nCols);

matrixF getMemMatrixF(int nRows, int nCols);

matrixF *getMemArrayOfMatricesF(int nMatrices, int nRows, int nCols);

matrixF createFMatrixFromArray(const float *a, int nRows, int nCols);

void freeMemMatrixF(matrixF m);

void outputMatrixF(matrixF m);

matrixF *createArrayOfMatrixFromArrayF(const float *values, int nMatrices, int nRows, int nCols);

#endif //LABA5B_MATRIX_H
