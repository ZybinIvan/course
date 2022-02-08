#include "vector.h"

vector createVector(size_t n) {
    int *data = (int *) malloc(sizeof(int) * n);
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector) {data, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    v->data = realloc(v->data, sizeof(int) * newCapacity);
    if (v->data == NULL && newCapacity > 0) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    if (newCapacity == 0)
        v->data = NULL;
    else if (newCapacity < v->size)
        v->size = newCapacity;


    v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    v->size = 0;
    v->capacity = 0;
    free(v->data);
}

bool isEmpty(vector *v) {
    return !v->size;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->size == v->capacity) {
        if (v->capacity == 0)
            reserve(v, 1);
        else
            reserve(v, v->capacity * 2);
    }

    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "empty vector");
        exit(1);
    }
    v->size--;
}