#include <iostream>
#include <stdexcept>
#include <string> 

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
    Node* head;
    Node* tail;
    int size;

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

    bool isEmpty() {
        return size == 0;
    }

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

    int getFirst() {
        return head->data;
    }

    int getLast() {
        return tail->data;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("índice inválido");
        }

        Node* node = getNodeByIndex(index);
        return node->data;
    }

    void updateNode(int index, int value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("índice inválido");
        }

        Node* node = getNodeByIndex(index);
        node->data = value;
    }
    
    void removeFirst() {
        if (isEmpty()) {
            throw std::out_of_range("Lista vazia");
        }

        if (size == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            Node* currNode = head;
            head = head->next;
            delete currNode;
        }
        size--;
    }

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
            prevNode->next = nullptr;
            tail = prevNode;
        }
        size--;
    }

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

    void removeByValue(int value) {
        int index = indexOf(value);
        if (index != -1) {
            removeByIndex(index);
        }
    }

    int indexOf(int value) {
        if (isEmpty()) {
            throw std::exception("Lista vazia");
        }

        Node* node = head;
        for (int i = 0; i < size; i++) {
            if (node->data == value) {
                return i;
            }
        }
        return -1;
    }

    int lastIndexOf(int value) {
        if (isEmpty()) {
            throw std::exception("Lista vazia");
        }

        int index = -1;

        Node* node = head;
        for (int i = 0; i < size; i++) {
            if (node->data == value) {
                index = i;
            }
        }
        return index;
    }

    int sizeLL() {
        return size;
    }

    bool contains(int value) {
        return indexOf(value) != -1;
    }

    string toString() {
        string llString = "";

        Node* node = head;
        while (node != nullptr) {
            llString += to_string(node->data);
            if (node->next != nullptr) {
                llString += " -> ";
            }
            node = node->next;
        }
        return llString;
    } 
};