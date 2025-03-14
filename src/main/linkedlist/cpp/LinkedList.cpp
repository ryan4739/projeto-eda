#include <iostream>
#include <stdexcept>
#include <string> 
#include <sstream>
#include "LinkedList.h"

using namespace std;

/**
     * Representação de um Nó da lista
     */
struct Node {
    int data; /**< O valor sendo armazenado na lista */
    Node* next; /**< O próximo elemento da lista */

    Node(int value) : data(value), next(nullptr) {}
};

/**
     * Representação de uma lista encadeada
     */
class LinkedList {
    Node* head; /**< Ponteiro para o primeiro nó da lista */
    Node* tail; /**< Ponteiro para o último nó da lista */
    int size; /**< O tamanho da lista*/

    /**
     * Pega o node em um índice informado
     * 
     * @param index o índice do node
     * @return o node
     */
    Node* getNodeByIndex(int index) {
        if (index < 0 || index >= this->size) {
            throw std::out_of_range("Índice inválido");
        }

        Node* node = head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return node;
    }

public:

    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    /**
     * Verifica se a lista está vazia
     * 
     * @return true caso esteja vazia, false caso não
     */
    bool isEmpty() {
        return size == 0;
    }
    
    /**
     * Adiciona um elemento na primeira posição da lista
     * 
     * @param value o valor a ser adicionado
     */
    void addFirst(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    
    /**
     * Adiciona um elemento na última posição da lista
     * 
     * @param value o valor a ser adicionado
     */
    void addLast(int value) {
        Node* newNode = new Node(value);
        
        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    /**
     * Adiciona um elemento em um índice específico da lista
     * 
     * @param value o valor a ser adicionado
     * @param index a posição na qual ele será adicionado
     */
    void add(int value, int index) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Índice inválido");
        }
        
        if (index == 0 || isEmpty()) {
            addFirst(value);
        } else if (index == size) {
            addLast(value);
        } else {
            Node* newNode = new Node(value);
            Node* prevNode = getNodeByIndex(index-1);
            Node* aftNode = prevNode->next;

            prevNode->next = newNode;
            newNode->next = aftNode;

            size++;
        }
    }

    /**
     * Informa o valor do primeiro elemento da lista
     * 
     * @return o valor do primeiro elemento da lista
     */
    int getFirst() {
        return head->data;
    }

    /**
     * Informa o valor do último elemento da lista
     * 
     * @return o último elemento da lista
     */
    int getLast() {
        return tail->data;
    }

    /**
     * Pega o valor do node a partir de seu índice
     * 
     * @param index o índice do node
     * @return o valor contido no node
     */
    int get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("índice inválido");
        }

        Node* node = getNodeByIndex(index);
        return node->data;
    }

    /**
     * Altera o valor de um nó na lista
     * 
     * @param value o valor a ser alterado
     * @param index o índice do valor a ser alterado
     */
    void updateNode(int value, int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("índice inválido");
        }

        Node* node = getNodeByIndex(index);
        node->data = value;
    }
    
    /**
     * Remove o primeiro elemento da lista
     */
    void removeFirst() {
        if (isEmpty()) {
            throw std::out_of_range("Lista vazia");
        }

        Node* currNode = head;
        if (size == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
        }
        delete currNode;
        size--;
    }

    /**
     * Remove o último elemento da lista
     */
    void removeLast() {
        if (isEmpty()) {
            throw std::out_of_range("Lista vazia");
        }

        if (size == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node* prevNode = getNodeByIndex(size-2);
            delete prevNode->next;
            tail = prevNode;
            tail->next = nullptr;
        }
        size--;
    }

    /**
     * Remove um elemento da lista a partir de seu índice
     * 
     * @param index o índice do elemento a ser removido
     */
    void removeByIndex(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Índice inválido");
        }

        if (index == 0) {
            return removeFirst();
        } else if (index == size-1) {
            return removeLast();
        }

        Node* prevNode = getNodeByIndex(index-1);
        Node* toBeRemoved = prevNode->next;

        prevNode->next = prevNode->next->next;
        delete toBeRemoved;

        size--;
    }

    /**
     * Remove o primeiro elemento da lista que tiver o valor informado
     * 
     * @param value o valor a ser removido
     */
    void removeByValue(int value) {
        int index = indexOf(value);
        if (index != -1) {
            removeByIndex(index);
        }
    }

    /**
     * Informa o índice da primeira ocorrência de um valor. Se não estiver presente na lista, retornará -1
     * 
     * @param value o valor a ser encontrado
     * @return o índice da primeira ocorrência do valor, caso esteja na lista, -1 caso não
     */
    int indexOf(int value) {
        if (isEmpty()) {
            throw std::runtime_error("Lista vazia");
        }

        Node* node = head;
        for (int i = 0; i < size; i++) {
            if (node->data == value) {
                return i;
            }
            node = node->next;
        }
        return -1;
    }

    /**
     * Informa o índice da última ocorrência de um valor. Se não estiver presente na lista, retornará -1
     * 
     * @param value o valor buscado
     * @return o índice da última ocorrência do valor, caso esteja na lista, -1 caso não
     */
    int lastIndexOf(int value) {
        if (isEmpty()) {
            throw std::runtime_error("Lista vazia");
        }

        int index = -1;

        Node* node = head;
        for (int i = 0; i < size; i++) {
            if (node->data == value) {
                index = i;
            }
            node = node->next;
        }
        return index;
    }

    /**
     * Informa o tamanho da lista
     * 
     * @return o tamanho da lista
     */
    int sizeLL() {
        return size;
    }

    /**
     * Verifica se um valor está contido ou não na lista
     * 
     * @param value o valor a ser buscado
     * @return true caso o valor esteja contido, false caso não
     */
    bool contains(int value) {
        return indexOf(value) != -1;
    }

    /**
     * Representação textual da lista no formato "a -> b -> c [...]"
     */
    string toString() {
        stringstream ss;
        Node* node = head;
        while (node != nullptr) {
            ss << node->data;
            if (node->next != nullptr) {
                ss << " -> ";
            }
            node = node->next;
        }
        return ss.str();
    } 
};