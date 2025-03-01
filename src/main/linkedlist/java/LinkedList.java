import java.util.NoSuchElementException;

/**
 * Representação de uma lista encadeada
 */
public class LinkedList {
    /**
     * O primeiro nó da lista
     */
    private Node head;

    /**
     * O último nó da lista
     */
    private Node tail;

    /**
     * O tamanho da lista
     */
    private int size;
    
    public LinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }
    
    /**
     * Verifica se a lista está vazia
     * @return true caso esteja vazia, false caso não
     */
    public boolean isEmpty() {
        return this.size == 0;
    }

    /**
     * Adiciona um elemento na primeira posição da lista
     * 
     * @param value o valor a ser adicionado
     */
    public void addFirst(int value) {
        Node newNode = new Node(value);

        if (isEmpty()) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            newNode.next = this.head;
            this.head = newNode;
        }
        this.size++;
    }

    /**
     * Adiciona um elemento na última posição da lista
     * 
     * @param value o valor a ser adicionado
     */
    public void addLast(int value) {
        Node newNode = new Node(value);
        
        if (isEmpty()) {
            this.head = newNode;
            this.tail = newNode;
        } else {
            this.tail.next = newNode;
            this.tail = newNode;
        }
        this.size++;
    }

    /**
     * Adiciona um elemento em um índice específico da lista
     * 
     * @param value o valor a ser adicionado
     * @param index a posição na qual ele será adicionado
     */
    public void add(int value, int index) {
        if (index < 0 || index > this.size-1) throw new IndexOutOfBoundsException("Índice inválido");

        if (index == 0)
            addFirst(value);
        else if (index == this.size-1)
            addLast(value);
        else {
            Node newNode = new Node(value);
            Node prevNode = getNodeByIndex(index-1);
            
            newNode.next = prevNode.next;
            prevNode.next = newNode;
        }
    }

    /**
     * Altera o valor de um nó na lista
     * 
     * @param value o valor a ser alterado
     * @param index o índice do valor a ser alterado
     */
    public void updateNode(int value, int index) {
        if (index < 0 || index > this.size-1) throw new IndexOutOfBoundsException("Índice inválido");

        Node node = getNodeByIndex(index);
        node.value = value;
    }

    /**
     * Pega o valor do node a partir de seu índice
     * 
     * @param index o índice do node
     * @return o valor contido no node
     */
    public int getValue(int index) {
        if (index < 0 || index > this.size-1) throw new IndexOutOfBoundsException("Índice inválido");
        return getNodeByIndex(index).value;
    }
    
    /**
     * Remove o primeiro elemento da lista
     */
    public void removeFirst() {
        if (isEmpty()) throw new NoSuchElementException("Node não existe");

        if (this.size == 1) {
            this.head = null;
            this.tail = null;
        } else {
            this.head = this.head.next;            
        }
        this.size--;
    }

    /**
     * Remove o último elemento da lista
     */
    public void removeLast() {
        if (isEmpty()) throw new NoSuchElementException("Node não existe");

        if (this.size == 1) {
            this.head = null;
            this.tail = null;
        } else {
            Node prevNode = getNodeByIndex(this.size-2);
            prevNode.next = null;
            this.tail = prevNode;
        }
        this.size--;
    }

    /**
     * Remove um elemento da lista a partir de seu índice
     * 
     * @param index o índice do elemento a ser removido
     */
    public void removeByIndex(int index) {
        if (index < 0 || index > this.size-1) throw new IndexOutOfBoundsException("Índice inválido");
        
        if (index == 0)
            removeFirst();
        else if (index == this.size-1)
            removeLast();
        else {
            Node prevNode = getNodeByIndex(index);
            prevNode.next = prevNode.next.next;

            this.size--;
        }
    }

    /**
     * Remove o primeiro elemento da lista que tiver o valor informado
     * 
     * @param value o valor a ser removido
     */
    public void removeByValue(int value) {
        if (!contains(value)) throw new NoSuchElementException("Valor não está contido");
        
        int index = getFirstOccurrence(value);
        removeByIndex(index);
    }   
    
    /**
     * Informa o índice da primeira ocorrência de um valor. Se não estiver presente na lista, retornará -1
     * 
     * @param value o valor a ser encontrado
     * @return o índice, caso o valor esteja na lista, -1 caso não.
     */
    private int getFirstOccurrence(int value) {
        if (isEmpty()) throw new NoSuchElementException("Elemento não existe");

        Node node = this.head;
        for (int i = 0; i < this.size; i++) {
            if (node.value == value)
                return i;

            node = node.next;
        }
        return -1;
    }

    /**
     * Pega o node em um índice informado
     * 
     * @param index o índice do node
     * @return o node
     */
    private Node getNodeByIndex(int index) {
        if (index < 0 || index > this.size-1) throw new IndexOutOfBoundsException("Índice inválido");

        Node node = this.head;
        for (int i = 0; i < index; i++)
        node = node.next;
        
        return node;
    }

    /**
     * Informa o tamanho da lista
     * 
     * @return o tamanho da lista
     */
    public int sizeLL() {
        return this.size;
    }
    
    /**
     * Verifica se um valor está contido ou não na lista
     * 
     * @param value o valor a ser buscado
     * @return true caso o valor esteja contido, false caso não
     */
    public boolean contains(int value) {
        Node node = this.head;
        for (int i = 0; i < this.size; i++)
        if (node.value == value)
        return true;
        
        return false;
    }

    /**
     * Representação textual da lista no formato "a -> b -> c [...]"
     */
    public String toString() {
        String llString = "";
    
        Node nodeAtual = this.head;
        for (int i = 0; i < this.size; i++) {
            llString += nodeAtual.value;
            if (i != this.size-2)
                llString += " -> ";
        }
        return llString;
    }
    
    /**
     * Representação de um Nó da lista
     */
    public static class Node {
        int value;
        Node next;
        
        public Node(int value) {
            this.value = value;
            this.next = null;
        }
    }
    
}
