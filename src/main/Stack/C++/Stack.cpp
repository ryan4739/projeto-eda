/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <stdexcept>
class Stack {       // The class
    private:
        int tail =-1;  // Attribute (int variable)
        int count =-1;
        int* array;// Attribute (string variable)
    public:   // Access specifier
        Stack(int capacidade){
            if(capacidade<=0){
                throw std::runtime_error("Não deu");
        }
            array = new int[capacidade];
            this-> count = capacidade;
        }
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
            if(tail<0){
                throw std::runtime_error("Não deu");
            }
            int V = array[tail];
            this -> tail--;
            return tail;
        }
        int indexOf(int valor){
            if(tail<0){
                throw std::runtime_error("Não deu");
            }
            for(int i=0;i<size(); i++){
                if(array[i]==valor){
                    return i;
                }
            }
            return -1;
        }
        void toString(){
            int numero = tail;
            std::string stringaro = "";
            for(int i =0; i<count;i++){
                if(isEmpty()){
                  stringaro+=", ";
                }
                stringaro+= std::__cxx11::to_string(array[i]);
                this ->  tail+=-1;
                if(!(isEmpty())){
                  stringaro+=", ";
                }
                
            }
            tail+=numero;
            std::cout << stringaro;
        }
        int peek(int valor){
            return array[valor];
        }
        void push(int valor){
            if(isFull()){
                throw std::runtime_error("Não deu");
            }
            this ->  tail+=1;
            array[tail]= valor;
        }
        void PushIndex(int valor){
            direita(valor);
            array;
        }
        int size(){
            return tail+1;
        }
        bool isFull(){
            if(this->tail+1 == count){
                return true;
            }
            return false;
        }
        void gettail(){
            std::cout <<tail;
            std::cout <<sizeof(array);
            std::cout <<sizeof(array[0]);
            std::cout << count;
        }
        bool isEmpty(){
            if(tail<0){
                return true;
            }
            return false;
        }
};

int main()
{
    Stack stacks(7);
    stacks.push(1);
    stacks.push(2);
    stacks.push(3);
    stacks.push(4);
    stacks.push(5);
    stacks.push(6);
    stacks.push(7);
    stacks.pop();
    stacks.toString();
    return 0;
}
