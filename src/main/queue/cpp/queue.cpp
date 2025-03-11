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
		is (isEmpty()) {
			head = 0;
		}
		tail = (tail + 1) % capacity;
		queue[tail] = element;
		size++;
	}

	void addFirst(T element) {}

	void add(T element, int index) {}

	T removeFirst() {return T();}

	T removeLast() {return T();}

	T remove(int index) {return T();}

	T getFirst() {return T();}

	T getLast() {return T();}

	T get(int index) {return T();}

	int indexOf(T element_to_find) {return -1;}

	int lastIndexOf(T element_to_find) {return T();}

	int getSize() {return -1;}

	bool isEmpty() {return false;}

	bool isFull() {return false;}

};

