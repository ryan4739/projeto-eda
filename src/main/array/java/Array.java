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
	 * O construtor da classe de array.
	 *
	 * @param size O tamanho do array a ser criado.
	 */
	@SuppressWarnings("unchecked")
	public Array(int capacity) {
		this.array = (T[]) new Object[capacity];
	}
	
	/**
	 * Retorna o primeiro índice relativo ao elemento indicado.
	 *
	 * @param element Elemento a ser buscado.
	 * @return Índice do elemento, caso encontrado, ou -1, caso não encontrado.
	 */
	public int searchElement(T element) {
		for (int i = 0; i < this.array.length; i++) {
			if (this.array[i] != null && this.array[i].equals(element))
				return i;
		}
		return -1;
	}

	/**
	 * Insere o elemento no índice indicado.
	 *
	 * @param element Elemento a ser inserido.
	 * @param index Índice do elemento a ser inserido.
	 * @return Estado de sucesso da operação.
	 */
	public boolean insertElement(T element, int index) {
		if (isIndexValid(index) == false)
			return false;
		array[index] = element;
		return true;
	}

	/**
	 * Remove o elemento do índice indicado.
	 *
	 * @param index Índice do elemento a ser removido.
	 * @return Estado de sucesso da operação.
	 */
	public boolean removeElement(int index) {
		if (isIndexValid(index) == false)
			return false;
		array[index] = null;
		return true;
	}

	/**
	 * Verifica se o índice é válido.
	 *
	 * @param index Índice a ser validado.
	 * @return Validez do índice.
	 */
	private boolean isIndexValid(int index) {
		if (index < 0 || index >= this.array.length)
			return false;
		return true;
	}

}
