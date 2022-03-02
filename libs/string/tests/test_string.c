#include "assert.h"

#include "test_string.h"

void test_strlen_() {
    char s1[] = "maIn\0";
    char s2[] = "m a i n\0";
    char s3[] = "\0";

    assert(strlen_(s1) == 4 && strlen_(s2) == 7 && strlen_(s3) == 0);
}

void test_find() {
    char s1[] = "ma in\0";
    char s2[] = "\0";

    assert(find(s1, s1 + 5, 'a') == s1 + 1 && find(s2, s2, 'a') == s2);
}

void test_findNonSpace() {
    char s1[] = "\tmain\0";
    char s2[] = " m\0";
    char s3[] = " \0";
    char s4[] = "\0";

    assert(findNonSpace(s1) == s1 + 1 && findNonSpace(s2) == s2 + 1);
    assert(findNonSpace(s3) == s3 + 1 && findNonSpace(s4) == s4);
}

void test_findSpace() {
    char s1[] = "main\0";
    char s2[] = " maiN\0";
    char s3[] = " \0";
    char s4[] = "\0";

    assert(findSpace(s1) == s1 + 4 && findSpace(s2) == s2);
    assert(findSpace(s3) == s3 && findSpace(s4) == s4);
}

void test_findNonSpaceReverse() {
    char s1[] = "main\t\0";
    char s2[] = " maiN \0";
    char s3[] = " \0";
    char s4[] = "\0";

    assert(findNonSpaceReverse(s1 + 3, s1 - 1) == s1 + 3 && findNonSpaceReverse(s2 + 5, s2 - 1) == s2 + 4);
    assert(findNonSpaceReverse(s3, s3 - 1) == s3 - 1 && findNonSpaceReverse(s4, s4 - 1) == s4);
}

void test_findSpaceReverse() {
    char s1[] = " main\0";
    char s2[] = "main\t \0";
    char s3[] = "\t\0";
    char s4[] = "\0";

    assert(findSpaceReverse(s1 + 4, s1 - 1) == s1 && findSpaceReverse(s2 + 5, s2 - 1) == s2 + 5);
    assert(findSpaceReverse(s3, s3 - 1) == s3 && findSpaceReverse(s4, s4 - 1) == s4 - 1);
}

void test_strcmp() {
    char s1[] = "main\0";
    char s2[] = "main\0";
    char s3[] = "123\0";
    char s4[] = "42\0";

    assert(strcmp_(s1, s2) == 0 && strcmp_(s3, s4) < 0);
    assert(strcmp_(s1, s3) > 0 && strcmp_(s1, s4) > 0);
}

void test_copy() {
    char s1[] = "main\0";
    char s2[5];

    char *end = copy(s1, s1 + 4, s2);
    *end = '\0';

    assert(strcmp_(s1, s2) == 0);
}

int isGraph(int symbol) {
    return !isspace(symbol);
}

void test_copyIf() {
    char s1[] = " mai n\0";
    char s2[5];
    char s3[] = "main\0";

    char *end = copyIf(s1, s1 + 6, s2, isGraph);
    *end = '\0';

    assert(strcmp_(s3, s2) == 0);
}

// общий тест
void test_functions_string() {
    test_strlen_();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_copyIf();
}