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
        void direita(int valor, int index){
            this-> tail+=1;
            if(isFull()){
                throw std::runtime_error("Não deu");
            }
            if(index>=count){
                throw std::runtime_error("Não deu");
            }
            for(int i =0; i<=index; i++){
              array[i-1] = array[i];
            }
            array[index]= valor;
        }
        void esquerda(int valor){
            if(isFull()){
                throw std::runtime_error("Não deu");
            }
            if(valor>=count){
                throw std::runtime_error("Não deu");
            }
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
            for(int i =0; i<=tail+1;i++){
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
        int peekValorPrimeiro(int valor){
            int numero = -1;
            for(int i =0;i<tail;i++){
                if(!(numero==-1)){
                    return numero;
                }
                if(valor==array[i]){
                    numero=i;
                }
            }
            return numero;
        }
        int peekValorUltimo(int valor){
            int numero = -1;
            for(int i =tail;i>0;i--){
                if(!(numero==-1)){
                    return numero;
                }
                if(valor==array[i]){
                    numero=i;
                }
            }
            return numero;
        }
        int peek(int valor){
            if(tail<valor){
                throw std::runtime_error("Não deu");
            }
            return array[valor];
        }
        void push(int valor){
            if(isFull()){
                throw std::runtime_error("Não deu");
            }
            this ->  tail+=1;
            array[tail]= valor;
        }
        void PushIndex(int valor, int index){
            direita(valor, index);
        }
        void RemoveFirst(){
            esquerda(0);
        }
        void RemoveValor(){
            esquerda(tail);
        }
        void RemoveIndex(int index){
            esquerda(index);
        }
        int size(){
            return tail+1;
        }
        bool isFull(){
            if(this->tail+1 >= count){
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
    stacks.PushIndex(6,4);
    stacks.PushIndex(6,3);
    stacks.PushIndex(6,2);
    stacks.PushIndex(6,1);
    stacks.RemoveIndex(4);
    stacks.toString();
    std::cout << stacks.peekValorPrimeiro(6);
    return 0;
}
