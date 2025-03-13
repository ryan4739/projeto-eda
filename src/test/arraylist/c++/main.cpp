#include "ArrayList.h"
#include <cassert>
#include <iostream>

void testArrayList() {
    // Teste 1: Construtor padrão
    ArrayList lista1;
    assert(lista1.isEmpty() == true); // A lista deve estar vazia após a criação

    // Teste 2: Adicionar elementos no final
    lista1.addLast(10);
    lista1.addLast(20);
    lista1.addLast(30);
    assert(lista1.contains(10) == true); // Deve conter o valor 10
    assert(lista1.contains(20) == true); // Deve conter o valor 20
    assert(lista1.contains(30) == true); // Deve conter o valor 30

    // Teste 3: Adicionar elementos no início
    lista1.addFirst(5);
    assert(lista1.contains(5) == true); // Deve conter o valor 5

    // Teste 4: Adicionar elementos em um índice específico
    lista1.addIndex(15, 2); // Adiciona 15 no índice 2
    assert(lista1.contains(15) == true); // Deve conter o valor 15

    // Teste 5: Remover o último elemento
    lista1.rmvLast();
    assert(lista1.contains(30) == false); // O valor 30 não deve mais estar na lista

    // Teste 6: Remover o primeiro elemento
    lista1.rmvFirst();
    assert(lista1.contains(5) == false); // O valor 5 não deve mais estar na lista

    // Teste 7: Remover um elemento em um índice específico
    lista1.rmvIndex(1); // Remove o elemento no índice 1 (valor 15)
    assert(lista1.contains(15) == false); // O valor 15 não deve mais estar na lista
    assert(lista1.getSize() == 1);
    /*
    // Teste 8: Verificar se a lista está vazia após remoções
    lista1.rmvLast();
    lista1.rmvLast();
    assert(lista1.isEmpty() == true); // A lista deve estar vazia novamente

    // Teste 9: Construtor com capacidade inicial
    ArrayList lista2(5); // Cria uma lista com capacidade inicial 5
    assert(lista2.isEmpty() == true); // A lista deve estar vazia após a criação

    // Teste 10: Adicionar elementos até estourar a capacidade inicial
    for (int i = 0; i < 10; i++) {
        lista2.addLast(i);
    }
    assert(lista2.contains(9) == true); // Deve conter o valor 9 após o resize
    */
}

int main() {
    testArrayList();
    return 0;
}
