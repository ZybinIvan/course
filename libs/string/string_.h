#ifndef LABA5B_5D_STRING__H
#define LABA5B_5D_STRING__H

#include <stdio.h>
#include <ctype.h>

size_t strlen_(const char *begin);

char *find(char *begin, char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp(const char *lhs, const char *rhs);

#endif //LABA5B_5D_STRING__H
