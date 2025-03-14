#include <iostream>
#include <cassert>
#include <stdexcept>
#include "../../deque/cpp/Deque.h"


Deque deque;

void setup() {
    deque = Deque(4);
}

void testAppendLeft() {
    setup();
    deque = Deque(3);
    deque.appendLeft(10);
    assert(deque.peekLeft() == 10);
    deque.appendLeft(20);
    assert(deque.peekLeft() == 20);
    deque.appendLeft(3);
    assert(deque.peekLeft() == 3);
    assert(deque.getCapacity() == 3);
    deque.appendLeft(9);
    assert(deque.getCapacity() == 6);
}

void testAppendRight() {
    setup();
    deque = Deque(3);
    deque.appendRight(10);
    assert(deque.peekRight() == 10);
    deque.appendRight(20);
    assert(deque.peekRight() == 20);
    deque.appendRight(3);
    assert(deque.peekRight() == 3);
    assert(deque.getCapacity() == 3);
    deque.appendRight(9);
    assert(deque.getCapacity() == 6);
}


void testPopLeft() {
     setup();
    try {
        deque.popLeft();
    } catch (const std::out_of_range& e) {
        assert(std::string(e.what()) == "O Deque está vazio"); 
    }
    deque.appendLeft(10);
    deque.appendRight(7);
    deque.appendLeft(20);
    deque.appendRight(9);
    assert(deque.popLeft() == 20);
    assert(deque.popLeft() == 10);
    assert(deque.popLeft() == 7);
    assert(deque.popLeft() == 9);
}

void testPopRight() {
    setup();
    try {
        deque.popRight();
    } catch (const std::out_of_range& e) {
        assert(std::string(e.what()) == "O Deque está vazio");
    }
    deque.appendLeft(10);
    deque.appendRight(7);
    deque.appendLeft(20);
    deque.appendRight(9);
    assert(deque.popRight() == 9);
    assert(deque.popRight() == 7);
    assert(deque.popRight() == 10);
    assert(deque.popRight() == 20);
}

void testPeekLeftAndRight() {
    setup();
    try {
        deque.peekLeft();
    } catch (const std::out_of_range& e) {
        assert(std::string(e.what()) == "O Deque está vazio");
    }
    try {
        deque.peekRight();
    } catch (const std::out_of_range& e) {
        assert(std::string(e.what()) == "O Deque está vazio");
    }
    deque.appendLeft(10);
    deque.appendLeft(20);
    deque.appendRight(7);
    deque.appendRight(9);
    assert(  deque.peekLeft() == 20);
    assert( deque.peekRight() == 9);
    deque.popLeft();
    deque.popRight();
    assert(deque.peekLeft() == 10);
    assert(deque.popRight() == 7);
}

void testIsEmpty() {
    setup();
    assert(deque.isEmpty());
    deque.appendRight(10);
    assert(!deque.isEmpty());
    deque.popLeft();
    assert(deque.isEmpty());
}

void testContains() {
    setup();
    deque.appendRight(5);
    deque.appendRight(10);
    deque.appendRight(15);
    assert(deque.contains(10));
    assert(!deque.contains(20));
    deque.popLeft();
    deque.popLeft();
    assert(!deque.contains(10));
}

void testResize() {
    setup();
    deque = Deque(2);
    deque.appendRight(1);
    deque.appendRight(2);
    assert(deque.getCapacity() == 2);
    assert(deque.getSize() == 2);
    deque.appendRight(3);
    assert(deque.getCapacity() == 4);
    assert(deque.getSize() == 3);
    deque.appendRight(4);
    assert(deque.getCapacity() == 4);
    deque.appendRight(5);
    assert(deque.getCapacity() == 8);
    deque.popLeft();
    deque.popLeft();
    deque.popLeft();
    assert(deque.isEmpty());
}

int main() {
    testAppendLeft();
    testAppendRight();
    testPopLeft();
    testPopRight();
    testPeekLeftAndRight();
    testIsEmpty();
    testContains();
    testResize();
    std::cout << "testes aprovados" << std::endl;
    return 0;
}
