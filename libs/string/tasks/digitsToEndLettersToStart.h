#ifndef MAIN_C_DIGITSTOENDLETTERSTOSTART_H
#define MAIN_C_DIGITSTOENDLETTERSTOSTART_H

#include "../string_.h"

void digitsToEndLettersToStart(char *s) {
    char *beginSearch = s;

    WordDescriptor word;
    while(getWord(beginSearch, &word)) {
        char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
        char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isalpha);
        copyIf(_stringBuffer, endStringBuffer, recPosition, isdigit);

        beginSearch = word.end;
    }
}

#endif
