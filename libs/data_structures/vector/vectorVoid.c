//
// Created by Иван on 08.02.2022.
//

#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    void *data = malloc(baseTypeSize * n);
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vectorVoid) {data, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    v->data = realloc(v->data, v->baseTypeSize * newCapacity);

    if (v->data == NULL && newCapacity != 0) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    if (newCapacity == 0)
        v->data = NULL;
    else if (newCapacity < v->size)
        v->size = newCapacity;

    v->capacity = newCapacity;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
    v->baseTypeSize = 0;
}

