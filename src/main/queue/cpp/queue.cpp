#include <iostream>
#include <stdexcept>

/**
 * @brief Classe que implementa uma fila circular em C++.
 * @tparam T Tipo dos elementos armazenados na fila.
 */
template <typename T>
class Queue {

private:
	T* queue;
	int head;
	int tail;
	int capacity;
	int size;

public:
	/**
     * @brief Construtor da classe Queue.
     * @param capacity Capacidade máxima da fila.
     */
	Queue(int capacity) {
		this->capacity = capacity;
		this->queue = new T[capacity];
		this->head = -1;
		this->tail = -1;
		this->size = 0;
	}

	/**
     * @brief Destrutor da classe Queue.
     * Libera a memória alocada para o array da fila.
     */
	~Queue() {
		delete[] queue;
	}

	/**
     * @brief Adiciona um elemento ao final da fila.
     * @param element Elemento a ser adicionado.
     * @throws std::runtime_error Se a fila estiver cheia.
     */
	void addLast(T element) {
		if (isFull()) throw std::runtime_error("Fila cheia.");
		if (isEmpty()) {
			head = 0;
		}
		tail = (tail + 1) % capacity;
		queue[tail] = element;
		size++;
	}

	/**
     * @brief Adiciona um elemento no início da fila.
     * @param element Elemento a ser adicionado.
     * @throws std::runtime_error Se a fila estiver cheia.
     */
	void addFirst(T element) {
		if (isFull()) throw std::runtime_error("Fila cheia.");
		addLast(element);
		for (int i = 0; i < this->size - 1; i++) {
			addLast(removeFirst());
		}
	}

	/**
     * @brief Adiciona um elemento em uma posição específica da fila.
     * @param element Elemento a ser adicionado.
     * @param index Índice onde o elemento será inserido.
     * @throws std::runtime_error Se a fila estiver cheia ou o índice for inválido.
     */
	void add(T element, int index) {
		if (isFull()) throw std::runtime_error("Fila cheia.");
		if (index < 0 || index > this->size)
            throw std::runtime_error("Índice inválido.");
		if (index == 0) addFirst(element);
        else if (index == this->size) addLast(element);
        else {
            Queue<T> aux(this->capacity);
            for (int i = 0; i < index; i++)
                aux.addLast(this->removeFirst());
            aux.addLast(element);
            while (!this->isEmpty())
                aux.addLast(this->removeFirst());
            while (!aux.isEmpty())
                this->addLast(aux.removeFirst());
        }
	}

	/**
     * @brief Remove e retorna o primeiro elemento da fila.
     * @return O elemento removido.
     * @throws std::runtime_error Se a fila estiver vazia.
     */
	T removeFirst() {
		if (isEmpty()) throw std::runtime_error("Fila vazia.");
        T element = this->queue[this->head];
        this->size--;
        if (this->head == this->tail) {
            this->head = -1;
            this->tail = -1;
        } else {
            this->head = (this->head + 1) % this->capacity;
        }
        return element;
	}

	/**
     * @brief Remove e retorna o último elemento da fila.
     * @return O elemento removido.
     * @throws std::runtime_error Se a fila estiver vazia.
     */
	T removeLast() {
		if (isEmpty()) throw std::runtime_error("Fila vazia.");
        for (int i = 0; i < this->size - 1; i++)
            this->addLast(removeFirst());
        return removeFirst();
	}

	/**
     * @brief Remove e retorna o elemento em uma posição específica da fila.
     * @param index Índice do elemento a ser removido.
     * @return O elemento removido.
     * @throws std::runtime_error Se a fila estiver vazia ou o índice for inválido.
     */
	T remove(int index) {
		if (isEmpty()) throw std::runtime_error("Fila vazia.");
        if (index < 0 || index >= this->size)
            throw std::runtime_error("Índice inválido.");
        if (index == 0) return removeFirst();
        if (index == this->size - 1) return removeLast();

        Queue<T> aux(this->capacity);
        for (int i = 0; i < index; i++)
            aux.addLast(this->removeFirst());
        T element = this->removeFirst();
        while (!this->isEmpty())
            aux.addLast(this->removeFirst());
        while (!aux.isEmpty())
            this->addLast(aux.removeFirst());
        return element;
	}

	/**
     * @brief Retorna o primeiro elemento da fila sem removê-lo.
     * @return O primeiro elemento da fila.
     * @throws std::runtime_error Se a fila estiver vazia.
     */
	T getFirst() {
		if (isEmpty()) throw std::runtime_error("Fila vazia.");
		return queue[head];
	}

	/**
     * @brief Retorna o último elemento da fila sem removê-lo.
     * @return O último elemento da fila.
     * @throws std::runtime_error Se a fila estiver vazia.
     */
	T getLast() {
		if (isEmpty()) throw std::runtime_error("Fila vazia.");
		for (int i = 0; i < size - 1; i++) {
			addLast(removeFirst());
		}
		T element = getFirst();
		addLast(removeFirst());
		return element;
	}

	/**
     * @brief Retorna o elemento em uma posição específica da fila sem removê-lo.
     * @param index Índice do elemento a ser retornado.
     * @return O elemento na posição especificada.
     * @throws std::runtime_error Se a fila estiver vazia ou o índice for inválido.
     */
	T get(int index) {
		if (isEmpty()) throw std::runtime_error("Fila vazia.");
        if (index < 0 || index >= this->size)
            throw std::runtime_error("Índice inválido.");

        Queue<T> aux(this->capacity);
        for (int i = 0; i < index; i++)
            aux.addLast(this->removeFirst());
        T element = this->queue[this->head];
        while (!this->isEmpty())
            aux.addLast(this->removeFirst());
        while (!aux.isEmpty())
            this->addLast(aux.removeFirst());
        return element;
	}

	/**
     * @brief Retorna o índice da primeira ocorrência de um elemento na fila.
     * @param element_to_find Elemento a ser buscado.
     * @return O índice da primeira ocorrência do elemento, ou -1 se não encontrado.
     */
	int indexOf(T element_to_find) {
		int index = -1;
        for (int i = 0; i < this->size; i++) {
            T element = this->removeFirst();
            if (index == -1 && element == element_to_find)
                index = i;
            this->addLast(element);
        }
        return index;
	}

	/**
     * @brief Retorna o índice da última ocorrência de um elemento na fila.
     * @param element_to_find Elemento a ser buscado.
     * @return O índice da última ocorrência do elemento, ou -1 se não encontrado.
     */
	int lastIndexOf(T element_to_find) {
		int index = -1;
        for (int i = 0; i < this->size; i++) {
            T element = this->removeFirst();
            if (element == element_to_find)
                index = i;
            this->addLast(element);
        }
        return index;
	}

	/**
     * @brief Retorna o número de elementos na fila.
     * @return O tamanho da fila.
     */
	int getSize() {
		return size;
	}

	/**
     * @brief Verifica se a fila está vazia.
     * @return true se a fila estiver vazia, false caso contrário.
     */
	bool isEmpty() {
		return size == 0;
	}

	/**
     * @brief Verifica se a fila está cheia.
     * @return true se a fila estiver cheia, false caso contrário.
     */
	bool isFull() {
		return size == capacity;
	}

};

