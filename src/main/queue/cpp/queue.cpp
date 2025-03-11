#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {

private:
	T* queue;
	int head;
	int tail;
	int capacity;
	int size;

public:
	Queue(int capacity) {
		this->capacity = capacity;
		this->queue = new T[capacity];
		this->head = -1;
		this->tail = -1;
		this->size = 0;
	}

	~Queue() {
		delete[] queue;
	}

	void addLast(T element) {
		if (isFull()) {
			throw std::overflow_error("Fila está cheia.");
		}
		if (isEmpty()) {
			head = 0;
		}
		tail = (tail + 1) % capacity;
		queue[tail] = element;
		size++;
	}

	void addFirst(T element) {
		//TODO
	}

	void add(T element, int index) {
		//TODO
	}

	T removeFirst() {
		//TODO
		return T();
	}

	T removeLast() {
		//TODO
		return T();
	}

	T remove(int index) {
		//TODO
		return T();
	}

	T getFirst() {
		if (isEmpty()) {
			throw std::underflow_error("Fila está vazia");
		}
		return queue[head];
	}

	T getLast() {
		if (isEmpty()) {
			throw std::underflow_error("Fila está vazia");
		}
		for (int i = 0; i < size - 1; i++) {
			addLast(removeFirst());
		}
		T element = getFirst();
		addLast(removeFirst());
		return element;
	}

	T get(int index) {
		//TODO
		return T();
	}

	int indexOf(T element_to_find) {
		//TODO
		return -1;
	}

	int lastIndexOf(T element_to_find) {
		//TODO
		return -1;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return size == capacity;
	}

};

