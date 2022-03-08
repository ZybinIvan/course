#ifndef MAIN_C_GETSTRINGWITHALTERNATINGWORDS_H
#define MAIN_C_GETSTRINGWITHALTERNATINGWORDS_H

#include "../string_.h"

char *getStringWithAlternatingWords(char *s1, char *s2) {
    char *newStr = malloc(strlen_(s1) + strlen_(s2) + 3);
    char *endStr = newStr;

    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1;
    char *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            endStr = copy(word1.begin, word1.end, endStr);
            *endStr++ = ' ';
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            endStr = copy(word2.begin, word2.end, endStr);
            *endStr++ = ' ';
            beginSearch2 = word2.end;
        }
    }
    *(--endStr) = '\0';

    return newStr;
}

#endif
