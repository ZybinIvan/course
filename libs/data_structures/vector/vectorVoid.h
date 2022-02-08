//
// Created by Иван on 08.02.2022.
//

#ifndef LABA5B_VECTORVOID_H
#define LABA5B_VECTORVOID_H

#include <limits.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;

vectorVoid createVectorV(size_t n, size_t baseTypeSize);

void reserveV(vectorVoid *v, size_t newCapacity);

void shrinkToFitV(vectorVoid *v);

void clearV(vectorVoid *v);

void deleteVectorV(vectorVoid *v);

#endif //LABA5B_VECTORVOID_H
