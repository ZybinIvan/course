#ifndef MAIN_C_REPLACEWORDS_H
#define MAIN_C_REPLACEWORDS_H

#include "../string_.h"


void replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        char *endBuffer = copy(source, getEndOfString(source), _stringBuffer);
        *endBuffer = '\0';
        readPtr = _stringBuffer;
        recPtr = source;
    }

    WordDescriptor currentWord;
    while (getWord(readPtr, &currentWord)) {
        if (!wordcmp(word1, currentWord))
            recPtr = copy(word2.begin, word2.end, recPtr);
        else
            recPtr = copy(currentWord.begin, currentWord.end, recPtr);

        readPtr = currentWord.end;
        recPtr = copy(readPtr, findNonSpace(readPtr), recPtr);
    }
    *recPtr = '\0';
}

#endif
