package lljava;

public class Node {
    int valor;
    Node next;

    public Node(int valor) {
        this.valor = valor;
        this.next = null;
    }

    public int getvalor() {
       return this.valor;
    }

    public void setvalor(int valor) {
        this.valor = valor;
    }

    public Node getNext() {
        return this.next;
    }

    public void setNext(Node next) {
        this.next = next;
    }
}
