package queue;

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
	 * @return Status de sucesso da operação.
	 */
	public void addLast(T element) {
		if (isFull() == true)
			throw new IllegalStateException("Fila cheia.");
		this.tail = (this.tail + 1) % this.capacity;
		this.queue[this.tail] = element;
		this.size++;
	}

	public void addFirst(T element) {
		//TODO
	}

	public void add(T element, int index) {
		//TODO
	}

	/**
	 * Remove e retorna elemento da fila.
	 *
	 * @return Elemento removido.
	 */
	public T removeFirst() {
		if (isEmpty()) throw new IllegalStateException("Fila vazia.");
		int element = this.queue[this.head];
		this.size--;
		if (this.head == this.tail) {
			this.head = -1;
			this.tail = -1;
		} else {
			this.head = (this.head + 1) % this.capacity;
		}
		return element;
	}

	public T removeLast() {
		//TODO
	}

	public T remove(int index) {
		//TODO
	}

	public T getFirst() {
		//TODO
	}

	public T getLast() {
		//TODO
	}

	public T get() {
		//TODO
	}

	/**
	 * Busca elemento na fila e retorna o primeiro índice do elemento, caso
	 * encontrado, ou -1, caso não encontrado.
	 *
	 * @param element Elemento a ser buscado.
	 * @return Índice do elemento ou indicação de que o elemento não foi
	 * encontrado.
	 */
	public int indexOf(T element) {
		int index = -1;
		for (int i = 0; i < this.size; i++) {
			int value = this.removeFirst();
			if (index == -1 && value == element)
				index = i;
			this.addLast(value);
		}
		return index;
	}

	public int lastIndexOf(T element) {
		//TODO
	}

	/**
	 * Verifica se a fila está vazia.
	 *
	 * @return Status de esvaziez (:D) da fila.
	 */
	private boolean isEmpty() {
		return this.head == -1 && this.tail == -1;
	}

	/**
	 * Verifica se a fila está cheia.
	 *
	 * @return Status de cheiez (:D) da fila.
	 */
	private boolean isFull() {
		return (this.tail + 1) % this.capacity == this.head;
	}

}

