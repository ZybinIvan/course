#ifndef LABA5B_5D_5E_REMOVEEXTRASPACES_H
#define LABA5B_5D_5E_REMOVEEXTRASPACES_H

#include <stdbool.h>
#include "../string_.h"

void removeExtraSpace(char *s) {
    if (*s == '\0')
        return;

    char *iRead = ++s;
    while (*iRead != '\0' && isgraph(*iRead))
        iRead++;

    char *iWrite = iRead;
    while (*iRead != '\0') {
        if (isgraph(*iRead) || isgraph(*(iRead - 1)))
            *iWrite++ = *iRead;
        iRead++;
    }

    *iWrite = '\0';
}

#endif
