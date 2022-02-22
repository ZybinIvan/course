#ifndef LABA5B_5D_TESTFUNCTIONSOFVECTOR_H
#define LABA5B_5D_TESTFUNCTIONSOFVECTOR_H

#include <assert.h>
#include "../../vector/vector.h"

void test_pushBack_emptyVector();

void test_pushBack_fullVector1();

void test_pushBack_fullVector2();

void test_popBack_notEmptyVector();

void test_atVector_notEmptyVector();

void test_atVector_requestToLastElement();

void test_atVector_requestToMiddleElement();

void test_atVector_requestToFirstElement();

void test_back_oneElementInVector();

void test_back_multipleElementsInVector();

void test_front_oneElementInVector();

void test_front_multipleElementsInVector();

void test();

#endif //LABA5B_5D_TESTFUNCTIONSOFVECTOR_H
