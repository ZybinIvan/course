#ifndef MAIN_C_PRINTWORDBEFOREFIRSTWORDWITHA_H
#define MAIN_C_PRINTWORDBEFOREFIRSTWORDWITHA_H

#include "../string_.h"

bool isAInTheWord(WordDescriptor word) {
    while (word.begin != word.end) {
        if (*word.begin == 'a' || *word.begin == 'A')
            return true;
        word.begin++;
    }

    return false;
}

WordDescriptor getFirstWordWithA(char *s) {
    char *beginDestination = s;
    WordDescriptor word;
    while (getWord(beginDestination, &word)) {
        if (isAInTheWord(word))
            return word;

        beginDestination = word.end;
    }
    word.begin = word.end;

    return word;
}

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(
        char *s, char **beginWordBefore, char **endWordBefore) {

    WordDescriptor firstWordWithA = getFirstWordWithA(s);
    char *k = firstWordWithA.begin;
    if (*findNonSpace(s) == '\0')
        return EMPTY_STRING;
    else if (*findNonSpace(firstWordWithA.begin) == '\0')
        return NOT_FOUND_A_WORD_WITH_A;
    else if (findNonSpace(s) == firstWordWithA.begin)
        return FIRST_WORD_WITH_A;
    else {
        WordDescriptor word;
        getWordReverse(firstWordWithA.begin - 1, s - 1, &word);
        *beginWordBefore = word.begin;
        *endWordBefore = word.end;
        return WORD_FOUND;
    }
}

void printWordBeforeFirstWordWithA(char *s) {
    WordDescriptor wordBeforeA;
    if (getWordBeforeFirstWordWithA(s, &wordBeforeA.begin, &wordBeforeA.end) == WORD_FOUND) {
        char wordBuffer[MAX_WORD_SIZE];
        char *endWordBuffer = copy(wordBeforeA.begin, wordBeforeA. end, wordBuffer);
        *endWordBuffer = '\0';

        puts(wordBuffer);
    } else
        printf("Word not found.\n");
}

#endif
