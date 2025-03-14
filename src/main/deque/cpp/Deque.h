#ifndef DEQUE_H
#define DEQUE_H

#include <stdexcept>
#include <iostream>
#include <sstream>
using namespace std;

class Deque {
  private:
    int *deque;
    int capacity;
    int size;
    int head;
    int tail;

  public:
    Deque(int capacidade);
    ~Deque();
    void appendLeft(int entrada);
    void appendRight(int entrada);
    int popLeft();
    int popRight();
    int peekLeft();
    int peekRight();
    int getSize();
    int getCapacity();
    bool contains(int valor);
    bool isFull();
    bool isEmpty();
    void resize();
    string toString();
};

#endif // DEQUE_H
