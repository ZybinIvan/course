#ifndef MAIN_C_FINDLASTWORDOFFIRSTSTRINGTHATINTHESECONDSTRING_H
#define MAIN_C_FINDLASTWORDOFFIRSTSTRINGTHATINTHESECONDSTRING_H

#include "../string_.h"

WordDescriptor findLastWordOfFirstStringThatInTheSecondString(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    for (long long int i = _bag.size - 1; i >= 0; --i) {
        for (size_t j = 0; j < _bag2.size; ++j) {
            if (!wordcmp(_bag.words[i], _bag2.words[j]))
                return _bag.words[i];
        }
    }

    WordDescriptor word;
    word.begin = getEndOfString(s1);
    word.end = word.begin;

    return word;
}

#endif
