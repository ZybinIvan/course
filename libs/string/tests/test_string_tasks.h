#ifndef LABA5B_5D_5E_TEST_STRING_TASKS_H
#define LABA5B_5D_5E_TEST_STRING_TASKS_H

#include "../tasks/removeNonLetters.h"
#include "../string_.h"
#include "../tasks/removeExtraSpaces.h"
#include "../tasks/digitsToEndLettersToStart.h"
#include "../tasks/replaceDigitForEquivalentCountOfSpaces.h"


void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

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
    char s1[] = " m  a i n \0";

    removeNonLetters(s1);

    ASSERT_STRING("main\0", s1);
}

void test_removeExtraSpaces() {
    char s[] = "  m   a  i n \0";

    removeExtraSpace(s);

    ASSERT_STRING(" m a i n \0", s);
}

void test_digitsToEndLettersToStart() {
    char s[] = "3mai12n 5e\0";

    digitsToEndLettersToStart(s);

    ASSERT_STRING("main312 e5\0", s);
}

void test_replaceDigitForEquivalentCountOfSpaces() {
    char s[] = "m1a2i3n\0";

    replaceDigitForEquivalentCountOfSpaces(s);

    ASSERT_STRING("m a  i   n\0", s);
}

void test_replaceDigitForEquivalentCountOfSpaces_withoutDigits() {
    char s[] = " main\0";

    replaceDigitForEquivalentCountOfSpaces(s);

    ASSERT_STRING(" main\0", s);
}

void test_string_tasks() {
    test_removeNonLetter();
    test_removeExtraSpaces();
    test_digitsToEndLettersToStart();
    test_replaceDigitForEquivalentCountOfSpaces();
    test_replaceDigitForEquivalentCountOfSpaces_withoutDigits();
}

#endif
