#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

class Deque {
private:
    int* deque;
    int capacity;
    int size;
    int head;
    int tail;

    void resize() {
        int newCapacity = capacity * 2;
        int* newDeque = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newDeque[i] = deque[(head + i) % capacity];
        }
        delete[] deque;
        deque = newDeque;
        head = 0;
        tail = size - 1;
        capacity = newCapacity;
    }

public:
    Deque() {
        capacity = 20;
        deque = new int[capacity];
        size = 0;
        head = -1;
        tail = -1;
    }

    Deque(int capacidade) {
        capacity = capacidade;
        deque = new int[capacity];
        size = 0;
        head = -1;
        tail = -1;
    }

    ~Deque() {
        delete[] deque;
    }

    void addFirst(int entrada) {
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

    void addLast(int entrada) {
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
    void add(int valor, int index) {
        if (index < 0 || index > size) {
            throw out_of_range("Índice fora do intervalo");
        }
        if (isFull()) {
            resize();
        }
    
        int insertPos = (head + index) % capacity;
    
        if (index < size / 2) {
            // Move elementos para a esquerda
            head = (head - 1 + capacity) % capacity;
            for (int i = 0; i < index; i++) {
                int from = (head + i + 1) % capacity;
                int to = (head + i) % capacity;
                deque[to] = deque[from];
            }
            deque[insertPos] = valor;
        } else {
            // Move elementos para a direita
            for (int i = size; i > index; i--) {
                int from = (head + i - 1) % capacity;
                int to = (head + i) % capacity;
                deque[to] = deque[from];
            }
            deque[insertPos] = valor;
            tail = (tail + 1) % capacity;
        }
    
        size++;
    }

    int removeFirst() {
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

    int removeLast() {
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

    int remove(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Índice fora do intervalo");
        }
    
        int removePos = (head + index) % capacity;
        int value = deque[removePos];
    
        if (index < size / 2) {
            // Move elementos para a direita
            for (int i = index; i > 0; i--) {
                int from = (head + i - 1) % capacity;
                int to = (head + i) % capacity;
                deque[to] = deque[from];
            }
            head = (head + 1) % capacity;
        } else {
            // Move elementos para a esquerda
            for (int i = index; i < size - 1; i++) {
                int from = (head + i + 1) % capacity;
                int to = (head + i) % capacity;
                deque[to] = deque[from];
            }
            tail = (tail - 1 + capacity) % capacity;
        }
    
        size--;
        if (size == 0) {
            head = -1;
            tail = -1;
        }
    
        return value;
    }    

    int getFirst() {
        if (isEmpty()) {
            throw out_of_range("Deque está vazio");
        }
        return deque[head];
    }

    int getLast() {
        if (isEmpty()) {
            throw out_of_range("Deque está vazio");
        }
        return deque[tail];
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Índice fora do intervalo");
        }
        return deque[(head + index) % capacity];
    }    

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    bool contains(int valor) {
        for (int i = 0; i < size; i++) {
            if (deque[(head + i) % capacity] == valor) {
                return true;
            }
        }
        return false;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    string toString() {
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
};
