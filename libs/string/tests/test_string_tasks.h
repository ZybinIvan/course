#ifndef LABA5B_5D_5E_TEST_STRING_TASKS_H
#define LABA5B_5D_5E_TEST_STRING_TASKS_H

#include <assert.h>

#include "../tasks/removeNonLetters.h"
#include "../string_.h"
#include "../tasks/removeExtraSpaces.h"
#include "../tasks/digitsToEndLettersToStart.h"
#include "../tasks/replaceDigitForEquivalentCountOfSpaces.h"
#include "../tasks/replaceWords.h"
#include "../tasks/isLexicographicallyOrdered.h"
#include "../tasks/getCountOfPalindromesWords.h"


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

void test_replace_w2LessThanW1() {
    char w1[] = "main\0";
    char w2[] = "123\0";
    char s[] = "main main task main\0";

    replace(s, w1, w2);

    ASSERT_STRING("123 123 task 123\0", s);
}

void test_replace_w1LessThanW2() {
    char w1[] = "main\0";
    char w2[] = "12345\0";
    char s[] = "main main task main\0";

    replace(s, w1, w2);

    ASSERT_STRING("12345 12345 task 12345\0", s);
}

void test_isLexicographicallyOrdered_ordered() {
    char s[] = "a abc abcd\0";

    assert(isLexicographicallyOrdered(s) == 1);

    ASSERT_STRING("1", "1");
}

void test_isLexicographicallyOrdered_notOrdered() {
    char s[] = "123 122 156\0";

    assert(isLexicographicallyOrdered(s) == 0);

    ASSERT_STRING("0", "0");
}

void test_isLexicographicallyOrdered_emptyString() {
    char s[] = "\0";

    assert(isLexicographicallyOrdered(s) == 1);

    ASSERT_STRING("1", "1");
}

void test_isLexicographicallyOrdered_allEqual() {
    char s[] = "main main main\0";

    assert(isLexicographicallyOrdered(s) == 1);

    ASSERT_STRING("1", "1");
}

void test_getCountOfPalindromesWords_withPalindromes() {
    char s[] = "main,tenet,121,r\0";

    assert((getCountOfPalindromesWords(s)) == 3);

    ASSERT_STRING("3", "3");
}

void test_getCountOfPalindromesWords_withoutPalindromes() {
    char s[] = "main,ten,123,rl\0";

    assert((getCountOfPalindromesWords(s)) == 0);

    ASSERT_STRING("0", "0");
}

void test_getCountOfPalindromesWords_emptyString() {
    char s[] = "\0";

    assert((getCountOfPalindromesWords(s)) == 0);

    ASSERT_STRING("0", "0");
}

void test_string_tasks() {
    test_removeNonLetter();

    test_removeExtraSpaces();

    test_digitsToEndLettersToStart();

    test_replaceDigitForEquivalentCountOfSpaces();
    test_replaceDigitForEquivalentCountOfSpaces_withoutDigits();

    test_replace_w2LessThanW1();
    test_replace_w1LessThanW2();

    test_isLexicographicallyOrdered_ordered();
    test_isLexicographicallyOrdered_notOrdered();
    test_isLexicographicallyOrdered_emptyString();
    test_isLexicographicallyOrdered_allEqual();

    test_getCountOfPalindromesWords_withPalindromes();
    test_getCountOfPalindromesWords_withoutPalindromes();
    test_getCountOfPalindromesWords_emptyString();
}

#endif
