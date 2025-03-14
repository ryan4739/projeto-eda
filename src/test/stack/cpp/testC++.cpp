#include <iostream>
#include <cassert>

void test_PushLast() {
    Stack stack(9);
    stack.pushLast(1);
    stack.pushLast(2);
    assert(stack.toString(), "2, 1");
    stack.pushLast(3);
    stack.pushLast(4);
    assert(stack.toString(), "4, 3, 2, 1");
   
    std::cout << "All test cases passed!\n";
}

void test_push() {
    // Usando assert para validar
    Stack stack(5);
	stack.push(2);
	stack.push(2);
	stack.push(2);
	stack.push(2);
	stack.push(2);
	assert(stack.toString(), "2, 2, 2, 2, 2");
	 try {
        cout << "Result: " << stack.push(4) << endl;
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    std::cout << "All test cases passed!\n";
}

void test_Pop() {
    // Usando assert para validar
    Stack stack(3);
    stack.push(2);
	stack.push(2);
	stack.push(2);
	stack.pop();
	stack.pop();
	stack.pop();
	 try {
        cout << "Result: " << stack.pop(); << endl;
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    
    std::cout << "All test cases passed!\n";
}

void test_PopLast() {
    // Usando assert para validar
    Stack stack(5);
    try {
        cout << "Result: " << stack.RemoveFirst() << endl;
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    stack.push(3);
    stack.push(4);
    stack.push(6);
    assert(stack.toString(), "3, 4, 6");
    stack.RemoveFirst();
    stack.RemoveFirst();
    assert(stack.toString(), "6");
    std::cout << "All test cases passed!\n";
}

void test_PopIndex() {
    // Usando assert para validar
    Stack stack(5);
    try {
        cout << "Result: " << stack.RemoveIndex() << endl;
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    stack.push(3);
    stack.push(4);
    stack.push(6);
    assert(stack.toString(), "3, 4, 6");
    stack.RemoveIndex(2);
    stack.RemoveIndex(0);
    assert(stack.toString(), "4");
    std::cout << "All test cases passed!\n";
}

void test_PeekLast() {
    // Usando assert para validar
    Stack stack(5);
    try {
        cout << "Result: " << stack.peekLast() << endl;
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    PushIndex(3,0);
    PushIndex(4,1);
    assert(stack.peekLast(), "3");
    PushIndex(1,0);
    assert(stack.peekLast(), "1");
    PushIndex(4,2);
    assert(stack.toString(), "1, 2, 4"
    
    std::cout << "All test cases passed!\n";
}

void test_PushIndex(){
    Stack stack(9);
    stack.PushIndex(2, 0);
    assert(stack.toString(), "2");
    try {
        cout << "Result: " << stack.PushIndex(2,3) << endl;
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    stack.PushIndex(3,1);
    stack.PushIndex(3,2);
    try {
        cout << "Result: " << stack.PushIndex(4,-1) << endl;
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    assert(stack.toString(), "2, 3, 3");
    stack.PushIndex(1,0);
    stack.PushIndex(4,2);
    assert(stack.toString(), "1, 2, 4";
    
    std::cout << "All test cases passed!\n";
}

void test_peekIndex() {
    // Usando assert para validar
    Stack stack(9);
    try {
        cout << "Result: " << stack.peekIndex(2,3) << endl;
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    stack.PushIndex(3,0);
    stack.PushIndex(4,1);
    assert(stack.peekIndex(1), "4");
    stack.PushIndex(1,1);
    assert(stack.peekIndex(1), "1");
    stack.PushIndex(4,2);
    assert(stack.peekIndex(2), "1");
    std::cout << "All test cases passed!\n";
}

void test_peek() {
    // Usando assert para validar
    Stack stack(9);
    try {
        cout << "Result: " << stack.peeK() << endl;
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    stack.push(3);
    stack.push(3);
    assert(stack.peek(), "3");
    stack.push(4);
    assert(stack.peek(), "4");
    std::cout << "All test cases passed!\n";
}

void test_IndeOf() {
    // Usando assert para validar
    Stack stack(9);
    try {
        cout << "Result: " << stack.indexOf(2) << endl;
    } catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    stack.push(2);
    assert(stack.indexOf(2), "0");
    stack.push(0);
    stack.push(1);
    stack.push(3);
    assert(stack.indexOf(0), "1");
    assert(stack.indexOf(7), "-1");
    
    std::cout << "All test cases passed!\n";
}

int main() {
    test_PushIndex();
    test_Pop();
    test_peekIndex;
    test_PopIndex();
    test_PushLast();
    test_peek();
    test_IndeOf();
    return 0;
}
