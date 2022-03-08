#ifndef LABA5B_5D_5E_REMOVEEXTRASPACES_H
#define LABA5B_5D_5E_REMOVEEXTRASPACES_H

#include <stdbool.h>
#include "../string_.h"

void removeExtraSpace(char *s) {
    if (*s == '\0')
        return;

    char *readPtr = ++s;
    while (*readPtr != '\0' && isgraph(*readPtr))
        readPtr++;

    char *recPtr = readPtr;
    while (*readPtr != '\0') {
        if (isgraph(*readPtr) || isgraph(*(readPtr - 1)))
            *recPtr++ = *readPtr;
        readPtr++;
    }

    *recPtr = '\0';
}

#endif
