#include "Deque.h"

Deque::Deque() {
    capacity = 20;
    deque = new int[capacity];
    size = 0;
    head = -1;
    tail = -1;
}

Deque::Deque(int capacidade) {
    capacity = capacidade;
    deque = new int[capacidade];
    size = 0;
    head = -1;
    tail = -1;
}

Deque::~Deque() {
    delete[] deque;
}

void Deque::appendLeft(int entrada) {
    if (isFull()) {
        resize();
    }
    if (isEmpty()) {
        head = tail = 0;
    } else {
        head = (head - 1 + capacity) % capacity;
    }
    deque[head] = entrada;
    size++;
}

void Deque::appendRight(int entrada) {
    if (isFull()) {
        resize();
    }
    if (isEmpty()) {
        head = tail = 0;
    } else {
        tail = (tail + 1) % capacity;
    }
    deque[tail] = entrada;
    size++;
}

int Deque::popLeft() {
    if (isEmpty()) {
        throw out_of_range("Deque está vazio");
    }
    int val = deque[head];
    if (size == 1) {
        head = tail = -1;
    } else {
        head = (head + 1) % capacity;
    }
    size--;
    return val;
}

int Deque::popRight() {
    if (isEmpty()) {
        throw out_of_range("Deque está vazio");
    }
    int val = deque[tail];
    if (size == 1) {
        head = tail = -1;
    } else {
        tail = (tail - 1 + capacity) % capacity;
    }
    size--;
    return val;
}

int Deque::peekLeft() {
    if (isEmpty()) {
        throw out_of_range("Deque está vazio");
    }
    return deque[head];
}

int Deque::peekRight() {
    if (isEmpty()) {
        throw out_of_range("Deque está vazio");
    }
    return deque[tail];
}

int Deque::getSize() {
    return size;
}

int Deque::getCapacity() {
    return capacity;
}

bool Deque::contains(int valor) {
    for (int i = 0; i < size; i++) {
        if (deque[(head + i) % capacity] == valor) {
            return true;
        }
    }
    return false;
}

bool Deque::isFull() {
    return size == capacity;
}

bool Deque::isEmpty() {
    return size == 0;
}

void Deque::resize() {
    int newCapacity = capacity * 2;
    int *newDeque = new int[newCapacity];
    for (int i = 0; i < size; i++) {
        newDeque[i] = deque[(head + i) % capacity];
    }
    delete[] deque;
    deque = newDeque;
    head = 0;
    tail = size - 1;
    capacity = newCapacity;
}

string Deque::toString() {
    if (isEmpty()) {
        return "Deque vazio";
    }
    stringstream ss;
    ss << "Deque: [";
    for (int i = 0; i < size; i++) {
        ss << deque[(head + i) % capacity];
        if (i < size - 1) {
            ss << ", ";
        }
    }
    ss << "]";
    return ss.str();
}
