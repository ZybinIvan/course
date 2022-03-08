#ifndef MAIN_C_REMOVEWORDSLIKELAST_H
#define MAIN_C_REMOVEWORDSLIKELAST_H

#include "../string_.h"

void removeWordsLikeLast(char *s) {
    getBagOfWords(&_bag, s);
    if (_bag.size == 0)
        return;

    char buffer[MAX_STRING_SIZE];
    char *endBuffer = copy(s, getEndOfString(s), buffer);
    *endBuffer = '\0';

    WordDescriptor lastWord = _bag.words[_bag.size - 1];
    for (size_t i = 0; i < _bag.size; ++i) {
        char *k1 = lastWord.begin;
        char *k2 = _bag.words[i].begin;
        if (wordcmp(_bag.words[i], lastWord)) {
            s = copy(_bag.words[i].begin, _bag.words[i].end, s);
            *s++ = ' ';
        }
    }

    s = copy(lastWord.begin, lastWord.end, s);
    *s = '\0';
}

#endif
