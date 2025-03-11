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

}

int main() {
    testQueue();
    std::cout << "Todos os testes passaram!\n";
    return 0;
}
