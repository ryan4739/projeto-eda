package lljava;

public class LinkedList {
    private Node head;

    public LinkedList() {
        this.head = null;
    }
    
    public void adicionaNoInicio(int valor) {
        Node novoNode = new Node(valor);
        novoNode.next = this.head;
        this.head = novoNode;
    }

    public void adicionaPorIndice(int valor, int indice) {
        if (indice == 0) {
            this.adicionaNoInicio(valor);
            return;
        }
        
        Node nodeAtual = this.head;
        int posicao = 0;
        while ((nodeAtual != null) && (posicao + 1) != indice) {
            posicao += 1;
            nodeAtual = nodeAtual.next;
        }

        if (nodeAtual != null) {
            Node novoNode = new Node(valor);
            novoNode.next = nodeAtual.next;
            nodeAtual.next = novoNode;
        } else {
            System.out.println("Índice não existe!");
        }
    }

    public void adicionaNoFinal(int valor) {
        Node novoNode = new Node(valor);
        if (this.head == null) {
            this.adicionaNoInicio(valor);
            return;
        }

        Node nodeAtual = this.head;
        while (nodeAtual.next != null) {
            nodeAtual = nodeAtual.next;
        }

        nodeAtual.next = novoNode;
    }

    public void alteraNode(int valor, int indice) {
        Node nodeAtual = this.head;
        int posicao = 0;
        if (posicao == indice) {
            nodeAtual.valor = valor;
        } else {
            while (nodeAtual != null && posicao != indice) {
                nodeAtual = nodeAtual.next;
            }

            if (nodeAtual != null) {
                nodeAtual.valor = valor;
            } else {
                System.out.println("Índice não existe!");
            }
        }
    }

    public void removePrimeiroNode() {
        if (this.head == null) return;

        this.head = this.head.next;
    }

    public void removeNodeIndice(int indice) {
        if (this.head == null) return;
        
        Node nodeAtual = this.head;
        int posicao = 0;

        if (indice == 0) {
            this.removePrimeiroNode();
        } else {
            while (nodeAtual != null && posicao < indice - 1) {
                posicao += 1;
                nodeAtual = nodeAtual.next;
            }
            
            if (nodeAtual == null || posicao < indice - 1) {
                System.err.println("Índice não existe!");
            } else {
                nodeAtual.next = nodeAtual.next.next;
            }
        }    
    }

    public void removeUltimoNode() {
        if (this.head == null) return;

        if (this.head.next == null) this.removePrimeiroNode();
        
        Node nodeAtual = this.head;
        while (nodeAtual != null && nodeAtual.next.next != null) {
            nodeAtual = nodeAtual.next;
        }

        nodeAtual.next = null;
    }

    public void removeNode(int valor) {
        Node nodeAtual = this.head;

        if (nodeAtual.valor == valor) {
            this.removePrimeiroNode();
            return;
        }

        while (nodeAtual != null && nodeAtual.next.valor != valor) {
            nodeAtual = nodeAtual.next;
        }

        if (nodeAtual == null) {
            return;
        } else {
            nodeAtual.next = nodeAtual.next.next;
        }
    }

    public int tamanhoLinkedList() {
        int tamanho = 0;
        Node nodeAtual = this.head; 
        while (nodeAtual != null) {
            tamanho += 1;
            nodeAtual = nodeAtual.next;
        }

        return tamanho;
    }

    public void imprimeLinkedList() {
        Node nodeAtual = this.head;
        while (nodeAtual != null) {
            System.out.println(nodeAtual.valor);
            nodeAtual = nodeAtual.next;
        }
    }

    public int getElementoIndice(int indice) {
        Node nodeAtual = this.head;
        
        int posicao = 0;
        while (nodeAtual != null && posicao < indice) {
            nodeAtual = nodeAtual.next;
            posicao++;
        }

        if (nodeAtual == null) {
            System.out.println("Índice não existe!");
            return 0;
        }

        return nodeAtual.valor;
    }

}
