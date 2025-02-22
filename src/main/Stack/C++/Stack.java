/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
class Stack {       // The class
  private:
     int tail =-1;        // Attribute (int variable)
    int[] array;// Attribute (string variable)
  public:             // Access specifier
    void direita(int valor){
        for(int i =valor; i<tail; i++){
          array[i-1] = array[i];
        }
    }
    void esquerda(int valor){
        for(int i =valor; i<tail; i++){
          array[i+1] = array[i];
        }
    }
    int pop(){
        V = array[tail];
        tail--;
        return tail;
    }
    int indexOf(int valor){
        
    }
    void toString(){
        int numero = tail;
        string stringaro = "";
        for(int i =0; i<numero;i++){
            stringaro+=array[i];
            tail+=-1
            if(!isEmpty()){
              stringaro+=", ";
            }
        }
        tail+=numero;
        return stringaro;
    }
    int peek(int valor){
        return array[valor];
    }
    void push(int valor){
        tail+=1;
        array[tail]= valor;
    }
    void PushIndex(int valor){
        direita(valor);
      array
    }
    int size(){
        return tail+1;
    }
    bool isFull(){
        if((tail+1)== sizeof(array)){
            return true;
        }
        return false;
    }
    bool isEmpty(){
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
