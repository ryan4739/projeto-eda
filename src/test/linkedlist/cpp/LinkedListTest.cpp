#include <iostream>
#include <stdexcept>
#include <cassert>
#include "../../../main/linkedlist/cpp/LinkedList.h"

void testIsEmpty() {
    LinkedList ll;
    assert(ll.isEmpty() == true);
    assert(ll.sizeLL() == 0);

    ll.addFirst(10);
    assert(ll.isEmpty() == false);
    assert(ll.sizeLL() == 1);

    ll.removeFirst();
    assert(ll.isEmpty() == true);

    ll.addLast(10);
    assert(ll.isEmpty() == false);

    ll.removeLast();
    assert(ll.isEmpty() == true);

    ll.addLast(10);
    ll.addLast(20);
    ll.addLast(30);
    assert(ll.isEmpty() == false);
}

void testAddFirst() {
    LinkedList ll;
    ll.addFirst(10);
    assert(ll.getFirst() == 10);
    assert(ll.sizeLL() == 1);

    ll.addFirst(20);
    assert(ll.getFirst() == 20);
    assert(ll.sizeLL() == 2);
    assert(ll.toString() == "20 -> 10");

    ll.addFirst(30);
    assert(ll.getFirst() == 30);
    assert(ll.sizeLL() == 3);
    assert(ll.toString() == "30 -> 20 -> 10");

    ll.removeFirst();
    ll.removeFirst();
    ll.removeFirst();
    assert(ll.sizeLL() == 0);

    ll.addFirst(15);
    assert(ll.getFirst() == 15);
}

void testAddLast() {
    LinkedList ll;
    ll.addLast(10);
    assert(ll.getLast() == 10);
    assert(ll.sizeLL() == 1);

    ll.addLast(20);
    assert(ll.getLast() == 20);
    assert(ll.sizeLL() == 2);
    assert(ll.toString() == "10 -> 20");

    ll.addLast(30);
    assert(ll.getLast() == 30);
    assert(ll.sizeLL() == 3);
    assert(ll.toString() == "10 -> 20 -> 30");

    ll.removeLast();
    ll.removeLast();
    ll.removeLast();
    assert(ll.isEmpty() == true);

    ll.addLast(15);
    assert(ll.getFirst() == 15);
    assert(ll.getLast() == 15);
}

void testAdd() {
    LinkedList ll;
    try {
        ll.add(20, 12);
    } catch (const std::out_of_range& e) {
        assert(std::string(e.what()) == "Índice inválido");
    }

    ll.add(30, 0);
    ll.add(40, 1);
    assert(ll.toString() == "30 -> 40");

    ll.add(50, 2);
    assert(ll.toString() == "30 -> 40 -> 50");
    ll.add(60, 3);
    assert(ll.toString() == "30 -> 40 -> 50 -> 60");
    ll.add(70, 2);
    assert(ll.toString() == "30 -> 40 -> 70 -> 50 -> 60");
}

void testContains() {
    LinkedList ll;
    try {
        ll.contains(5);
    } catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Lista vazia");
    }

    ll.addLast(10);
    ll.addLast(20);
    ll.addLast(30);
    assert(ll.contains(10) == true);
    assert(ll.contains(20) == true);
    assert(ll.contains(30) == true);
    assert(ll.contains(50) == false);
}

void testGet() {
    LinkedList ll;
    ll.addLast(10);
    assert(ll.get(0) == 10);

    ll.addLast(20);
    assert(ll.get(1) == 20);

    ll.addLast(30);
    ll.addLast(40);
    ll.addLast(50);

    assert(ll.get(4) == 50);
    assert(ll.get(3) == 40);
    assert(ll.get(2) == 30);

    try {
        ll.get(20);
    } catch (const std::out_of_range& e) {
        assert(std::string(e.what()) == "índice inválido");
    }
}

void testUpdateNode() {
    LinkedList ll;
    try {
        ll.updateNode(5, 0);
    } catch (const std::out_of_range& e) {
        assert(std::string(e.what()) == "índice inválido");
    }

    ll.addFirst(10);
    assert(ll.get(0) == 10);

    ll.updateNode(15, 0);
    assert(ll.get(0) == 15);
}

