#ifndef MAIN_C_GETSTRINGDIFFERENTFROMLASTWORD_H
#define MAIN_C_GETSTRINGDIFFERENTFROMLASTWORD_H

#include "../string_.h"

char *getStringDifferentFromLastWord(char *s) {
    char *newString = malloc(strlen_(s) + 1);
    char *endOfNewString = newString;
    getBagOfWords(&_bag, s);

    if (_bag.size == 0) {
        free(newString);
        return s;
    }

    size_t n = _bag.size - 1;
    for (size_t i = 0; i < n; ++i)
        if(wordcmp(_bag.words[i], _bag.words[n])) {
            endOfNewString = copy(_bag.words[i].begin, _bag.words[i].end, endOfNewString);
            *endOfNewString++ = ' ';
        }

    *(--endOfNewString) = '\0';

    return newString;
}

#endif
