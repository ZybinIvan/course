//
// Created by Иван on 06.02.2022.
//

#ifndef LABA5B_VECTOR_H
#define LABA5B_VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct vector {
    int *data;          // указатель на элементы вектора
    size_t size;        // размер вектора
    size_t capacity;    // вместимость вектора
} vector;

vector createVector(size_t n);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void shrinkToFit(vector *v);

void deleteVector(vector *v);

#endif //LABA5B_VECTOR_H

