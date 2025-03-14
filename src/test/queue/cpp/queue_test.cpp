#include <iostream>
#include <cassert>
#include "../../../main/queue/cpp/queue.cpp"

// Função para testar a criação da fila e métodos básicos
void testQueueCreation() {
    Queue<int> q(10);
    assert(q.isEmpty());
    assert(q.getSize() == 0);
    std::cout << "Testes de criação da fila passaram!\n";
}

// Função para testar adição de elementos no final da fila
void testAddLast() {
    Queue<int> q(10);
    q.addLast(10);
    q.addLast(20);
    q.addLast(30);
    assert(q.getSize() == 3);
    assert(q.getFirst() == 10);
    assert(q.getLast() == 30);
    std::cout << "Testes de addLast passaram!\n";
}

// Função para testar adição de elementos no início da fila
void testAddFirst() {
    Queue<int> q(10);
    q.addLast(10);
    q.addLast(20);
    q.addFirst(5);
    assert(q.getSize() == 3);
    assert(q.getFirst() == 5);
    assert(q.getLast() == 20);
    std::cout << "Testes de addFirst passaram!\n";
}

// Função para testar adição de elementos em posições específicas
void testAddAtPosition() {
    Queue<int> q(10);
    q.addLast(10);
    q.addLast(20);
    q.addLast(30);
    q.add(40, 2);
    assert(q.getSize() == 4);
    assert(q.getFirst() == 10);
    assert(q.getLast() == 30);
    q.add(70, 0);
    assert(q.getSize() == 5);
    assert(q.getFirst() == 70);
    assert(q.getLast() == 30);
    q.add(90, 5);
    assert(q.getSize() == 6);
    assert(q.getFirst() == 70);
    assert(q.getLast() == 90);
    std::cout << "Testes de add em posições específicas passaram!\n";
}

// Função para testar remoção de elementos no início da fila
void testRemoveFirst() {
    Queue<int> q(10);
    q.addLast(10);
    q.addLast(20);
    q.addLast(30);
    assert(q.removeFirst() == 10);
    assert(q.getSize() == 2);
    assert(q.getFirst() == 20);
    std::cout << "Testes de removeFirst passaram!\n";
}

// Função para testar remoção de elementos no final da fila
void testRemoveLast() {
    Queue<int> q(10);
    q.addLast(10);
    q.addLast(20);
    q.addLast(30);
    assert(q.removeLast() == 30);
    assert(q.getSize() == 2);
    assert(q.getLast() == 20);
    std::cout << "Testes de removeLast passaram!\n";
}

// Função para testar remoção de elementos em posições específicas
void testRemoveAtPosition() {
    Queue<int> q(10);
    q.addLast(10);
    q.addLast(20);
    q.addLast(30);
    assert(q.remove(1) == 20);
    assert(q.getSize() == 2);
    assert(q.getFirst() == 10);
    assert(q.getLast() == 30);
    std::cout << "Testes de remove em posições específicas passaram!\n";
}

// Função para testar métodos de consulta (getFirst, getLast, get, indexOf, lastIndexOf)
void testQueryMethods() {
    Queue<int> q(10);
    q.addLast(10);
    q.addLast(20);
    q.addLast(30);
    assert(q.getFirst() == 10);
    assert(q.getLast() == 30);
    assert(q.get(1) == 20);
    assert(q.indexOf(20) == 1);
    assert(q.indexOf(40) == -1);
    q.addLast(20);
    assert(q.lastIndexOf(20) == 3);
    std::cout << "Testes de métodos de consulta passaram!\n";
}

// Função para testar métodos de estado (size, isEmpty, isFull)
void testStateMethods() {
    Queue<int> q(3);
    assert(q.isEmpty());
    q.addLast(10);
    q.addLast(20);
    q.addLast(30);
    assert(q.isFull());
    assert(q.getSize() == 3);
    std::cout << "Testes de métodos de estado passaram!\n";
}

// Função principal que executa todos os testes
void testQueue() {
    testQueueCreation();
    testAddLast();
    testAddFirst();
    testAddAtPosition();
    testRemoveFirst();
    testRemoveLast();
    testRemoveAtPosition();
    testQueryMethods();
    testStateMethods();
    std::cout << "Todos os testes passaram!\n";
}

int main() {
    testQueue();
    return 0;
}
