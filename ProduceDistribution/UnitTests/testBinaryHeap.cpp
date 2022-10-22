#include <catch2/catch_test_macros.hpp>
#include <string>
#include <iostream>
#include "BinaryHeap.h"

TEST_CASE("basic operations for heap") {

    //heap of ints
    BinaryHeap<int> heap;
    REQUIRE(heap.getMaxSize() == 64);
    //heap of doubles
    BinaryHeap<double> heap2;

    //heap of ints with initial size of 128
    BinaryHeap<int> heap3(128);
    REQUIRE(heap3.getMaxSize() == 128);

    //heap can increase its size if needed
    for (int i = 0; i < 100; ++i) {
        heap2.insert(i);
    }
    REQUIRE(heap2.getMaxSize() == 128);

    //test insert
    heap.insert(7);
    REQUIRE( heap.getSize() == 1);

    //test remove
    int retval = heap.remove();
    REQUIRE( retval == 7);
    REQUIRE( heap.getSize() == 0);

    heap.insert(1);
    heap.insert(5);
    heap.insert(2);
    heap.insert(3);
    heap.insert(4);

    retval = heap.remove();
    REQUIRE( retval == 5 );

}

