#include "string_.h"

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (isspace(*begin) && *begin != '\0')
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (!isspace(*begin) && *begin != '\0')
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs && *rhs && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}