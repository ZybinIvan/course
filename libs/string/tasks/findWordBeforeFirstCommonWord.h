#ifndef MAIN_C_FINDWORDBEFOREFIRSTCOMMONWORD_H
#define MAIN_C_FINDWORDBEFOREFIRSTCOMMONWORD_H

#include "../string_.h"

WordDescriptor findWordBeforeFirstCommonWord(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);

    for (size_t i = 1; i < _bag.size; ++i) {
        for (int j = 0; j < _bag2.size; ++j) {
            if (!wordcmp(_bag.words[i], _bag2.words[j]))
                return (_bag.words[i - 1]);
        }
    }

    WordDescriptor word;
    word.begin = getEndOfString(s1);
    word.end = word.begin;

    return word;
}


#endif
