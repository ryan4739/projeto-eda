package array;

/**
 * Uma classe genérica de Array com as funcionalidades de criar um array com
 * tamanho determinado, inserir elementos e remover elementos.
 *
 * @param <T> O tipo de elemento que este array pode guardar e operar.
 */
public class Array<T> {

	/**
	 * O array em si.
	 */
	protected T[] array;
	/**
	 * O tamanho do array.
	 */
	protected int size;

	/**
	 * O construtor da classe de array.
	 *
	 * @param size O tamanho do array a ser criado.
	 */
	@SuppressWarnings("unchecked")
	public Array(int size) {
		this.array = (T[]) new Object[size];
		this.size = size;
	}
	
	/**
	 * Retorna o elemento relativo ao índice indicado.
	 *
	 * @param index Índice do elemento a ser retornado.
	 * @return O elemento especificado pelo índice, caso encontrado.
	 */
	public T getElement(int index) {
		if (index < 0 || index >= size) 
			throw new IndexOutOfBoundsException("Índice inválido!");
		return array[index];
	}

	/**
	 * Adiciona o elemento no índice indicado.
	 *
	 * @param element O elemento a ser adicionado.
	 * @param index O índice do elemento a ser adicionado.
	 * @return Status de sucesso da operação.
	 */
	public boolean setElement(T element, int index) {
		if (index < 0 || index >= size)
			return false;
		array[index] = element;
		return true;
	}

	/**
	 * Remove o elemento do índice indicado.
	 *
	 * @param index Índice do elemento a ser removido.
	 * @return Status de sucesso da operação.
	 */
	public boolean rmElement(int index) {
		if (index < 0 || index >= size)
			return false;
		array[index] = null;
		return true;
	}

}
