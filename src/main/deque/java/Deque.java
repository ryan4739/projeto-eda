package deque;

import java.util.NoSuchElementException;


/**
 * Implementação de um Deque (Fila Dupla) usando um array circular.
 */
public class Deque {

    public static final int Default = 20; // Capacidade padrão do deque
    private int[] deque; // Array para armazenar os elementos do deque
    private int size; // Número de elementos no deque
    private int head; // Índice do primeiro elemento
    private int tail; // Índice do último elemento
    private int capacity; // Capacidade atual do deque
    

    /**
     * Construtor padrão que inicializa o deque com capacidade padrão.
     */
    public Deque() {
        this(Default);
    }
    
    /**
     * Construtor que inicializa o deque com uma capacidade específica.
     * @param capacidade Capacidade inicial do deque.
     */
    public Deque(int capacidade) {
        deque = new int[capacidade];
        size = 0;
        head = -1;
        tail = -1;
        capacity = capacidade;
    }

    /**
     * Adiciona um elemento no início do deque.
     * @param entrada elemento a ser adicionado.
     */
    public void appendLeft(int entrada) {
        if (isFull()) {
            resize();
        }
        head = (head - 1 + capacity) % capacity;
        deque[head] = entrada;
        if (size == 0) {
            tail = head;
        }
        size++;
    }

    /**
     * Adiciona um elemento no final do deque.
     * @param entrada elemento a ser adicionado.
     */
    public void appendRight(int entrada) {
        if (isFull()) {
            resize();
        }
        tail = (tail + 1) % capacity;  
        deque[tail] = entrada;
        if (size == 0) {
            head = tail;
        }
        size++;
    }

    /**
     * Remove e retorna o elemento do início do deque.
     * @throws NoSuchElementException se o deque estiver vazio.
     */
    public int popLeft() {
        if (isEmpty()) {
            throw new NoSuchElementException("O Deque está vazio");
        }
        int aux = deque[head];
        head = (head + 1) % capacity;
        size--;
        if (size == 0) {
            head = -1;
            tail = -1;
        }
        return aux;
    }

    /**
     * Remove e retorna o elemento do final do deque.
     * @throws NoSuchElementException se o deque estiver vazio.
     */
    public int popRight() {
        if (isEmpty()) {
            throw new NoSuchElementException("O Deque está vazio");
        }
        int aux = deque[tail];
        tail = (tail - 1 + capacity) % capacity;
        size--;
        if (size == 0) {
            head = -1;
            tail = -1;
        }
        return aux;
    }

    /**
     * Retorna o primeiro elemento do deque sem removê-lo.
     * @throws NoSuchElementException se o deque estiver vazio.
     */
    public int peekLeft() {
        if (isEmpty()) {
            throw new NoSuchElementException("O Deque está vazio");
        }
        return deque[head];
    }

    /**
     * Retorna o último elemento do deque sem removê-lo.
     * @throws NoSuchElementException se o deque estiver vazio.
     */
    public int peekRight() {
        if (isEmpty()) {
            throw new NoSuchElementException("O Deque está vazio");
        }
        return deque[tail];
    }

    /**
     * Retorna o número de elementos no deque.
     */
    public int getSize() {
        return size;
    }

    /**
     * Retorna o número máximo de elementos que cabem no deque no momento.
     */
    public int getCapacity(){
        return capacity;
    }

    /**
     * Verifica se o deque contém um determinado valor.
     * @param valor O valor a ser buscado.
     * @return true se o valor for encontrado, false caso contrário.
     */
    public boolean contains(int valor) {
        for (int i = 0; i < size; i++) {
            if (deque[(head + i) % capacity] == valor) {
                return true;
            }
        }
        return false;
    }

    /**
     * Verifica se o deque está cheio.
     * @return true se o deque estiver cheio, false caso contrário.
     */
    public boolean isFull() {
        return size == capacity;
    }

    /**
     * Verifica se o deque está vazio.
     * @return true se o deque estiver vazio, false caso contrário.
     */
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * Expande a capacidade do deque quando necessário.
     */
    private void resize() {
        int[] deqAux = new int[capacity * 2];
        for (int i = 0; i < size; i++) {
            deqAux[i] = deque[(head + i) % capacity];
        }
        deque = deqAux;
        head = 0;
        tail = size - 1;
        capacity *= 2;
    }

    /**
     * Retorna uma representação em string do deque.
     */
    public String toString() {
        if (isEmpty()) {
            return "[]";
        }
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < size; i++) {
            sb.append(deque[(head + i) % capacity]);
            if (i < size - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }
}
