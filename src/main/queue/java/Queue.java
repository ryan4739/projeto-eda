package src.main.queue.java;

/**
 * Uma classe de fila baseada em arrays, com as funcionalidades de criar uma
 * pilha de tamanho determinado, inserir elementos e remover elementos. 
 *
 * @param <T> O tipo de elemento que esta fila pode guardar e operar.  
 */
public class Queue<T> {

	/**
	 * Array de elementos do tipo genérico que representa a fila.
	 */
	private T[] queue;
	/**
	 * Ponteiro para o início da fila.
	 */
	private int head;
	/**
	 * Ponteiro para o final da fila.
	 */
	private int tail;
	/**
	 * Capacidade da fila.
	 */
	private int capacity;
	/**
	 * Tamanho da fila.
	 */
	private int size;

	/**
	 * O construtor da classe de fila.
	 *
	 * @param size O tamanho da fila.
	 *
	 */
	public Queue(int capacity) {
		this.queue = (T[]) new Object[capacity];
		this.head = -1;
		this.tail = -1;
		this.capacity = capacity;
		this.size = 0;
	}

	/**
	 * Insere elemento no final da fila.
	 *
	 * @param element Elemento à ser inserido na fila.
	 */
	public void addLast(T element) {
		if (isFull()) throw new IllegalStateException("Fila cheia.");
		if (isEmpty()) this.head = 0;
		this.tail = (this.tail + 1) % this.capacity;
		this.queue[this.tail] = element;
		this.size++;
	}

	/**
	 * Insere elemento no começo da fila.
	 *
	 * @param element Elemento à ser inserido na fila.
	 */
	public void addFirst(T element) {
		if (isFull()) throw new IllegalStateException("Fila cheia.");
		addLast(element);
		for (int i = 0; i < this.size - 1; i++)
			addLast(removeFirst());
	}

	/**
	 * Insere elemento na posição indicada da fila.
	 *
	 * @param element Elemento à ser inserido na fila.
	 */
	public void add(T element, int index) {
		if (isFull()) throw new IllegalStateException("Fila cheia.");
		if (index < 0 || index > this.size)
			throw new IndexOutOfBoundsException("Índice inválido.");
		if (index == 0) addFirst(element);
		else if (index == this.size) addLast(element);
		else {
			Queue<T> aux = new Queue<>(this.capacity);
			for (int i = 0; i < index; i++)
				aux.addLast(this.removeFirst());
			aux.addLast(element);
			while (!this.isEmpty())
				aux.addLast(this.removeFirst());
			while (!aux.isEmpty())
				this.addLast(aux.removeFirst());
		}
	}

	/**
	 * Remove e retorna o primeiro elemento da fila.
	 *
	 * @return Elemento removido.
	 */
	public T removeFirst() {
		if (isEmpty()) throw new IllegalStateException("Fila vazia.");
		T element = this.queue[this.head];
		this.size--;
		if (this.head == this.tail) {
			this.head = -1;
			this.tail = -1;
		} else {
			this.head = (this.head + 1) % this.capacity;
		}
		return element;
	}

	/**
	 * Remove e retorna o último elemento da fila.
	 *
	 * @return Elemento removido.
	 */
	public T removeLast() {
		if (isEmpty()) throw new IllegalStateException("Fila vazia.");
		for (int i = 0; i < this.size - 1; i++)
			this.addLast(removeFirst());
		return removeFirst();
	}

	/**
	 * Remove e retorna o elemento do índice indicado.
	 *
	 * @return Elemento removido.
	 */
	public T remove(int index) {
		if (isEmpty()) throw new IllegalStateException("Fila vazia.");
		if (index < 0 || index >= this.size)
			throw new IndexOutOfBoundsException("Índice inválido.");
		if (index == 0) return removeFirst();
		if (index == this.size - 1) return removeLast();

		Queue<T> aux = new Queue<>(this.capacity);
		for (int i = 0; i < index; i++)
			aux.addLast(this.removeFirst());
		T element = this.removeFirst();
		while (!this.isEmpty())
			aux.addLast(this.removeFirst());
		while (!aux.isEmpty())
			this.addLast(aux.removeFirst());
		return element;
	}

	/**
	 * Retorna o primeiro elemento da fila.
	 *
	 * @return Primeiro elemento da fila.
	 */
	public T getFirst() {
		if (isEmpty()) throw new IllegalStateException("Fila vazia.");
		return this.queue[this.head];
	}

	/**
	 * Retorna o último elemento da fila.
	 *
	 * @return Último elemento da fila.
	 */
	public T getLast() {
		if (isEmpty()) throw new IllegalStateException("Fila vazia.");
		for (int i = 0; i < this.size - 1; i++)
			this.addLast(removeFirst());
		T element = this.getFirst();
		this.addLast(this.removeFirst());
		return element;
	}

	/**
	 * Retorna o elemento do índice indicado da fila.
	 *
	 * @return Elemento do índice indicado da fila.
	 */
	public T get(int index) {
		if (isEmpty()) throw new IllegalStateException("Fila vazia.");
		if (index < 0 || index >= this.size)
			throw new IndexOutOfBoundsException("Índice inválido.");
		
		Queue<T> aux = new Queue<>(this.capacity);
		for (int i = 0; i < index; i++)
			aux.addLast(this.removeFirst());
		T element = this.queue[this.head];
		while (!this.isEmpty())
			aux.addLast(this.removeFirst());
		while (!aux.isEmpty())
			this.addLast(aux.removeFirst());
		return element;
	}

	/**
	 * Busca elemento indicado na fila e retorna o primeiro índice do elemento, 
	 * caso encontrado, ou -1, caso não encontrado.
	 *
	 * @param element Elemento a ser buscado.
	 * @return Índice do elemento ou indicação de que o elemento não foi
	 * encontrado.
	 */
	public int indexOf(T element_to_find) {
		int index = -1;
		for (int i = 0; i < this.size; i++) {
			T element = this.removeFirst();
			if (index == -1 && element == element_to_find)
				index = i;
			this.addLast(element);
		}
		return index;
	}

	/**
	 * Busca o elemento indicado na fila e retorna a última ocorrênia do elemento,
	 * caso encontrado, ou -1, caso não encontrado.
	 *
	 * @param element Elemento a ser buscado.
	 * @return Índice do elemento ou indicação de que o elemento não foi
	 * encontrado.
	 */
	public int lastIndexOf(T element_to_find) {
		int index = -1;
		for (int i = 0; i < this.size; i++) {
			T element = this.removeFirst();
			if (element == element_to_find)
				index = i;
			this.addLast(element);
		}
		return index;
	}

	/**
	 * Retorna o tamanho da fila.
	 *
	 * @return Tamanho da fila.
	 */
	public int size() {
		return this.size;
	}

	/**
	 * Verifica se a fila está vazia.
	 *
	 * @return Status de esvaziez (:D) da fila.
	 */
	public boolean isEmpty() {
		return this.head == -1 && this.tail == -1;
	}

	/**
	 * Verifica se a fila está cheia.
	 *
	 * @return Status de cheiez (:D) da fila.
	 */
	public boolean isFull() {
		return (this.tail + 1) % this.capacity == this.head;
	}

}

