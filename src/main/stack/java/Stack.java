
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
    // Deve mandar verdadeiro se está cheio, falso no contrário
    // @Param 
    public boolean isFull() {
        if(this.tail+1>=array.length){
            return true;
        }
        return false;
    }
    public void direita(int index){
        for(int i = index; i<tail; i++){
            array[i+1] = array[i];
        }
    }
    // deve lançar exceção caso a pilha esteja cheia.
    public void push(int valor) {
        if(isFull()){
            throw new NoSuchElementException("Carga máxima atingida");
        }
        array[++this.tail]=valor;
    }
    public void pushLast(int valor){
        if(isFull()){
            throw new IndexOutOfBoundries("Carga máxima atingida");
        }
        direita(0);
        array[0] = valor;
        this.tail++;
    }
    public void pushIndex(int valor, int index){
        if(isFull() || index<0 || index >tail+1){
            throw new IndexOutOfBoundries("Carga máxima atingida ou index invalido");
        }
        direita(index);
        array[index] = valor;
        this.tail++;
    }
    public void esquerda(int index){
        for(int i=index; i>0;i--){
            array[i-1] = array[i];
        }
    }
    // deve lançar exceção caso a pilha esteja vazia.
    public int pop() {
        if(isEmpty()){
            throw new NoSuchElementException("ELemento inexistente");
        }
        int V = array[this.tail--];
        return V;
    }

    public void popLast(){
        if(isEmpty()){
            throw new IndexOutOfBoundries("ELemento inexistente");
        }
        esquerda(0)
        this.tail--;
    }
    public void popIndex(int index){
        if(isEmpty() || index<0 || index >tail){
            throw new IndexOutOfBoundries("ELemento inexistente ou index fora de range");
        }
        esquerda(index);
        this.tail--;
    }
    // deve lançar exceção caso a pilha esteja vazia.
    public int peek() {
        if(isEmpty()){
            throw new NoSuchElementException("Não existe elementos na Stack");
        }
        return this.array[this.tail];
    }
    public int peekIndex(int index){
        if(isEmpty() || index>tail+1 || index<0s){
            throw new IndexOutOfBoundries("Não existe elementos na Stack);
        }
        return this.array[index];
    }
    public int peekLast(){
       if(isEmpty()){
            throw new IndexOutOfBoundries("Não existe elementos na Stack");
        }
        return this.array[0]; 
    }


    // Retorna a versão da String 
    public String toString() {
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
    // retorna o tamanho do Stack
    public int size() {
        return this.tail+1;
    }

}
