//
// Created by Иван on 14.02.2022.
//

#include <stdio.h>

void swap(void *a, void *b, size_t bytes) {
    char *pa = a;
    char *pb = b;

    for (size_t i = 0; i < bytes; ++i) {
        char t = *pa;
        *pa = *pb;
        *pb = t;
    }
}