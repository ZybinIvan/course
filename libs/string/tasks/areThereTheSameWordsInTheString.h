#ifndef MAIN_C_ARETHERETHESAMEWORDSINTHESTRING_H
#define MAIN_C_ARETHERETHESAMEWORDSINTHESTRING_H

#include "../string_.h"

bool areThereTheSameWordsInTheString(char *s) {
    getBagOfWords(&_bag, s);
    for (size_t i = 0; i < _bag.size; ++i) {
        for (size_t j = i + 1; j < _bag.size; ++j) {
            if (!wordcmp(_bag.words[i], _bag.words[j]))
                return true;
        }
    }

    return false;
}

#endif
