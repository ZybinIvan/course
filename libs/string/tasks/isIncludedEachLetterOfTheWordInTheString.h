#ifndef MAIN_C_ISINCLUDEDEACHLETTEROFTHEWORDINTHESTRING_H
#define MAIN_C_ISINCLUDEDEACHLETTEROFTHEWORDINTHESTRING_H

#include "../string_.h"

#define MAX_CHAR 128

bool isIncludedEachLetterOfTheWordInTheString(char *s, char *word) {
    bool stringSymbols[MAX_CHAR] = {false};

    while (*s != '\0')
        stringSymbols[*s++] = true;

    while (*word != '\0') {
        char c = *word;
        bool k = stringSymbols[*word];
        if (stringSymbols[*word++] == false)
            return false;
    }
    return true;
}

#endif
