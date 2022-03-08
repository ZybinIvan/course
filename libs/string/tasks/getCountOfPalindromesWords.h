#ifndef MAIN_C_GETCOUNTOFPALINDROMESWORDS_H
#define MAIN_C_GETCOUNTOFPALINDROMESWORDS_H

#include "../string_.h"

int getCountOfPalindromesWords(char *s) {
    int count = 0;
    WordDescriptor word;

    while(getWordComma(s, &word)) {
        if (isPalindromeWord(word))
            count++;

        s = word.end;
    }

    return count;
}

#endif