//
// Created by Иван on 14.02.2022.
//

#ifndef LABA5B_MATRIX_H
#define LABA5B_MATRIX_H

#include <stdio.h>
#include <malloc.h>

typedef struct matrix {
    int **values;
    int nRows;
    int nCols;
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

void freeMemMatrix(matrix m);

void freeMemMatrices(matrix *ms, int nMatrices);

#endif //LABA5B_MATRIX_H
