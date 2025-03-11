using namespace std;

class MyDeque {
  private:
    int *deque;
    int head, size, capacity;

  public:

    MyDeque(int c) {
        deque = new int[c];
        capacity = c;
        size = 0;
        head = 0;
    }


    int popLeft() {
        if (isEmpty()){
            return -1;
        }
        int aux = deque[head];
        head = (head + 1) % capacity;
        size--;
        return aux;
    }

    int popRight() {
        if (isEmpty()){
            return -1;
        }
        int tail = (head + size - 1) % capacity;
        size--;
        return deque[tail];
    }


    void appendLeft(int x) {
        if (!isFull()){
            head = (head - 1 + capacity) % capacity;
            deque[head] = x;
            size++;
        }
    }

    void appendRight(int x) {
        if (!isFull()){
            int tail = (head + size) % capacity;
            deque[tail] = x;
            size++;
        }
    }
 
    int peekLeft() {
        return deque[head];
    }
 
    int peekRight() { 
        int tail = (head + size - 1) % capacity;
        return deque[tail];
    }

    private:
    bool isFull(){
        if(size == capacity){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(size == 0){
            return true;
        }
        return false;
    }
};
