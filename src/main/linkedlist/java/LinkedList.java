package java;

import java.util.NoSuchElementException;

public class LinkedList {
    private Node head;
    private Node tail;
    private int size;

    public LinkedList() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }
    
    public boolean isEmpty() {
        return this.size == 0;
    }

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

    public void add(int value, int indice) {
        if (indice == 0)
            addFirst(value);
        else if (indice == this.size-1)
            addLast(value);
        else {
            Node newNode = new Node(value);
            Node prevNode = getNodeIndice(indice-1);
            
            newNode.next = prevNode.next;
            prevNode.next = newNode;
        }
    }

    public void alteraNode(int value, int indice) {
        Node node = getNodeIndice(indice);
        node.value = value;
    }

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

    public void removeLast() {
        if (isEmpty()) throw new NoSuchElementException("Node não existe");

        if (this.size == 1) {
            this.head = null;
            this.tail = null;
        } else {
            Node prevNode = getNodeIndice(this.size-2);
            prevNode.next = null;
            this.tail = prevNode;
        }
        this.size--;
    }

    public void removeByIndex(int indice) {
        if (indice < 0 || indice > this.size-1) throw new IndexOutOfBoundsException("Índice inválido");
        
        if (indice == 0)
            removeFirst();
        else if (indice == this.size-1)
            removeLast();
        else {
            Node prevNode = getNodeIndice(indice);
            prevNode.next = prevNode.next.next;

            this.size--;
        }
    }

    public void removeByValue(int value) {
        if (!contains(value)) throw new NoSuchElementException("value não existe");
        
        int indice = getPrimeiraOcorrencia(value);
        removeByIndex(indice);
    }   

    public int sizeLL() {
        return this.size;
    }

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

    public int getValue(int indice) {
        return getNodeIndice(indice).value;
    }

    private Node getNodePorIndice(int indice) {
        Node node = this.head;
        for (int i = 0; i < indice; i++)
            node = node.next;

        return node;
    }

    private int getPrimeiraOcorrencia(int value) {
        Node node = this.head;
        for (int i = 0; i < this.size; i++) {
            if (node.value == value)
                return i;

            node = node.next;
        }
        return -1;
    }

    public boolean contains(int value) {
        Node node = this.head;
        for (int i = 0; i < this.size; i++)
            if (node.value == value)
                return true;
        
        return false;
    }

    public static class Node {
        int value;
        Node next;

        public Node(int value) {
            this.value = value;
            this.next = null;
        }
    }

}
