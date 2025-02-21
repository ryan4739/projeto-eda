/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

class Stack {       // The class
  public:             // Access specifier
    int tail =-1;        // Attribute (int variable)
    int[] array;// Attribute (string variable)
    void direita(){
        
    }
    void esquerda(){
        
    }
    int pop(){
        V = array[tail];
        tail--;
        return tail;
    }
    int indexOf(valor){
        
    }
    string toString(){
        
    }
    int peek(valor){
        return array[valor];
    }
    void push(valor){
        tail+=1;
        array[tail]= valor;
    }
    void PushIndex(){
        
    }
    int size(){
        return tail+1;
    }
    boolean isFull(){
        if((tail+1)== sizeof(array)){
            return true;
        }
        return false;
    }
    boolean isEmpty(){
        if(tail<0){
            return true;
        return false
        }
    }
};

int main()
{
    string array[0];

    return 0;
}
