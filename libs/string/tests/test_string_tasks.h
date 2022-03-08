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
#include "../tasks/printWordBeforeFirstWordWithA.h"
#include "../tasks/findLastWordOfFirstStringThatInTheSecondString.h"
#include "../tasks/areThereTheSameWordsInTheString.h"
#include "../tasks/areThereTheAnagramsInTheString.h"
#include "../tasks/getStringDifferentFromLastWord.h"
#include "../tasks/findWordBeforeFirstCommonWord.h"


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

void test_replaceDigitForEquivalentCountOfSpaces_onlyDigits() {
    char s[] = "123\0";

    replaceDigitForEquivalentCountOfSpaces(s);

    ASSERT_STRING("      \0", s);
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
void test_getStringWithAlternatingWords_sameCountOfWords() {
    char s1[] = "test this\0";
    char s2[] = "of function\0";

    ASSERT_STRING("test of this function\0", getStringWithAlternatingWords(s1, s2));
}

void test_getStringWithAlternatingWords_differentCountOfWords1() {
    char s1[] = "successful of function\0";
    char s2[] = "test this\0";

    ASSERT_STRING("successful test of this function\0", getStringWithAlternatingWords(s1, s2));
}

void test_getStringWithAlternatingWords_differentCountOfWords2() {
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

// task 11
void testAll_getWordBeforeFirstWordWithA() {
    char *beginWord, *endWord;

    char s1[] = "";
    assert (getWordBeforeFirstWordWithA(s1, &beginWord, &endWord) == EMPTY_STRING);

    char s2[] = " ABC ";
    assert (getWordBeforeFirstWordWithA(s2, &beginWord, &endWord) == FIRST_WORD_WITH_A);

    char s3[] = "BC A";
    assert (getWordBeforeFirstWordWithA(s3, &beginWord, &endWord) == WORD_FOUND);
    char got[MAX_WORD_SIZE];
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING ("BC", got);

    char s4[] = "B Q WE YR OW IUWR ";
    assert (getWordBeforeFirstWordWithA(s4, &beginWord, &endWord) == NOT_FOUND_A_WORD_WITH_A);
}

// task 12
void test_findLastWordOfFirstStringThatInTheSecondString() {
    char s1[] = "main pop char qwerty pop\0";
    char s2[] = "fuf qwerty pop\0";
    char s[MAX_WORD_SIZE];

    WordDescriptor word = findLastWordOfFirstStringThatInTheSecondString(s1, s2);
    wordDescriptorToString(word, s);

    ASSERT_STRING("pop", s);
}

void test_findLastWordOfFirstStringThatInTheSecondString_withoutSameWords() {
    char s1[] = "main pop\0";
    char s2[] = "qwerty\0";
    char s[MAX_WORD_SIZE];

    WordDescriptor word = findLastWordOfFirstStringThatInTheSecondString(s1, s2);
    wordDescriptorToString(word, s);

    ASSERT_STRING("\0", s);
}

// task 13
void test_areThereTheSameWordsInTheString_withSameWords() {
    char s[] = "main qwerty pop main\0";

    assert(areThereTheSameWordsInTheString(s) == 1);

    ASSERT_STRING("1", "1");
}

void test_areThereTheSameWordsInTheString_withoutSameWords() {
    char s[] = "main qwerty pop\0";

    assert(areThereTheSameWordsInTheString(s) == 0);

    ASSERT_STRING("1", "1");
}

// task 14
void test_areThereTheAnagramsInTheString_withAnagrams() {
    char s[] = "main ainm qwert fuf\0";

    assert(areThereTheAnagramsInTheString(s) == 1);

    ASSERT_STRING("1", "1");
}

void test_areThereTheAnagramsInTheString_withoutAnagrams() {
    char s[] = "main qwert fuf\0";

    assert(areThereTheAnagramsInTheString(s) == 0);

    ASSERT_STRING("0", "0");
}

void test_areThereTheAnagramsInTheString_emptyString() {
    char s[] = "\0";

    assert(areThereTheAnagramsInTheString(s) == 0);

    ASSERT_STRING("0", "0");
}

// task 15
void test_getStringDifferentFromLastWord() {
    char s1[] = "a b cd b b s b\0";
    char *s2 = getStringDifferentFromLastWord(s1);

    ASSERT_STRING("a cd s\0", s2);
}

void test_getStringDifferentFromLastWord_emptyString() {
    char s1[] = "\0";
    char *s2 = getStringDifferentFromLastWord(s1);

    ASSERT_STRING("\0", s2);
}

// task 16
void test_findWordBeforeFirstCommonWord_withCommonWord() {
    char s1[] = "a b c dd c\0";
    char s2[] = "gn d c p \0";
    char s[MAX_WORD_SIZE];

    WordDescriptor word = findWordBeforeFirstCommonWord(s1, s2);
    wordDescriptorToString(word, s);

    ASSERT_STRING("b\0", s);
}

void test_findWordBeforeFirstCommonWord_withoutCommonWord() {
    char s1[] = "a b c d\0";
    char s2[] = "q w e r t y\0";
    char s[MAX_WORD_SIZE];

    WordDescriptor word = findWordBeforeFirstCommonWord(s1, s2);
    wordDescriptorToString(word, s);

    ASSERT_STRING("\0", s);
}

void test_findWordBeforeFirstCommonWord_commonIsFirst() {
    char s1[] = "a b c d\0";
    char s2[] = "a w e r t y\0";
    char s[MAX_WORD_SIZE];

    WordDescriptor word = findWordBeforeFirstCommonWord(s1, s2);
    wordDescriptorToString(word, s);

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
    test_replaceDigitForEquivalentCountOfSpaces_onlyDigits();

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

    // task 11
    testAll_getWordBeforeFirstWordWithA();

    // task 12
    test_findLastWordOfFirstStringThatInTheSecondString();
    test_findLastWordOfFirstStringThatInTheSecondString_withoutSameWords();

    // task 13
    test_areThereTheSameWordsInTheString_withSameWords();
    test_areThereTheSameWordsInTheString_withoutSameWords();

    // task 14
    test_areThereTheAnagramsInTheString_withAnagrams();
    test_areThereTheAnagramsInTheString_withoutAnagrams();
    test_areThereTheAnagramsInTheString_emptyString();

    // task 15
    test_getStringDifferentFromLastWord();
    test_getStringDifferentFromLastWord_emptyString();

    // task 16
    test_findWordBeforeFirstCommonWord_withCommonWord();
    test_findWordBeforeFirstCommonWord_withoutCommonWord();
    test_findWordBeforeFirstCommonWord_commonIsFirst();
}

#endif
