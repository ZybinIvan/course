#ifndef MAIN_C_REPLACEDIGITFOREQUIVALENTCOUNTOFSPACES_H
#define MAIN_C_REPLACEDIGITFOREQUIVALENTCOUNTOFSPACES_H

#include "../string_.h"

void replaceDigitForEquivalentCountOfSpaces (char *s) {
    char *endBuffer = copy(s, getEndOfString(s), _stringBuffer);
    *endBuffer = '\0';

    char *iRead = _stringBuffer;
    char *iWrite = s;

    while (*iRead != '\0') {
        if (isdigit(*iRead))
            for (int i = '0'; i < *iRead; ++i)
                *iWrite++ = ' ';

        else
            *iWrite++ = *iRead;

        iRead++;
    }

    *iWrite = '\0';
}

#endif
