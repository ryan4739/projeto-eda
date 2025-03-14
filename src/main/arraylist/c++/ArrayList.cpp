// a maior diferença entre a implementação em C++ e a implementação em java é que
// vamos precisar liberar a alocação de memória, diferente em java que temos o 
// Garbage Collector fazendo esse trabalho para gente durante o resize().
#include <iostream>
#include <stdexcept> // Para o uso de exceções
#include "ArrayList.h"

// Implementação como arquivo de objeto
// Implementação do método resize
void ArrayList::resize() {
    capacity *= 2;
    int* newData = new int[capacity];
    for (size_t i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data; // Liberação da memória que não estamos utilizando mais
    data = newData;
}

// Implementação do método shiftDireita
void ArrayList::shiftDireita(size_t index) {
    testeTamanho();
    for (size_t i = ++size; i > index; i--) {
        data[i] = data[i - 1];
    }
}

// Implementação do método shiftEsquerda
void ArrayList::shiftEsquerda(size_t index) {
    testeRmv();
    for (size_t i = index; i < --size; i++) {
        data[i] = data[i + 1];
    }
}

// Implementação do método isEmpty
bool ArrayList::isEmpty() {
    return size == -1;
}

// Implementação do método isFull
bool ArrayList::isFull() {
    return size == capacity;
}

// Implementação do método testeTamanho
void ArrayList::testeTamanho() {
    if (isFull())
        resize();
}

// Implementação do método testeRmv
void ArrayList::testeRmv() {
    if (isEmpty())
        throw std::out_of_range("Lista vazia");
}

// Implementação do construtor com capacidade inicial
ArrayList::ArrayList(size_t initialCapacity) : capacity(initialCapacity), size(0) {
    data = new int[capacity];
}

// Implementação do construtor padrão
ArrayList::ArrayList() : capacity(20), size(-1) {
    data = new int[capacity];
}

// Implementação do destrutor
ArrayList::~ArrayList() {
    delete[] data;
}

// Implementação do método addLast
bool ArrayList::addLast(int value) {
    data[++size] = value;
    return true;
}

// Implementação do método addFirst
bool ArrayList::addFirst(int value) {
    shiftDireita(0);
    data[0] = value;
    return true;
}

// Implementação do método addIndex
bool ArrayList::addIndex(int value, size_t index) {
    shiftDireita(index);
    data[index] = value;
    return true;
}

// Implementação do método contains
bool ArrayList::contains(int value) {
    if (isEmpty()) {
        return false;
    }
    for (size_t i = 0; i <= size; i++) {
        if (data[i] == value)
            return true;
    }
    return false;
}

// Implementação do método rmvLast
bool ArrayList::rmvLast() {
    testeRmv();
    size--;
    return true;
}

// Implementação do método rmvFirst
bool ArrayList::rmvFirst() {
    shiftEsquerda(0);
    return true;
}

// Implementação do método rmvIndex
bool ArrayList::rmvIndex(size_t index) {
    shiftEsquerda(index);
    return true;
}

size_t ArrayList::getSize() const{
	return size;
}

/* Implementação Padrão
class ArrayList{
private: 
	int* data;
	size_t capacity;	//size_t funciona como um int, mas ele sempre será positivo
				//evitando problemas com indice negativo 
	size_t size;	

	void resize(){
		capacity *= 2;
		int* newData = new int[capacity];
		for(size_t i = 0; i < size; i++){
			newData[i] = data[i];
		}
		delete[] data; 	//aqui fazemos a liberação da memória que não estamos utilizando mais
		data = newData;
	}

	void shiftDireita(size_t index){
		testeTamanho();
		for(size_t i = ++size; i > index; i--){
			data[i] = data[i-1];
		}
	}

	void shiftEsquerda(size_t index){
		testeRmv();
		for(size_t i = index; i < size--; i++){
			data[i] = data[i+1];
		}
	}

	bool isEmpty(){
		return size == -1;
	}

	bool isFull(){
		return size == capacity;
	}

	void testeTamanho(){
		if(isFull())
			resize();
	}

	void testeRmv(){
		if(isEmpty())
			throw std::out_of_range("Lista vazia");
	}
public:
	//construtor com capacidade passada pelo usuário
	ArrayList(size_t initialCapacity) : capacity(initialCapacity), size(0){
		data = new int[capacity];
	}
	
	//construtor padrão
	ArrayList() : capacity(20), size(-1){
		data = new int[capacity];
	}

	//destrutor para liberar memória
	~ArrayList(){
		delete[] data;
	}

	bool addLast(int value){
		data[++size] = value;
		return true;
	}

	bool addFirst(int value){
		shiftDireita(0);
		data[0] = value;
	        return true;	
	}

	bool addIndex(int value, size_t index){
		shiftDireita(index);
		data[index] = value;
		return true;
	}

	bool contains(int value){
		if(isEmpty()){
			return false;
		}
		for(size_t i = 0; i <= size; i++){
			if(data[i] == value)
				return true;
		}
		return false;
	}

	bool rmvLast(){
		testeRmv();
		size--;
		return true;
	}

	bool rmvFirst(){
		shiftEsquerda(0);
		return true;
	}

	bool rmvIndex(size_t index){
		shiftEsquerda(index);
		return true;
	}

}
*/
