#ifndef LABA5B_5D_REMOVENONLETTERS_H
#define LABA5B_5D_REMOVENONLETTERS_H

#include "../string_.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}


#endif
