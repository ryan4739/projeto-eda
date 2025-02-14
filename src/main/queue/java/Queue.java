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
	protected T[] queue;
	/**
	 * Tamanho da fila.
	 */
	protected int size;
	/**
	 * Ponteiro para o início da fila.
	 */
	protected int head;
	/**
	 * Ponteiro para o final da fila.
	 */
	protected int tail;

	/**
	 * O construtor da classe de fila.
	 *
	 * @param size O tamanho da fila.
	 *
	 */
	public Queue(int size) {
		this.queue = (T[]) new Object[size];
		this.size = 0;
		this.head = -1;
		this.tail = -1;
	} 

}

