#ifndef MAIN_C_ISLEXICOGRAPHICALLYORDERED_H
#define MAIN_C_ISLEXICOGRAPHICALLYORDERED_H

#include "../string_.h"

bool isLexicographicallyOrdered(char *s) {
    WordDescriptor word;
    if (!getWord(s, &word))
        return true;

    WordDescriptor currentWord;
    while(getWord(word.end, &currentWord)) {
        if(wordcmp(word, currentWord) > 0)
            return false;
        word = currentWord;
    }

    return true;
}

#endif
