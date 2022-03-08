#ifndef MAIN_C_REPLACEDIGITFOREQUIVALENTCOUNTOFSPACES_H
#define MAIN_C_REPLACEDIGITFOREQUIVALENTCOUNTOFSPACES_H

#include "../string_.h"

void replaceDigitForEquivalentCountOfSpaces (char *s) {
    char *endBuffer = copy(s, getEndOfString(s), _stringBuffer);
    *endBuffer = '\0';

    char *readPtr = _stringBuffer;
    char *recPtr = s;

    while (*readPtr != '\0') {
        if (isdigit(*readPtr))
            for (int i = '0'; i < *readPtr; ++i)
                *recPtr++ = ' ';

        else
            *recPtr++ = *readPtr;

        readPtr++;
    }

    *recPtr = '\0';
}

#endif
