#ifndef LABA5B_5D_STRING__H
#define LABA5B_5D_STRING__H

#include <stdio.h>
#include <ctype.h>
#include <memory.h>

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
int strcmp(const char *lhs, const char *rhs);

// Записывает по адресу beginDestination фрагмент памяти, с beginSource до endSource
char *copy(const char *beginSource, const char *endSource, char *beginDestination);

// Записывает по адресу beginDestination фрагмент памяти, с beginSource до endSource, удовлетворяющие условию f
char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

// (справа налево)
// Записывает по адресу beginDestination фрагмент памяти, с rbeginSource до rendSource, удовлетворяющие условию f
char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

char* getEndOfString(char *s);

#endif //LABA5B_5D_STRING__H
