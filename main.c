#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"
#include <assert.h>

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

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector1();
    test_pushBack_fullVector2();
    test_popBack_notEmptyVector();
}

int main() {
    test();

    return 0;
}
