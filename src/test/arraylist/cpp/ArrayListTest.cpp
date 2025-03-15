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
    std::cout << "Eliminando o resto dos elementos para testar com ela vazia...\n";
    list.rmvLast();
    list.rmvLast();
    std::cout << "A lista está vazia? " << (list.isEmpty() ? "Sim" : "Não") << " (esperado: Sim)\n";

    // Testando isFull
    std::cout << "\nTestando isFull...\n";
    std::cout << "A lista está cheia? " << (list.isFull() ? "Sim" : "Não") << " (esperado: Não)\n";
    std::cout << "Adicionando até estar cheia...\n";
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addLast(4);
    list.addLast(5);
    list.addLast(6);
    list.addLast(7);
    list.addLast(8);
    list.addLast(9);
    list.addLast(10);
    list.addLast(11);
    list.addLast(12);
    list.addLast(13);
    list.addLast(14);
    list.addLast(15);
    list.addLast(16);
    list.addLast(17);
    list.addLast(18);
    list.addLast(19);
    list.addLast(20);
    std::cout << "Tamanho? " << list.getSize() << " (esperado: 19)\n";
    std::cout << "A lista está cheia? " << (list.isFull() ? "Sim" : "Não") << " (esperado: Sim)\n";


    // Testando reSize
    std::cout << "Testando reSize...\n";
    list.addLast(21);
    std::cout << "Tamanho? " << list.getSize() << " (esperado: 20)\n";
    std::cout << "A lista está cheia? " << (list.isFull() ? "Sim" : "Não") << " (esoerado: Não)\n";

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
