#include "matrix.h"


matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; ++i)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; ++i)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
    printf("\n");
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; ++i)
        outputMatrix(ms[i]);
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; ++i) {
        int t = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = t;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *criteriaResults = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; ++i)
        criteriaResults[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; ++i) {
        int t = criteriaResults[i];
        int j = i;
        while (j > 0 && criteriaResults[j - 1] > t) {
            criteriaResults[j] = criteriaResults[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        criteriaResults[j] = t;
    }

    free(criteriaResults);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *criteriaResults = (int *) malloc(sizeof(int) * m.nCols);
    int *column = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nCols; ++i) {
        for (int j = 0; j < m.nRows; ++j)
            column[j] = m.values[j][i];
        criteriaResults[i] = criteria(column, m.nRows);
    }

    free(column);

    for (int i = 0; i < m.nCols; ++i) {
        int t = criteriaResults[i];
        int j = i;
        while (j > 0 && criteriaResults[j - 1] > t) {
            criteriaResults[j] = criteriaResults[j - 1];
            swapColumns(m, j, j - 1);
            j--;
        }
        criteriaResults[j] = t;
    }

    free(criteriaResults);
}

bool isSquareMatrix(matrix m) {
    return m.nCols == m.nRows;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;
    for (int i = 0; i < m1.nRows; ++i) {
        for (int j = 0; j < m1.nCols; ++j)
            if (m1.values[i][j] != m2.values[i][j]) {
                return false;
            }
    }

    return true;
}

bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            if (i == j && m.values[i][j] != 1 || i != j && m.values[i][j] != 0)
                return false;


    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            if (m.values[i][j] != m.values[j][i])
                return false;


    return true;
}

void transposeSquareMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return;
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = i + 1; j < m.nCols; ++j) {
            int t = m.values[i][j];
            m.values[i][j] = m.values[j][i];
            m.values[j][i] = t;
        }
    }
}

position getMinValuePos(matrix m) {
    position min = {0, 0};
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            if (m.values[i][j] < m.values[min.rowIndex][min.colIndex]) {
                min.rowIndex = i;
                min.colIndex = j;
            }

    return min;
}

position getMaxValuePos(matrix m) {
    position max = {0, 0};
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            if (m.values[i][j] > m.values[max.rowIndex][max.colIndex]) {
                max.rowIndex = i;
                max.colIndex = j;
            }

    return max;
}

matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; ++i)
        for (int j = 0; j < nCols; ++j)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices, int nRows, int nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

matrixF getMemMatrixF(int nRows, int nCols) {
    float **values = (float **) malloc(sizeof(float *) * nRows);
    for (int i = 0; i < nRows; ++i)
        values[i] = (float *) malloc(sizeof(float) * nCols);

    return (matrixF) {values, nRows, nCols};
}

matrixF *getMemArrayOfMatricesF(int nMatrices, int nRows, int nCols) {
    matrixF *ms = (matrixF *) malloc(sizeof(matrixF) * nMatrices);
    for (int i = 0; i < nMatrices; ++i)
        ms[i] = getMemMatrixF(nRows, nCols);

    return ms;
}

matrixF createFMatrixFromArray(const float *a, int nRows, int nCols) {
    matrixF m = getMemMatrixF(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; ++i)
        for (int j = 0; j < nCols; ++j)
            m.values[i][j] = a[k++];

    return m;
}

void freeMemMatrixF(matrixF m) {
    for (int i = 0; i < m.nRows; ++i)
        free(m.values[i]);
    free(m.values);
}

void outputMatrixF(matrixF m) {
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j)
            printf("%f ", m.values[i][j]);
        printf("\n");
    }
    printf("\n");
}

matrixF *createArrayOfMatrixFromArrayF(const float *values, int nMatrices, int nRows, int nCols) {
    matrixF *ms = getMemArrayOfMatricesF(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}
