#include <iostream>
#include <stdexcept>
#include "ArrayList.h"

void ArrayList::resize() {
    capacity *= 2;
    int* newData = new int[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

void ArrayList::shiftDireita(int index) {
    testeTamanho();
    for (int i = ++size; i > index; i--) {
        data[i] = data[i - 1];
    }
}

void ArrayList::shiftEsquerda(int index) {
    testeRmv();
    if(index == 0){
	rmvLast();
    }
    else{
    	for (int i = index; i < --size; i++) {
        	data[i] = data[i + 1];
	}
    }
}

bool ArrayList::isEmpty() {
    return size == -1;
}

bool ArrayList::isFull() {
    return size == capacity-1;
}

void ArrayList::testeTamanho() {
    if (isFull())
        resize();
}

void ArrayList::testeRmv() {
    if (isEmpty())
        throw std::out_of_range("Lista vazia");
}

ArrayList::ArrayList(size_t initialCapacity) : capacity(initialCapacity), size(0) {
    data = new int[capacity];
}

ArrayList::ArrayList() : capacity(20), size(-1) {
    data = new int[capacity];
}

ArrayList::~ArrayList() {
    delete[] data;
}

bool ArrayList::addLast(int value) {
    data[++size] = value;
    return true;
}

bool ArrayList::addFirst(int value) {
    shiftDireita(0);
    data[0] = value;
    return true;
}

bool ArrayList::addIndex(int value, int index) {
    shiftDireita(index);
    data[index] = value;
    return true;
}

bool ArrayList::contains(int value) {
    if (isEmpty()) {
        return false;
    }
    for (int i = 0; i <= size; i++) {
        if (data[i] == value)
            return true;
    }
    return false;
}

bool ArrayList::rmvLast() {
    testeRmv();
    --size;
    return true;
}

bool ArrayList::rmvFirst() {
    shiftEsquerda(0);
    return true;
}

bool ArrayList::rmvIndex(int index) {
    shiftEsquerda(index);
    return true;
}

int ArrayList::getSize() const {
    return size;
}
