#ifndef MAIN_C_FILLTHESMALLERSTRING_H
#define MAIN_C_FILLTHESMALLERSTRING_H

#include "../string_.h"

void fillTheSmallerString(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    size_t n1 = _bag.size;
    size_t n2 = _bag2.size;

    if (n1 == n2)
        return;

    char *beginDestination;
    char *beginSearch;
    if (n1 < n2) {
        beginDestination = getEndOfString(s1);
        beginSearch = _bag2.words[n1].begin;
    } else {
        beginDestination = getEndOfString(s2);
        beginSearch = _bag.words[n2].begin;
    }

    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        *beginDestination++ = ' ';
        beginDestination = copy(word.begin, word.end, beginDestination);

        beginSearch = word.end;
    }

    *beginDestination = '\0';
}

#endif
