package main.deque.Java;

public class Deque<Obj> {

    public static final int Default = 20;
    private Obj[] deque;
    private int size;
    private int head;
    private int capacity;
    
    
    
    public Deque() {
        this(Default);
    }
    
    public Deque(int capacidade) {
        deque = new Obj[capacidade];
        size = 0;
        head = 0;
        capacity = capacidade;

    }


    public void appendLeft(Obj entrada) {
        if(isFull()){
            resize();
        }
        head = (head - 1 + capacity) % capacity;
        deque[head] = entrada;
        size++;
    }

    public void appendRight(Obj entrada) {
        if(isFull()){
            resize();
        }
        int tail = (head + size) % capacity;
        deque[tail] = entrada;
        size++;
    }

    public Obj popLeft() {
        if(isEmpty()){
            throw new NoSuchElementException();
        }
        Obj aux = deque[head];
        head = (head +1) % capacity;
        
        size--;
        return aux;
    }

    public Obj popRight() {
        if(isEmpty()){
            throw new NoSuchElementException();
        }
        int tail = (head + size - 1) % capacity;
        size--;
        return deque[tail];
    }

    public Obj accessLeft() {
        return deque[head];
    }

    public Obj accessRight() {
        int tail = (head + size - 1) % capacity;
        return deque[tail];
    }

    private boolean isFull(){
        if(size == capacity){
            return true;
        }
        return false;
    }

    private boolean isEmpty(){
        if(size == 0){
            return true;
        }
        return false;
    }

    private void resize(){
        
        Obj[] deqAux = new Obj[capacity*2];
        for(int i = 0; i< capacity; i++){
            deqAux[i] = deque[(head + i) % capacity];
        }

        deque = deqAux;
        head = 0;
        capacity = capacity*2;
    }
}
