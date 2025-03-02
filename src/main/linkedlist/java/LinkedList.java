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
        if (index == 0)
            addFirst(value);
        else if (index == this.size)
            addLast(value);
        else {
            if (index < 0 || index > this.size-1) throw new IndexOutOfBoundsException("Índice inválido");
            
            Node newNode = new Node(value);
            Node prevNode = getNodeByIndex(index-1);
            
            newNode.next = prevNode.next;
            prevNode.next = newNode;
            this.size++;
        }
    }

    /**
     * Informa o valor do primeiro elemento da lista
     * 
     * @return o valor do primeiro elemento da lista
     */
    public int getFirst() {
        return this.head.value;
    }

    /**
     * Informa o valor do último elemento da lista
     * 
     * @return o último elemento da lista
     */
    public int getLast() {
        return this.tail.value;
    }

    /**
     * Pega o valor do node a partir de seu índice
     * 
     * @param index o índice do node
     * @return o valor contido no node
     */
    public int get(int index) {
        if (index < 0 || index > this.size-1) throw new IndexOutOfBoundsException("Índice inválido");
        
        int value;
        if (index == 0)
            value = getFirst();
        else if (index == this.size-1)
            value = getLast();
        else
            value = getNodeByIndex(index).value;
            
        return value;
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
            Node prevNode = getNodeByIndex(index-1);
            prevNode.next = prevNode.next.next;

            this.size--;
        }
    }

    /**
     * Remove o primeiro elemento da lista que tiver o valor informado
     * 
     * @param value o valor a ser removido
     */
    public boolean removeByValue(int value) {        
        int index = indexOf(value);

        if (index != -1) {
            removeByIndex(index);
            return true;
        }
        return false;
    }   
    
    /**
     * Informa o índice da primeira ocorrência de um valor. Se não estiver presente na lista, retornará -1
     * 
     * @param value o valor a ser encontrado
     * @return o índice da primeira ocorrência do valor, caso esteja na lista, -1 caso não.
     */
    public int indexOf(int value) {
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
     * Informa o índice da última ocorrência de um valor. Se não estiver presente na lista, retornará -1
     * 
     * @param value o valor buscado
     * @return o índice da última ocorrência do valor, caso esteja na lista, -1 caso não
     */
    public int lastIndexOf(int value) {
        if (isEmpty()) throw new NoSuchElementException("Elemento não existe");
        
        int index = -1;
        
        Node node = this.head;
        for (int i = 0; i < this.size; i++) {
            if (node.value == value)
                index = i;
            
            node = node.next;
        }
        return index;
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
       return indexOf(value) != -1;
    }

    /**
     * Representação textual da lista no formato "a -> b -> c [...]"
     */
    public String toString() {
        if (isEmpty()) return "";

        Node currNode = this.head;
        String llString = "";
        while (currNode != null) {
            llString += currNode.value + " -> ";
            currNode = currNode.next;
        }
        return llString.substring(0, llString.length() - 4);
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
