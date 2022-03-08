#ifndef MAIN_C_PRINTWORDSINREVERSEORDER_H
#define MAIN_C_PRINTWORDSINREVERSEORDER_H

#include "../string_.h"

void printWordInReverseOrder(char *s) {
    getBagOfWords(&_bag, s);
    for (long long int i = _bag.size - 1; i >= 0; --i) {
        char word[MAX_WORD_SIZE];
        char *endOfWord = copy(_bag.words[i].begin, _bag.words[i].end, word);
        *endOfWord = '\0';
        puts(word);
    }
}

#endif
