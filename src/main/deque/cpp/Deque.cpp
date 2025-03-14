using namespace std;

#include <stdexcept>
#include <iostream>
#include <sstream>

/**
 * Classe Deque - Implementação de um deque (fila dupla) circular dinâmico.
 */
class Deque {
  private:
    int *deque;     ///< Ponteiro para o array que armazena os elementos do deque.
    int capacity;   ///< Capacidade máxima do deque antes de redimensionamento.
    int size;       ///< Número atual de elementos no deque.
    int head;       ///< Índice do primeiro elemento no deque.
    int tail;       ///< Índice do último elemento no deque.

  public:
    /**
     * Construtor da classe Deque.
     * @param capacidade Capacidade inicial do deque.
     */
    Deque(int capacidade) {
        deque = new int[capacidade];
        capacity = capacidade;
        size = 0;
        head = -1;
        tail = -1;
    }

    /**
     * Destrutor da classe Deque.
     * Libera a memória alocada dinamicamente.
     */
    ~Deque() {
        delete[] deque;
    }

    /**
     * Insere um elemento no início do deque.
     * @param entrada Valor a ser inserido.
     */
    void appendLeft(int entrada) {
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
    
    /**
     * Insere um elemento no final do deque.
     * @param entrada Valor a ser inserido.
     */
    void appendRight(int entrada) {
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

    /**
     * Remove e retorna o elemento do início do deque.
     * @return Valor removido.
     * @throws std::out_of_range Se o deque estiver vazio.
     */
    int popLeft() {
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

    /**
     * Remove e retorna o elemento do final do deque.
     * @return Valor removido.
     * @throws std::out_of_range Se o deque estiver vazio.
     */
    int popRight() {
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

    /**
     * Retorna o elemento no início do deque sem removê-lo.
     * @return Valor do início do deque.
     * @throws std::out_of_range Se o deque estiver vazio.
     */
    int peekLeft() {
        if (isEmpty()) {
            throw out_of_range("Deque está vazio");
        }
        return deque[head];
    }
 
    /**
     * Retorna o elemento no final do deque sem removê-lo.
     * @return Valor do final do deque.
     * @throws std::out_of_range Se o deque estiver vazio.
     */
    int peekRight() {
        if (isEmpty()) {
            throw out_of_range("Deque está vazio");
        }
        return deque[tail];
    }

    /**
     * Retorna o número de elementos no deque.
     * @return Tamanho atual do deque.
     */
    int getSize() {
        return size;
    }

    /**
     * Retorna o número máximo de elementos no deque antes do resize.
     */
    int getCapacity() {
        return capacity;
    }

    /**
     * Verifica se um valor está presente no deque.
     * @param valor Valor a ser procurado.
     * @return true se o valor estiver presente, false caso contrário.
     */
    bool contains(int valor) {
        for (int i = 0; i < size; i++) {
            if (deque[(head + i) % capacity] == valor) {
                return true;
            }
        }
        return false;
    }

    /**
     * Verifica se o deque está cheio.
     * @return true se o deque estiver cheio, false caso contrário.
     */
    bool isFull() {
        return size == capacity;
    }

    /**
     * Verifica se o deque está vazio.
     * @return true se o deque estiver vazio, false caso contrário.
     */
    bool isEmpty() {
        return size == 0;
    }

    /**
     * Redimensiona o deque para o dobro da capacidade atual.
     */
    void resize() {
        int newCapacity = capacity * 2;
        int *newDeque = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newDeque[i] = deque[(head + i) % capacity];
        }
        delete[] deque;
        deque = newDeque;
        head = 0;
        tail = size - 1;
        capacity = newCapacity;
    }

    /**
     * Retorna uma representação em string do deque.
     * @return Uma string formatada com os elementos do deque.
     */
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
