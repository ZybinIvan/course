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
    while (isspace(*begin))
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

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs && *rhs && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    size_t size = endSource - beginSource;
    memcpy(beginDestination, beginSource, size);

    return beginDestination + size;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource))
            *(beginDestination++) = *beginSource;

        beginSource++;
    }

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource))
            *(beginDestination++) = *rbeginSource;

        rbeginSource--;
    }

    return beginDestination;
}

char *getEndOfString(char *s) {
    return s + strlen_(s);
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}

int getWordReverse(char *rBegin, char *rEnd, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rBegin, rEnd);
    if (word->end == rEnd)
        return 0;

    word->begin = findSpaceReverse(word->end, rEnd) + 1;
    word->end++;

    return 1;
}

int wordcmp(WordDescriptor w1, WordDescriptor w2) {
    while (w1.begin != (w1.end - 1) && w2.begin != (w2.end - 1) && *w1.begin == *w2.begin) {
        w1.begin++;
        w2.begin++;
    }

    return *w1.begin - *w2.begin;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    size_t size = 0;
    while (getWord(s, &bag->words[size]))
        s = bag->words[size++].end;

    bag->size = size;
}

char *findNonComma(char *begin) {
    while (*begin == ',')
        begin++;

    return begin;
}

char *findComma(char *begin) {
    while (*begin != ',' && *begin != '\0')
        begin++;

    return begin;
}

int getWordComma(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonComma(beginSearch);
    if (*word->begin == '\0')
        return 0;

    word->end = findComma(word->begin);

    return 1;
}

bool isPalindromeWord(WordDescriptor word) {
    word.end--;

    while (word.begin <= word.end && *word.begin == *word.end) {
        word.begin++;
        word.end--;
    }

    return (word.begin > word.end);
}

void wordDescriptorToString(WordDescriptor word, char *destination) {
    char *end = copy(word.begin, word.end, destination);
    *end = '\0';
}



