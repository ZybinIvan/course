#ifndef LABA5B_5D_TEST_STRING_TASKS_H
#define LABA5B_5D_TEST_STRING_TASKS_H

#include "../tasks/removeNonLetters.h"
#include "../string_.h"

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

void test_removeNonLetter();

void test_string_tasks();

#endif
