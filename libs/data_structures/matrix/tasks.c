#include "tasks.h"

// 1
void swapRowsWithMaxAndMinElement(matrix m) {
    position max = getMaxValuePos(m);
    position min = getMinValuePos(m);

    swapRows(m, max.rowIndex, min.rowIndex);
}

// 2
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

// 3
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

// 4
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

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

// 5
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


// 6
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix mul = mulMatrices(m1, m2);
    bool flag = isEMatrix(mul);
    freeMemMatrix(mul);

    return flag;
}

// 7
int max2(int a, int b) {
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int n = m.nRows + m.nCols - 1;
    int *maxValues = (int *) malloc(n * sizeof(int));

    for (int i = 0; i < m.nRows - 1; i++)
        maxValues[i] = m.values[m.nRows - 1 - i][0];

    for (int i = 0; i < m.nCols; i++)
        maxValues[i + m.nRows - 1] = m.values[0][i];

    for (int i = 1; i < m.nRows; ++i)
        for (int j = 1; j < m.nCols; ++j) {
            int diagonalIndex = j - i + m.nRows - 1;
            maxValues[diagonalIndex] = max2(maxValues[diagonalIndex], m.values[i][j]);
        }

    long long sum = 0;
    for (int i = 0; i < n; ++i)
        sum += maxValues[i];
    sum -= maxValues[m.nRows - 1];

    free(maxValues);

    return sum;
}

// 8
int min2(int a, int b) {
    return a < b ? a : b;
}

int getMinInArea(matrix m) {
    position max = getMaxValuePos(m);
    int rowIndex = max.rowIndex;
    int colIndex = max.colIndex;
    int min = m.values[rowIndex][colIndex];

    int leftBorder = min2(rowIndex, colIndex);
    int rightBorder = min2(rowIndex, m.nCols - colIndex - 1);

    for (int i = 0; i < leftBorder + 1; ++i)
        for (int j = i; j < rowIndex + 1; ++j)
            min = min2(m.values[rowIndex - j][colIndex - i], min);

    for (int i = 0; i < rightBorder; ++i)
        for (int j = i; j < rowIndex; ++j)
            min = min2(m.values[rowIndex - j - 1][colIndex + i + 1], min);

    return min;
}

// 9
float getDistance(int *a, int n) {
    float sum = 0;
    for (int i = 0; i < n; ++i)
        sum += (float) (a[i] * a[i]);

    return sqrtf(sum);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int)) {
    float *criteriaResults = (float *) malloc(sizeof(float) * m.nRows);
    for (int i = 0; i < m.nRows; ++i)
        criteriaResults[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; ++i) {
        float t = criteriaResults[i];
        int j = i;
        while (j > 0 && criteriaResults[j - 1] - t > FLT_EPSILON) {
            criteriaResults[j] = criteriaResults[j - 1];
            swapRows(m, j, j - 1);
            j--;
        }
        criteriaResults[j] = t;
    }

    free(criteriaResults);
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

// 10
int cmp_long_long(const void *pa, const void *pb) {
    long long *a = (long long *) pa;
    long long *b = (long long *) pb;

    return (int) (*a - *b);
}

int countNUnique(long long *a, int n) {
    int count = 0;
    for (int i = 1; i < n; ++i)
        if (a[i] != a[i - 1])
            count++;

    return count + (n != 0);
}

int countEqClassesByRowsSum(matrix m) {
    long long *rowsSums = (long long *) malloc(sizeof(long long) * m.nRows);
    for (int i = 0; i < m.nRows; ++i)
        rowsSums[i] = getSum(m.values[i], m.nCols);

    qsort(rowsSums, m.nRows, sizeof(long long), cmp_long_long);
    int count = countNUnique(rowsSums, m.nRows);

    free(rowsSums);

    return count;
}

// 11
int getNSpecialElement(matrix m) {
    long long *colSums = (long long *) calloc(m.nCols, sizeof(long long));
    for (int i = 0; i < m.nCols; ++i)
        for (int j = 0; j < m.nRows; ++j)
            colSums[i] += m.values[j][i];

    int count = 0;
    for (int i = 0; i < m.nCols; ++i)
        for (int j = 0; j < m.nRows; ++j)
            if (m.values[j][i] > colSums[i] - m.values[j][i]) {
                count++;
                break;
            }

    free(colSums);

    return count;
}

// 12
position getLeftMin(matrix m) {
    position min = {0, 0};
    for (int i = 0; i < m.nCols; ++i)
        for (int j = 0; j < m.nRows; ++j)
            if (m.values[j][i] < m.values[min.rowIndex][min.colIndex]) {
                min.rowIndex = j;
                min.colIndex = i;
            }

    return min;
}

void swapPenultimateRow(matrix m, int n) {
    position min = getLeftMin(m);
    int column = min.colIndex;
    int row = n - 2;
    int inter = m.values[row][column];
    for (int i = 0; i < n; ++i)
        m.values[row][i] = m.values[i][column];

    m.values[row][row] = inter;
}

// 13
bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; ++i)
        if (a[i] < a[i - 1])
            return false;
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; ++i)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int count = 0;
    for (int i = 0; i < nMatrix; ++i)
        count += hasAllNonDescendingRows(ms[i]);

    return count;
}

// 14
int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] == value)
            count++;

    return count;
}

int countZeroRows(matrix m) {
    int count = 0;
    for (int i = 0; i < m.nRows; ++i)
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            count++;

    return count;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int *zeroRowsInMatrix = (int *) malloc(sizeof(int) * nMatrix);

    int max = countZeroRows(ms[0]);
    zeroRowsInMatrix[0] = max;

    for (int i = 1; i < nMatrix; ++i) {
        zeroRowsInMatrix[i] = countZeroRows(ms[i]);
        if (zeroRowsInMatrix[i] > max)
            max = zeroRowsInMatrix[i];
    }

    for (int i = 0; i < nMatrix; ++i)
        if (zeroRowsInMatrix[i] == max)
            outputMatrix(ms[i]);

    free(zeroRowsInMatrix);
}

// 15
float getMaxAbsF(matrixF m) {
    float max = fabsf(m.values[0][0]);

    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j) {
            float x = fabsf(m.values[i][j]);
            if (x - max > FLT_EPSILON)
                max = x;
        }

    return max;
}

void printMatricesWithMinimumNorm(matrixF *ms, int nMatrix, float (*norm)(matrixF)) {
    float *norms = (float *) malloc(sizeof(float) * nMatrix);
    float min = getMaxAbsF(ms[0]);
    norms[0] = min;
    for (int i = 1; i < nMatrix; ++i) {
        norms[i] = getMaxAbsF(ms[i]);
        if (norms[i] < min)
            min = norms[i];
    }

    for (int i = 0; i < nMatrix; ++i)
        if (norms[i] == min)
            outputMatrixF(ms[i]);

    free(norms);
}

// 16
bool isSpecialElement(const int *a, int n, int colIndex) {
    for (int i = 0; i < colIndex; i++)
        if (a[colIndex] <= a[i])
            return false;

    for (int i = colIndex + 1; i < n; i++)
        if (a[colIndex] >= a[i])
            return false;

    return true;
}

int getNSpecialElement2(matrix m) {
    int count = 0;
    for (int i = 0; i < m.nRows; ++i)
        for (int j = 0; j < m.nCols; ++j)
            if(isSpecialElement(m.values[i], m.nCols, j))
                count++;

    return count;
}