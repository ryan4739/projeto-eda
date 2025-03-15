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
        bool isFull(){
            if(this->tail+1 >= count){
                return true;
            }
            return false;
        }
        bool isEmpty(){
            if(tail<0){
                return true;
            }
            return false;
        }
        void direita(int valor, int index){
            this-> tail+=1;
            if(isFull()){
                throw std::runtime_error("Não deu");
            }
            if(index>count){
                throw std::runtime_error("Não deu");
            }
            for(int i=index; i<tail; i++){
              array[i-1] = array[i];
            }
            array[index]= valor;
        }
        void esquerda(int valor){
            if(isEmpty()){
                throw std::runtime_error("Não deu");
            }
            if(valor>count){
                throw std::runtime_error("Não deu");
            }
            
            for(int i =valor; i<tail; i++){
              array[i+1] = array[i];
            }
            this-> tail+=-1;
        }
        int pop(){
            if(isEmpty()){
                throw std::runtime_error("Não deu");
            }
            int V = array[tail];
            this -> tail--;
            return tail;
        }
        int indexOf(int valor){
            if(isEmpty()){
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
            for(int i =0; i<=numero;i++){
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
        int peekIndex(int valor){
            if(tail<valor|| isEmpty() || valor<0){
                throw std::runtime_error("Não deu");
            }
            return array[valor];
        }
        int peekLast(){
            if(isEmpty()){
                throw std::runtime_error("Não deu");
            }
            return array[0];
        }
        int peek(){
            if(isEmpty()){
                throw std::runtime_error("Não deu");
            }
            return array[tail];
        }
        void push(int valor){
            if(isFull()){
                throw std::runtime_error("Não deu");
            }
            this ->  tail+=1;
            array[tail]= valor;
        }
        void pushLast(int valor){
            direita(valor, 0);
		}
        void PushIndex(int valor, int index){
            direita(valor, index);
        }
        void RemoveFirst(){
            esquerda(0);
        }
        void RemoveValor(int valor){
        for(int i=0; i<tail;i++){
            if(array[i]==valor){
                esquerda(i);
            }
        }
        }
        void RemoveIndex(int index){
            esquerda(index);
        }
        int size(){
            return tail+1;
        }
        void gettail(){
            std::cout <<tail;
            std::cout <<sizeof(array);
            std::cout <<sizeof(array[0]);
            std::cout << count;
        }
};

int main()
{
    Stack stacks(7);
    stacks.PushIndex(6,5);
    stacks.PushIndex(6,4);
    stacks.PushIndex(6,3);
    stacks.toString();
    return 0;
}
