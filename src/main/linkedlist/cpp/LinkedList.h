#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

/**
 * Representação de um nó na lista
 */
struct Node;

/**
 * Representação de uma lista encadeada
 */
class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

    Node* getNodeByIndex(int index);

public:
    LinkedList();

    bool isEmpty();
    void addFirst(int value);
    void addLast(int value);
    void add(int value, int index);
    int getFirst();
    int getLast();
    int get(int index);
    void updateNode(int value, int index);
    void removeFirst();
    void removeLast();
    void removeByIndex(int index);
    void removeByValue(int value);
    int indexOf(int value);
    int lastIndexOf(int value);
    int sizeLL();
    bool contains(int value);
    std::string toString();
};

#endif 