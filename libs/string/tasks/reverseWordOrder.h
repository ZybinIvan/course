#ifndef MAIN_C_REVERSEWORDORDER_H
#define MAIN_C_REVERSEWORDORDER_H

#include "../string_.h"

void reverseWordOrder(char *s) {
    char *endBuffer = copy(s, getEndOfString(s), _stringBuffer);
    *endBuffer = '\0';

    WordDescriptor word;
    while(getWordReverse(endBuffer - 1, _stringBuffer - 1, &word)) {
        s = copy(word.begin, word.end, s);
        *s++ = ' ';
        endBuffer = word.begin;
    }

    *(--s) = '\0' ;
}

#endif
