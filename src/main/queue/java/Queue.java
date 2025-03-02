package queue;

/**
 * Uma classe de fila baseada em arrays, com as funcionalidades de criar uma
 * pilha de tamanho determinado, inserir elementos e remover elementos. 
 *
 * @param <T> O tipo de elemento que esta fila pode guardar e operar.  
 */
public class Queue<T> {

	/**
	 * Fila em si.
	 */
	private T[] queue;
	/**
	 * Tamanho da fila.
	 */
	private int size;
	/**
	 * Ponteiro para o início da fila.
	 */
	private int head;
	/**
	 * Ponteiro para o final da fila.
	 */
	private int tail;

	/**
	 * O construtor da classe de fila.
	 *
	 * @param size O tamanho da fila.
	 *
	 */
	public Queue(int capacity) {
		this.queue = (T[]) new Object[capacity];
		this.size = 0;
		this.head = -1;
		this.tail = -1;
	}

	/**
	 * Insere elemento no final da fila.
	 *
	 * @param element Elemento à ser inserido na fila.
	 * @return Status de sucesso da operação.
	 */
	public void insertElement(T element) {
		if (isFull() == true)
			throw new IllegalStateException("Queue is full!");
		updateTail();
		this.queue[this.tail] = element;
		this.size++;
	}

	/**
	 * Remove e retorna elemento da fila.
	 *
	 * @return Elemento removido.
	 */
	public T removeElement() {
		if (isEmpty() == true)
			throw new IllegalStateException("Queue is empty!");
		updateHead();	
		return this.queue[this.head - 1];
	}

	/**
	 * Busca elemento na fila e retorna o índice do elemento, caso encontrado,
	 * ou -1, caso não encontrado.
	 *
	 * @param element Elemento a ser buscado.
	 * @return Índice do elemento ou indicação de que o elemento não foi
	 * encontrado.
	 */
	public int searchElement(T element) {
		for (int i = 0; i < this.queue.length; i++) {
			if (this.queue[i].equals(element))
				return i;
		}
		return -1;
	}

	/**
	 * Atualiza o ponteiro de início da fila.
	 */
	private void updateHead() {
		if (this.head + 1 == this.queue.length)
			this.head = 0;
		this.head++;
	}

	/**
	 * Atualiza o ponteiro de final da fila.
	 */
	private void updateTail() {
		if (this.tail + 1 == this.queue.length)
			this.tail = 0;
		this.tail++;
	}

	/**
	 * Verifica se a fila está vazia.
	 *
	 * @return Status de esvaziez (:D) da fila.
	 */
	private boolean isEmpty() {
		if (this.head == this.tail)
			return true;
		return false;
	}

	/**
	 * Verifica se a fila está cheia.
	 *
	 * @return Status de cheiez (:D) da fila.
	 */
	private boolean isFull() {
		if (this.tail + 1 == this.head)
			return true;
		if ((this.tail + 1 == this.queue.length) && (this.head == 0))
			return true;
		return false;
	}

}

