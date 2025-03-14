#include <iostream>
#include "../../../main/arraylist/cpp/ArrayList.h"

void testArrayList() {
    // Testando o construtor padrão
    ArrayList list;
    std::cout << "Testando construtor padrão...\n";
    std::cout << "Tamanho da lista: " << list.getSize() << " (esperado: -1)\n";

    // Testando addLast
    std::cout << "\nTestando addLast...\n";
    list.addLast(10);
    list.addLast(20);
    list.addLast(30);
    std::cout << "Tamanho da lista após addLast: " << list.getSize() << " (esperado: 2)\n";

    // Testando contains
    std::cout << "\nTestando contains...\n";
    std::cout << "Contém 20? " << (list.contains(20) ? "Sim" : "Não") << " (esperado: Sim)\n";
    std::cout << "Contém 40? " << (list.contains(40) ? "Sim" : "Não") << " (esperado: Não)\n";

    // Testando addFirst
    std::cout << "\nTestando addFirst...\n";
    list.addFirst(5);
    std::cout << "Tamanho da lista após addFirst: " << list.getSize() << " (esperado: 3)\n";

    // Testando addIndex
    std::cout << "\nTestando addIndex...\n";
    list.addIndex(15, 2);
    std::cout << "Tamanho da lista após addIndex: " << list.getSize() << " (esperado: 4)\n";

    // Testando rmvLast
    std::cout << "\nTestando rmvLast...\n";
    list.rmvLast();
    std::cout << "Tamanho da lista após rmvLast: " << list.getSize() << " (esperado: 3)\n";

    // Testando rmvFirst
    std::cout << "\nTestando rmvFirst...\n";
    list.rmvFirst();
    std::cout << "Tamanho da lista após rmvFirst: " << list.getSize() << " (esperado: 2)\n";

    // Testando rmvIndex
    std::cout << "\nTestando rmvIndex...\n";
    list.rmvIndex(1);
    std::cout << "Tamanho da lista após rmvIndex: " << list.getSize() << " (esperado: 1)\n";

    // Testando isEmpty
    std::cout << "\nTestando isEmpty...\n";
    std::cout << "A lista está vazia? " << (list.isEmpty() ? "Sim" : "Não") << " (esperado: Não)\n";

    // Testando isFull (assumindo que a capacidade inicial é 20)
    std::cout << "\nTestando isFull...\n";
    std::cout << "A lista está cheia? " << (list.isFull() ? "Sim" : "Não") << " (esperado: Não)\n";

    // Testando o destrutor (não há muito o que testar aqui, mas podemos verificar se o programa não crasha)
    std::cout << "\nTestando destrutor...\n";
    {
        ArrayList tempList;
        tempList.addLast(100);
    }
    std::cout << "Destrutor chamado com sucesso.\n";
}

int main() {
    testArrayList();
    return 0;
}
