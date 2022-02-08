#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures//vector/vectorVoid.h"


void test_pushBack_emptyVector() {
    vector v = createVector(3);
    pushBack(&v, 1);

    assert(v.data[0] == 1);
    assert(v.size == 1);
    assert(v.capacity == 3);
}

void test_pushBack_fullVector1() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);

    assert(v.data[0] == 1 && v.data[1] == 2);
    assert(v.size == 2);
    assert(v.capacity == 2);
}

void test_pushBack_fullVector2() {
    vector v = createVector(2);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    assert(v.data[0] == 1 && v.data[1] == 2);
    assert(v.size == 3);
    assert(v.capacity == 4);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);

    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    pushBack(&v, 1);
    pushBack(&v, 2);

    assert(*atVector(&v, 0) == 1);
    assert(atVector(&v, 1) == &v.data[1]);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    assert(*atVector(&v, 2) == 3);
    assert(atVector(&v, 2) == &v.data[2]);
}

void test_atVector_requestToMiddleElement() {
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    assert(*atVector(&v, 1) == 2);
    assert(atVector(&v, 1) == &v.data[1]);
}

void test_atVector_requestToFirstElement() {
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    assert(*atVector(&v, 0) == 1);
    assert(atVector(&v, 0) == &v.data[0]);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 1);

    assert(*back(&v) == 1);
    assert(back(&v) == &v.data[0]);
}

void test_back_multipleElementsInVector() {
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    assert(*back(&v) == 3);
    assert(back(&v) == &v.data[2]);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 1);

    assert(*front(&v) == 1);
    assert(front(&v) == &v.data[0]);
}

void test_front_multipleElementsInVector() {
    vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    assert(*front(&v) == 1);
    assert(front(&v) == &v.data[0]);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector1();
    test_pushBack_fullVector2();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_atVector_requestToFirstElement();
    test_atVector_requestToMiddleElement();
    test_back_oneElementInVector();
    test_back_multipleElementsInVector();
    test_front_oneElementInVector();
    test_front_multipleElementsInVector();
}

int main() {
    test();

    vectorVoid vv;

    return 0;
}
