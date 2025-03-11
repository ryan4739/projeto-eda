#include <iostream>
#include <cassert>
#include "../../../main/queue/cpp/queue.cpp"

void testQueue() {
   
    // Queue
    Queue<int> q(5);
    assert(q.isEmpty());
    assert(q.getSize() == 0);

    // addLast
    q.addLast(10);
    q.addLast(20);
    q.addLast(30);
    assert(q.getSize() == 3);
    assert(q.getFirst() == 10);
    assert(q.getLast() == 30);

    // addFirst
    q.addFirst(5);
    assert(q.getSize() == 4);
    assert(q.getFirst() == 5);
    assert(q.getLast() == 30);
    
    // add
    q.add(40, 2);
    assert(q.getSize() == 5);
    assert(q.getFirst() == 5);
    assert(q.getLast() == 30);
    q.add(70, 0);
    assert(q.getSize() == 6);
    assert(q.getFirst() == 70);
    assert(q.getLast() == 30);
    q.add(90, 6);
    assert(q.getSize() == 7);
    assert(q.getFirst() == 70);
    assert(q.getLast() == 90);
    
    // removeFirst
    assert(q.removeFirst() == 5);
    assert(q.getSize() == 4);
    assert(q.getFirst() == 10);
    
    // removeLast
    assert(q.removeLast() == 40);
    assert(q.getSize() == 3);
    assert(q.getLast() == 30);
    
    // remove
    assert(q.remove(0) == 10);
    assert(q.getSize() == 2);
    assert(q.getFirst() == 20);
    assert(q.remove(1) == 30);
    assert(q.getSize() == 1);
    assert(q.getFirst() == 20);
    q.addFirst(120);
    q.addFirst(130);
    q.addFirst(140);
    assert(q.remove(1) == 130);
    assert(q.getSize() == 3);
    assert(q.getFirst() == 140);
    
    // getFirst
    assert(q.getFirst() == 20);
    
    // getLast
    assert(q.getLast() == 30);
    
    // get
    assert(q.get(0) == 20);
    assert(q.get(1) == 30);
    
    // indexOf
    assert(q.indexOf(20) == 0);
    assert(q.indexOf(30) == 1);
    assert(q.indexOf(40) == -1);
    
    // lastIndexOf
    q.addLast(20);
    assert(q.lastIndexOf(20) == 2);
    
    // size
    assert(q.getSize() == 3);
    
    // isEmpty
    assert(!q.isEmpty());
    
    // isFull
    assert(!q.isFull());

}

int main() {
    testQueue();
    std::cout << "Todos os testes passaram!\n";
    return 0;
}
