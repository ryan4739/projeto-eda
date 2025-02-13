package queue;

/**
 * Uma classe de fila baseada em arrays, com as funcionalidades de criar uma
 * pilha de tamanho determinado, inserir elementos e remover elementos. 
 *
 * @param <T> O tipo de elemento que esta fila pode guardar e operar.  
 */
public class Queue<T> {

	/**
	 * Tamanho da fila.
	 */
	protected int length;
	/**
	 * Fila em si.
	 */
	protected T[] queue;

	/**
	 * O construtor da classe de fila.
	 *
	 * @param length O tamanho da fila.
	 *
	 */
	public Queue(int length) {
		this.length = length;
		this.queue = (T[]) new Object[length];
	} 

}

