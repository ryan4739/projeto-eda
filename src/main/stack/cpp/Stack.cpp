#include <iostream>
#include <stdexcept>
#include <string>

class Stack {
private:
    int top;        // Índice do topo da pilha
    int capacity;   // Capacidade da pilha
    int* array;     // Array para armazenar os elementos

public:
    // Construtor que inicializa a pilha com um tamanho definido
    Stack(int capacidade) {
        if (capacidade <= 0) {
            throw std::runtime_error("Capacidade inválida"); // Evita criação de pilha com capacidade inválida
        }
        array = new int[capacidade]; // Aloca dinamicamente a pilha
        this->capacity = capacidade;
        this->top = -1; // Indica que a pilha está vazia
    }

    // Verifica se a pilha está cheia
    bool isFull() const {
        return top + 1 >= capacity;
    }

    // Verifica se a pilha está vazia
    bool isEmpty() const {
        return top < 0;
    }

    // Adiciona um elemento ao topo da pilha
    void push(int valor) {
        if (isFull()) {
            throw std::runtime_error("A pilha está cheia");
        }
        array[++top] = valor; // Incrementa top e insere o valor
    }

    // Remove e retorna o elemento do topo da pilha
    int pop() {
        if (isEmpty()) {
            throw std::runtime_error("A pilha está vazia");
        }
        return array[top--]; // Retorna o valor e decrementa top
    }

    // Retorna o elemento do topo sem removê-lo
    int peek() const {
        if (isEmpty()) {
            throw std::runtime_error("A pilha está vazia");
        }
        return array[top];
    }

    // Retorna o primeiro elemento da pilha sem removê-lo
    int peekFirst() const {
        if (isEmpty()) {
            throw std::runtime_error("A pilha está vazia");
        }
        return array[0];
    }

    // Retorna o índice da primeira ocorrência de um valor na pilha
    int indexOf(int valor) const {
        for (int i = 0; i <= top; i++) {
            if (array[i] == valor) {
                return i; // Retorna o índice onde o valor foi encontrado
            }
        }
        return -1; // Retorna -1 se o valor não for encontrado
    }

    // Insere um elemento em um índice específico da pilha
    void PushIndex(int valor, int index) {
        if (isFull()) {
            throw std::runtime_error("A pilha está cheia");
        }
        if (index < 0 || index > top + 1) {
            throw std::runtime_error("Índice inválido");
        }
        // Desloca os elementos para a direita para abrir espaço
        for (int i = top + 1; i > index; i--) {
            array[i] = array[i - 1];
        }
        array[index] = valor; // Insere o novo valor
        top++; // Atualiza o topo
    }

    // Remove o elemento de um índice específico
    void popIndex(int index) {
        if (isEmpty()) {
            throw std::runtime_error("A pilha está vazia");
        }
        if (index < 0 || index > top) {
            throw std::runtime_error("Índice inválido");
        }
        // Desloca os elementos para a esquerda para remover o elemento
        for (int i = index; i < top; i++) {
            array[i] = array[i + 1];
        }
        top--; // Atualiza o topo
    }

    // Exibe os elementos da pilha
    void printStack() const {
        if (isEmpty()) {
            std::cout << "Pilha vazia" << std::endl;
            return;
        }
        for (int i = 0; i <= top; i++) {
            std::cout << array[i] << (i < top ? ", " : "\n"); // Formata a saída
        }
    }

    // Insere um elemento na base da pilha (última posição)
    void pushLast(int valor) {
        PushIndex(valor, 0); // Insere na posição 0
    }

    // Remove e retorna o primeiro elemento da pilha
    int popLast() {
        if (isEmpty()) {
            throw std::runtime_error("Pilha vazia");
        }
        int firstValue = array[0];
        popIndex(0); // Remove o primeiro elemento
        return firstValue;
    }
};
