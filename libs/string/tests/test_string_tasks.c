#include "test_string_tasks.h"
#include "../string_.h"

void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, " Got : \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void test_removeNonLetter() {
    char s1[] = " m a i n \0";

    removeNonLetters(s1);

    ASSERT_STRING("main\0", s1);
}

void test_string_tasks() {
    test_removeNonLetter();
}