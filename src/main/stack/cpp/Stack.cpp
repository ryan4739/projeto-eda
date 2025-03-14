#include <iostream>
#include <stdexcept>
#include <string>

class Stack {
private:
    int top;        // Índice do topo da pilha
    int capacity;   // Capacidade da pilha
    int* array;     // Array para armazenar os elementos

public:
    Stack(int capacidade) {
        if (capacidade <= 0) {
            throw std::runtime_error("Capacidade inválida");
        }
        array = new int[capacidade];
        this->capacity = capacidade;
        this->top = -1;
    }

    bool isFull() const {
        return top + 1 >= capacity;
    }

    bool isEmpty() const {
        return top < 0;
    }

    void push(int valor) {
        if (isFull()) {
            throw std::runtime_error("A pilha está cheia");
        }
        array[++top] = valor;
    }

    int pop() {
        if (isEmpty()) {
            throw std::runtime_error("A pilha está vazia");
        }
        return array[top--];
    }

    int peek() const {
        if (isEmpty()) {
            throw std::runtime_error("A pilha está vazia");
        }
        return array[top];
    }

    int peekFirst() const {
        if (isEmpty()) {
            throw std::runtime_error("A pilha está vazia");
        }
        return array[0];
    }

    int indexOf(int valor) const {
        for (int i = 0; i <= top; i++) {
            if (array[i] == valor) {
                return i;
            }
        }
        return -1;
    }

    void PushIndex(int valor, int index) {
        if (isFull()) {
            throw std::runtime_error("A pilha está cheia");
        }
        if (index < 0 || index > top + 1) {
            throw std::runtime_error("Índice inválido");
        }
        for (int i = top + 1; i > index; i--) {
            array[i] = array[i - 1];
        }
        array[index] = valor;
        top++;
    }

    void popIndex(int index) {
        if (isEmpty()) {
            throw std::runtime_error("A pilha está vazia");
        }
        if (index < 0 || index > top) {
            throw std::runtime_error("Índice inválido");
        }
        for (int i = index; i < top; i++) {
            array[i] = array[i + 1];
        }
        top--;
    }

    void printStack() const {
        if (isEmpty()) {
            std::cout << "Pilha vazia" << std::endl;
            return;
        }
        for (int i = 0; i <= top; i++) {
            std::cout << array[i] << (i < top ? ", " : "\n");
        }
    }
    void pushLast(int valor) {
        PushIndex(valor, 0);
    }
    int popLast() {
        if (isEmpty()) {
            throw std::runtime_error("Pilha vazia");
        }
        int firstValue = array[0];
        popIndex(0);
        return firstValue;
    }
};
