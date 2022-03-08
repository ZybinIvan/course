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
#include "../tasks/getStringWithAlternatingWords.h"
#include "../tasks/reverseWordOrder.h"


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

// task 1
void test_removeNonLetter_withSpaces() {
    char s1[] = " m  a i n \0";

    removeNonLetters(s1);

    ASSERT_STRING("main\0", s1);
}

void test_removeNonLetter_withoutSpaces() {
    char s1[] = "main\0";

    removeNonLetters(s1);

    ASSERT_STRING("main\0", s1);
}

void test_removeNonLetter_emptyString() {
    char s1[] = "\0";

    removeNonLetters(s1);

    ASSERT_STRING("\0", s1);
}

// task 2
void test_removeExtraSpaces_withExtraSpaces() {
    char s[] = "  m   a  i n \0";

    removeExtraSpace(s);

    ASSERT_STRING(" m a i n \0", s);
}

void test_removeExtraSpaces_withoutExtraSpaces() {
    char s[] = "m a i n \0";

    removeExtraSpace(s);

    ASSERT_STRING("m a i n \0", s);
}

// task 3
void test_digitsToEndLettersToStart() {
    char s[] = "3mai12n 5e\0";

    digitsToEndLettersToStart(s);

    ASSERT_STRING("main312 e5\0", s);
}

// task 4
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

// task 5
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

// task 6
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


// task 8
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

// task 9
void test_getStringWithAlternatingWords_sameCountOfWords(){
    char s1[] = "test this\0";
    char s2[] = "of function\0";

    ASSERT_STRING("test of this function\0", getStringWithAlternatingWords(s1, s2));
}

void test_getStringWithAlternatingWords_differentCountOfWords1(){
    char s1[] = "successful of function\0";
    char s2[] = "test this\0";

    ASSERT_STRING("successful test of this function\0", getStringWithAlternatingWords(s1, s2));
}

void test_getStringWithAlternatingWords_differentCountOfWords2(){
    char s1[] = "successful of\0";
    char s2[] = "test this function\0";

    ASSERT_STRING("successful test of this function\0", getStringWithAlternatingWords(s1, s2));
}

// task 10
void test_reverseWordOrder() {
    char s[] = "function this of test successful\0";

    reverseWordOrder(s);

    ASSERT_STRING("successful test of this function", s);
}
void test_reverseWordOrder2() {
    char s[] = "main   test\0";

    reverseWordOrder(s);

    ASSERT_STRING("test main\0", s);
}

void test_reverseWordOrder_emptyString() {
    char s[] = "\0";

    reverseWordOrder(s);

    ASSERT_STRING("\0", s);
}


void test_string_tasks() {
    // task 1
    test_removeNonLetter_withSpaces();
    test_removeNonLetter_withoutSpaces();
    test_removeNonLetter_emptyString();

    // task 2
    test_removeExtraSpaces_withExtraSpaces();
    test_removeExtraSpaces_withoutExtraSpaces();

    // task 3
    test_digitsToEndLettersToStart();

    // task 4
    test_replaceDigitForEquivalentCountOfSpaces();
    test_replaceDigitForEquivalentCountOfSpaces_withoutDigits();

    // task 5
    test_replace_w2LessThanW1();
    test_replace_w1LessThanW2();

    // task 6
    test_isLexicographicallyOrdered_ordered();
    test_isLexicographicallyOrdered_notOrdered();
    test_isLexicographicallyOrdered_emptyString();
    test_isLexicographicallyOrdered_allEqual();

    // task 8
    test_getCountOfPalindromesWords_withPalindromes();
    test_getCountOfPalindromesWords_withoutPalindromes();
    test_getCountOfPalindromesWords_emptyString();

    // task 9
    test_getStringWithAlternatingWords_sameCountOfWords();
    test_getStringWithAlternatingWords_differentCountOfWords1();
    test_getStringWithAlternatingWords_differentCountOfWords2();

    // task 10
    test_reverseWordOrder();
    test_reverseWordOrder2();
    test_reverseWordOrder_emptyString();
}

#endif