void testRemoveLast() {
    LinkedList ll;
    ll.addFirst(10);
    assert(ll.getLast() == 10);

    ll.removeLast();
    assert(ll.isEmpty() == true);

    ll.addLast(30);
    ll.addLast(45);
    assert(ll.getLast() == 45);
    ll.removeLast();
    assert(ll.getLast() == 30);
}

void testRemoveByIndex() {
    LinkedList ll;
    try {
        ll.removeByIndex(0);
    } catch (const std::out_of_range& e) {
        assert(std::string(e.what()) == "Índice inválido");
    }

    ll.addLast(10);
    ll.addLast(20);
    ll.addLast(30);
    ll.addLast(40);
    ll.addLast(50);
    assert(ll.toString() == "10 -> 20 -> 30 -> 40 -> 50");

    ll.removeByIndex(1);
    assert(ll.toString() == "10 -> 30 -> 40 -> 50");

    ll.removeByIndex(0);
    assert(ll.toString() == "30 -> 40 -> 50");

    ll.removeByIndex(2);
    assert(ll.toString() == "30 -> 40");
}

void testRemoveByValue() {
    LinkedList ll;
    ll.addLast(10);
    ll.addLast(20);
    ll.addLast(10);
    ll.addLast(30);
    ll.removeByValue(10);
    assert(ll.toString() == "20 -> 10 -> 30");

    ll.addLast(10);
    assert(ll.toString() == "20 -> 10 -> 30 -> 10");
    ll.removeByValue(10);
    assert(ll.toString() == "20 -> 30 -> 10");
}

void testRemoveFirst() {
    LinkedList ll;
    ll.addFirst(10);
    ll.addFirst(20);
    ll.addFirst(30);
    assert(ll.toString() == "30 -> 20 -> 10");

    ll.removeFirst();
    assert(ll.toString() == "20 -> 10");

    ll.removeFirst();
    assert(ll.toString() == "10");

    ll.removeFirst();
    assert(ll.toString() == "");
}

void testSizeLL() {
    LinkedList ll;
    assert(ll.sizeLL() == 0);

    ll.addLast(10);
    assert(ll.sizeLL() == 1);

    ll.removeFirst();
    assert(ll.sizeLL() == 0);

    ll.addLast(10);
    ll.addLast(20);
    ll.addLast(30);
    assert(ll.sizeLL() == 3);
}

void testToString() {
    LinkedList ll;
    assert(ll.toString() == "");

    ll.addFirst(10);
    assert(ll.toString() == "10");

    ll.addLast(20);
    assert(ll.toString() == "10 -> 20");

    ll.addFirst(5);
    assert(ll.toString() == "5 -> 10 -> 20");

    ll.add(15, 1);
    assert(ll.toString() == "5 -> 15 -> 10 -> 20");

    ll.updateNode(5, 1);
    assert(ll.toString() == "5 -> 5 -> 10 -> 20");
}

void testIndexOf() {
    LinkedList ll;
    try {
        ll.indexOf(10);
    } catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Lista vazia");
    }

    ll.addLast(10);
    assert(ll.indexOf(10) == 0);

    ll.addLast(20);
    ll.addLast(10);
    assert(ll.indexOf(10) == 0);

    ll.removeFirst();
    assert(ll.indexOf(10) == 1);
}

void testLastIndexOf() {
    LinkedList ll;
    try {
        ll.lastIndexOf(10);
    } catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Lista vazia");
    }

    ll.addLast(10);
    assert(ll.lastIndexOf(10) == 0);

    ll.addLast(10);
    ll.addLast(10);
    ll.addLast(10);
    assert(ll.lastIndexOf(10) == 3);
}

int main() {
    testIsEmpty();
    testAddFirst();
    testAddLast();
    testAdd();
    testContains();
    testGet();
    testUpdateNode();
    testRemoveLast();
    testRemoveByIndex();
    testRemoveByValue();
    testRemoveFirst();
    testSizeLL();
    testToString();
    testIndexOf();
    testLastIndexOf();
    
    std::cout << "Todos os testes passaram com sucesso!" << std::endl;

    return 0;
}