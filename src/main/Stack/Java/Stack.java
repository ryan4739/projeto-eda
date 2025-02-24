
import java.util.*;

public class Stack{
    protected int[] array;
    protected int tail;
    public Stack(int capacidade){
        this.array = new int[capacidade];
        this.tail = -1;
    }
    public boolean isEmpty(){
        if(tail==-1){
            return true;
        }
        return false;
    }
    public boolean isFull() {
        if(this.tail+1>=array.length){
            return true;
        }
        return false;
    }

    // deve lançar exceção caso a pilha esteja cheia.
    public void push(int valor) {
        if(isFull()){
            throw new NoSuchElementException("Se ferrou cara");
        }
        array[++this.tail]=valor;
    }

    // deve lançar exceção caso a pilha esteja vazia.
    public int pop() {
        if(isEmpty()){
            throw new NoSuchElementException("sE FERRROU CARA");
        }
        int V = array[this.tail--];
        return V;
    }

    // deve lançar exceção caso a pilha esteja vazia.
    public int peek() {
        if(isEmpty()){
            throw new NoSuchElementException("RUaaaaaaaaaaannnnnnn");
        }
        return this.array[this.tail];
    }


    // deve retornar uma string representando a pilha. Veja os testes para a especificação
    // detalhada. Não é permitido iterar diretamente sobre o array ou criar arrays. Crie outra pilha, se preciso. Use as operações push, pop,
    // isEmpty etc. 
    public String toString() {
        if(isEmpty()){
            throw new NoSuchElementException("RICARRRRRRDO");
        }
        String pilha = "";
        int contador = 0;
        while(!isEmpty()){
            pilha += pop();
            if(!isEmpty()){
                pilha += " ,";
            }
            contador++;
        }
        tail=+contador;
        return pilha;
    }
    
    // Deve retornar a posição da primeira ocorrência do elemento passado como parâmetro. Note que
    // o topo sempre está na primeira posição (0), abaixo do topo é a posição 1 etc. Não confunda
    // com os índices do array. Interprete os testes para a especificação mais detalhada.
    // Não é permitido iterar diretamente sobre o array. Use as operações push, pop,
    // isEmpty etc.
    public int indexOf(int valor) {
        int contador = 0;
        int numero= 0;
        while(!isFull()){
            if(array[contador++]==valor){
                 numero=contador;
            }
        }
        return numero;
    }

    public int size() {
        return this.tail+1;
    }

}
