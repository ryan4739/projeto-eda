#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

/**
 * @class Deque
 * @brief Implementação de um deque (fila dupla) circular dinâmica.
 */
class Deque {
private:
    int *deque;   ///< Array dinâmico que armazena os elementos do deque.
    int capacity; ///< Capacidade máxima do deque.
    int size;     ///< Número de elementos armazenados.
    int head;     ///< Índice do primeiro elemento.
    int tail;     ///< Índice do último elemento.

    /**
     * @brief Expande a capacidade do deque quando cheio.
     */
    void resize();

public:
    /**
     * @brief Construtor padrão que inicializa o deque com capacidade 20.
     */
    Deque();

    /**
     * @brief Construtor que inicializa o deque com capacidade especificada.
     * @param capacidade Capacidade inicial do deque.
     */
    Deque(int capacidade);

    /**
     * @brief Destrutor que libera a memória alocada.
     */
    ~Deque();

    /**
     * @brief Insere um elemento no início do deque.
     * @param entrada Valor a ser inserido.
     */
    void appendLeft(int entrada);

    /**
     * @brief Insere um elemento no final do deque.
     * @param entrada Valor a ser inserido.
     */
    void appendRight(int entrada);

    /**
     * @brief Remove e retorna o elemento do início do deque.
     * @return Valor removido.
     * @throws std::out_of_range Se o deque estiver vazio.
     */
    int popLeft();

    /**
     * @brief Remove e retorna o elemento do final do deque.
     * @return Valor removido.
     * @throws std::out_of_range Se o deque estiver vazio.
     */
    int popRight();

    /**
     * @brief Retorna o elemento do início do deque sem removê-lo.
     * @return Valor do primeiro elemento.
     * @throws std::out_of_range Se o deque estiver vazio.
     */
    int peekLeft();

    /**
     * @brief Retorna o elemento do final do deque sem removê-lo.
     * @return Valor do último elemento.
     * @throws std::out_of_range Se o deque estiver vazio.
     */
    int peekRight();

    /**
     * @brief Retorna o tamanho atual do deque.
     * @return Número de elementos no deque.
     */
    int getSize();

    /**
     * @brief Retorna a capacidade atual do deque.
     * @return Capacidade total do deque.
     */
    int getCapacity();

    /**
     * @brief Verifica se o deque contém um determinado valor.
     * @param valor Valor a ser procurado.
     * @return true se o valor estiver presente, false caso contrário.
     */
    bool contains(int valor);

    /**
     * @brief Verifica se o deque está cheio.
     * @return true se estiver cheio, false caso contrário.
     */
    bool isFull();

    /**
     * @brief Verifica se o deque está vazio.
     * @return true se estiver vazio, false caso contrário.
     */
    bool isEmpty();

    /**
     * @brief Retorna uma string com os elementos do deque.
     * @return Representação do deque como string.
     */
    string toString();
};

#endif // DEQUE_H
