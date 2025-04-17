#include <iostream>
#include <stdexcept>
#include <string>

class Stack {
private:
    int tail = -1;
    int count = -1;
    int* array;

public:
    Stack(int capacidade) {
        if (capacidade <= 0) {
            throw std::runtime_error("Não deu");
        }
        array = new int[capacidade];
        this->count = capacidade;
    }

    bool isFull() {
        return tail + 1 >= count;
    }

    bool isEmpty() {
        return tail < 0;
    }

    void direita(int valor, int index) {
        if (isFull()) {
            throw std::runtime_error("Não deu");
        }
        if (index > tail + 1) {
            throw std::runtime_error("Não deu");
        }
        for (int i = tail + 1; i > index; i--) {
            array[i] = array[i - 1];
        }
        array[index] = valor;
        tail++;
    }

    void esquerda(int index) {
        if (isEmpty()) {
            throw std::runtime_error("Não deu");
        }
        for (int i = index; i < tail; i++) {
            array[i] = array[i + 1];
        }
        tail--;
    }

    int pop() {
        if (isEmpty()) {
            throw std::runtime_error("Não deu");
        }
        int V = array[tail];
        tail--;
        return V;
    }

    int indexOf(int valor) {
        if (isEmpty()) {
            throw std::runtime_error("Não deu");
        }
        for (int i = 0; i <= tail; i++) {
            if (array[i] == valor) {
                return i;
            }
        }
        return -1;
    }

   std::string toString() {
        std::string stringaro = "";
        for (int i = 0; i <= tail; i++) {
            stringaro += std::to_string(array[i]);
            if (i < tail) {
                stringaro += ", ";
            }
        }
        return stringaro;
    }

    int peekValorPrimeiro(int valor) {
        for (int i = 0; i <= tail; i++) {
            if (array[i] == valor) {
                return i;
            }
        }
        return -1;
    }

    int peekValorUltimo(int valor) {
        for (int i = tail; i >= 0; i--) {
            if (array[i] == valor) {
                return i;
            }
        }
        return -1;
    }

    int peekIndex(int index) {
        if (index > tail || index < 0 || isEmpty()) {
            throw std::runtime_error("Não deu");
        }
        return array[index];
    }

    int peekLast() {
        if (isEmpty()) {
            throw std::runtime_error("Não deu");
        }
        return array[0];
    }

    int peek() {
        if (isEmpty()) {
            throw std::runtime_error("Não deu");
        }
        return array[tail];
    }

    void push(int valor) {
        if (isFull()) {
            throw std::runtime_error("Não deu");
        }
        tail++;
        array[tail] = valor;
    }

    void pushLast(int valor) {
        direita(valor, 0);
    }

    void PushIndex(int valor, int index) {
        direita(valor, index);
    }

    void RemoveFirst() {
        esquerda(0);
    }

    void RemoveValor(int valor) {
        for (int i = 0; i <= tail; i++) {
            if (array[i] == valor) {
                esquerda(i);
                i--;  // re-check current index after shift
            }
        }
    }

    void RemoveIndex(int index) {
        esquerda(index);
    }

    int size() {
        return tail + 1;
    }

    void gettail() {
        std::cout << tail << " " << sizeof(array) << " " << sizeof(array[0]) << " " << count << std::endl;
    }

    ~Stack() {
        delete[] array;
    }
};
