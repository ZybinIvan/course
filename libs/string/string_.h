#ifndef LABA5B_5D_STRING__H
#define LABA5B_5D_STRING__H

#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <strings.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20


char _stringBuffer[MAX_STRING_SIZE + 1];

// Возвращает кол-во символов в строке
size_t strlen_(const char *begin);

// Возвращает указатель на первый элемент ch в строке
char *find(char *begin, char *end, int ch);

// Возвращает указатель на первый не пробельный символ
char *findNonSpace(char *begin);

// Возвращает указатель на первый пробельный символ
char *findSpace(char *begin);

// Возвращает указатель на первый не пробельный символ справа
char *findNonSpaceReverse(char *rbegin, const char *rend);

// Возвращает указатель на первый пробельный символ справа
char *findSpaceReverse(char *rbegin, const char *rend);

// Возвращает 0, если строки равны, отрицательное значение, если lhs располагается до rhs
// в лексикографическом порядке, и положительное если после
int strcmp_(const char *lhs, const char *rhs);

// Записывает по адресу beginDestination фрагмент памяти, с beginSource до endSource
char *copy(const char *beginSource, const char *endSource, char *beginDestination);

// Записывает по адресу beginDestination фрагмент памяти, с beginSource до endSource, удовлетворяющие условию f
char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

// (справа налево)
// Записывает по адресу beginDestination фрагмент памяти, с rbeginSource до rendSource, удовлетворяющие условию f
char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

char *getEndOfString(char *s);

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

int getWord(char *beginSearch, WordDescriptor *word);

int getWordReverse(char *rBegin, char *rEnd, WordDescriptor *word);

int wordcmp(WordDescriptor w1, WordDescriptor w2);

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

BagOfWords _bag;
BagOfWords _bag2;

void getBagOfWords(BagOfWords *bag, char *s);

char *findNonComma(char *begin);

char *findComma(char *begin);

int getWordComma(char *beginSearch, WordDescriptor *word);

bool isPalindromeWord(WordDescriptor word);

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

void wordDescriptorToString(WordDescriptor word, char *destination);

#endif //LABA5B_5D_STRING__H
