#include <iostream>
#include <cassert>

void test_PushLast() {
    Stack stack(9);
    stack.pushLast(1);
    stack.pushLast(2);
    assert(stack.toString() == "2, 1");
    stack.pushLast(3);
    stack.pushLast(4);
    assert(stack.toString() == "4, 3, 2, 1");

    std::cout << "All test cases passed!\n";
}

void test_push() {
    Stack stack(5);
    stack.push(2);
    stack.push(2);
    stack.push(2);
    stack.push(2);
    stack.push(2);
    assert(stack.toString() == "2, 2, 2, 2, 2");
    
    try {
        std::cout << "Result: " << stack.push(4) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "All test cases passed!\n";
}

void test_Pop() {
    Stack stack(3);
    stack.push(2);
    stack.push(2);
    stack.push(2);
    stack.pop();
    stack.pop();
    stack.pop();

    try {
        std::cout << "Result: " << stack.pop() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "All test cases passed!\n";
}

void test_PopLast() {
    Stack stack(5);

    try {
        std::cout << "Result: " << stack.popLast() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    stack.push(3);
    stack.push(4);
    stack.push(6);
    assert(stack.toString() == "3, 4, 6");
    
    stack.popLast();
    stack.popLast();
    assert(stack.toString() == "6");

    std::cout << "All test cases passed!\n";
}

void test_PopIndex() {
    Stack stack(5);

    try {
        std::cout << "Result: " << stack.popIndex(0) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    stack.push(3);
    stack.push(4);
    stack.push(6);
    assert(stack.toString() == "3, 4, 6");

    stack.popIndex(2);
    stack.popIndex(0);
    assert(stack.toString() == "4");

    std::cout << "All test cases passed!\n";
}

void test_PeekLast() {
    Stack stack(5);

    try {
        std::cout << "Result: " << stack.peekLast() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    stack.PushIndex(3, 0);
    stack.PushIndex(4, 1);
    assert(stack.peekLast() == 3);
    stack.PushIndex(1, 0);
    assert(stack.peekLast() == 1);
    stack.PushIndex(4, 2);
    assert(stack.toString() == "1, 2, 4");

    std::cout << "All test cases passed!\n";
}

void test_PushIndex() {
    Stack stack(9);
    stack.PushIndex(2, 0);
    assert(stack.toString() == "2");

    try {
        std::cout << "Result: " << stack.PushIndex(2, 3) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    stack.PushIndex(3, 1);
    stack.PushIndex(3, 2);

    try {
        std::cout << "Result: " << stack.PushIndex(4, -1) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    assert(stack.toString() == "2, 3, 3");
    stack.PushIndex(1, 0);
    stack.PushIndex(4, 2);
    assert(stack.toString() == "1, 2, 4");

    std::cout << "All test cases passed!\n";
}

void test_peek() {
    Stack stack(9);

    try {
        std::cout << "Result: " << stack.peek() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    stack.push(3);
    stack.push(3);
    assert(stack.peek() == 3);
    stack.push(4);
    assert(stack.peek() == 4);

    std::cout << "All test cases passed!\n";
}

void test_IndexOf() {
    Stack stack(9);

    try {
        std::cout << "Result: " << stack.indexOf(2) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    stack.push(2);
    assert(stack.indexOf(2) == 0);
    stack.push(0);
    stack.push(1);
    stack.push(3);
    assert(stack.indexOf(0) == 1);
    assert(stack.indexOf(7) == -1);

    std::cout << "All test cases passed!\n";
}

int main() {
    test_PushIndex();
    test_Pop();
    test_peek();
    test_PopIndex();
    test_PushLast();
    test_IndexOf();

    return 0;
}
