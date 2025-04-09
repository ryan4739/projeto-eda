#include <iostream>
#include <stdexcept> 
#include <string>   
#include <cassert>
#include "../../../main/stack/cpp/Stack.cpp"

void test_PushLast() {
    Stack stack(9);
    stack.pushLast(1);
    stack.pushLast(2);
    std::string resultado = stack.toString();
    assert(resultado=="2, 1");
    stack.pushLast(3);
    stack.pushLast(4);
    resultado = stack.toString();
    assert(resultado== "4, 3, 2, 1");
   
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
    std::string resultado = stack.toString();
	assert(resultado== "2, 2, 2, 2, 2");
	 try {
         stack.push(2);
    } catch (const std::runtime_error& e) {
         std::cout << "Exception caught: " << e.what() << std::endl;
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
         stack.pop();
    } catch (const std::runtime_error& e) {
         std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    std::cout << "All test cases passed!\n";
}

void test_PopLast() {
    // Usando assert para validar
    Stack stack(5);
    try {
        stack.RemoveFirst();
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    stack.push(3);
    stack.push(4);
    stack.push(6);
    std::string resultado = stack.toString();
    assert(resultado== "3, 4, 6");
    stack.RemoveFirst();
    stack.RemoveFirst();
    resultado = stack.toString();
    assert(resultado=="6");
    std::cout << "All test cases passed!\n";
}

void test_PopIndex(){
    // Usando assert para validar
    Stack stack(5);
    try {
        stack.RemoveIndex(-1);
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    stack.push(3);
    stack.push(4);
    stack.push(6);
    std::string resultado = stack.toString();
    assert(resultado == "3, 4, 6");
    stack.RemoveIndex(2);
    stack.RemoveIndex(0);
    resultado = stack.toString();
    assert(resultado == "4");
    std::cout << "All test cases passed!\n";
}

void test_PeekLast(){
    Stack stack(5);
    try {
        stack.peekLast();
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    stack.PushIndex(3,0);
    stack.PushIndex(4,1);
    std::string resultado = std::to_string(stack.peekLast());
    assert(resultado == "3");
    stack.PushIndex(1,0);
    resultado = std::to_string(stack.peekLast());
    assert(resultado == "1");
    stack.PushIndex(4,2);
    resultado = stack.toString();
    assert(resultado == "1, 2, 4");
    
    std::cout << "All test cases passed!\n";
    }

void test_PushIndex(){
    Stack stack(9);
    stack.PushIndex(2, 0);
    std::string resultado = stack.toString();
    assert(resultado == "2");
    try {
        stack.PushIndex(2,3);
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    stack.PushIndex(3,1);
    stack.PushIndex(3,2);
    try {
        stack.PushIndex(4,-1);
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    resultado = stack.toString();
    assert(resultado == "2, 3, 3");
    stack.PushIndex(1,0);
    stack.PushIndex(4,2);
    resultado = stack.toString();
    assert(resultado == "1, 2, 4");
    
    std::cout << "All test cases passed!\n";
}

void test_peekIndex() {
    // Usando assert para validar
    Stack stack(9);
    try {
        stack.peekIndex(2);
    } catch (const std::runtime_error& e) {
        std:: cout << "Exception caught: " << e.what() << std::endl;
    }
    stack.PushIndex(3,0);
    stack.PushIndex(4,1);
    std::string resultado = std::to_string(stack.peekIndex(1));
    assert(resultado == "4");
    stack.PushIndex(1,1);
    resultado = std::to_string(stack.peekIndex(1));
    assert(resultado == "1");
    stack.PushIndex(4,2);
    resultado = std::to_string(stack.peekIndex(1));
    assert(resultado == "1");
    std::cout << "All test cases passed!\n";
}

void test_peek() {
    // Usando assert para validar
    Stack stack(9);
    try {
        stack.peek();
    } catch (const std::runtime_error& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    stack.push(3);
    stack.push(3);
    std::string resultado = std::to_string(stack.peek());
    assert(resultado == "3");
    stack.push(4);
    resultado = std::to_string(stack.peek());
    assert(resultado == "4");
    std::cout << "All test cases passed!\n";
}

void test_IndeOf() {
    // Usando assert para validar
    Stack stack(9);
    try {
        stack.indexOf(2);
    } catch (const std::runtime_error& e){
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    stack.push(2);
    std::string resultado = std::to_string(stack.indexOf(2));
    assert(resultado == "0");
    stack.push(0);
    stack.push(1);
    stack.push(3);
    resultado = std::to_string(stack.indexOf(0));
    assert(resultado == "1");
    resultado = std::to_string(stack.indexOf(7));
    assert(resultado == "-1");
    
    std::cout << "All test cases passed!\n";
}

int main2(){
    test_PushIndex();
    test_Pop();
    test_peekIndex;
    test_PopIndex();
    test_PushLast();
    test_peek();
    test_IndeOf();
    return 0;
}
