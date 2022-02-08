//
// Created by Иван on 08.02.2022.
//

#ifndef LABA5B_VECTORVOID_H
#define LABA5B_VECTORVOID_H

#include <limits.h>

typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;

#endif //LABA5B_VECTORVOID_H
