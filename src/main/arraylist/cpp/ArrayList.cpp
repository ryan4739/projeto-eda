#include "ArrayList.h"
#include <algorithm>  // std::copy

ArrayList::ArrayList(size_t capacidadeInicial)
    : data(new int[capacidadeInicial]), capacity(capacidadeInicial), size(0) {}

ArrayList::~ArrayList() {
    delete[] data;
}

bool ArrayList::isEmpty() const {
    return size == 0;
}

size_t ArrayList::getSize() const {
    return size;
}

bool ArrayList::contains(int value) const {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == value) return true;
    }
    return false;
}

void ArrayList::testeTamanho() {
    if (size < capacity) return;
    size_t novaCap = capacity * 2;
    int* novoData = new int[novaCap];
    std::copy(data, data + size, novoData);
    delete[] data;
    data = novoData;
    capacity = novaCap;
}

void ArrayList::shiftDireita(size_t index) {
    for (size_t i = size; i > index; --i) {
        data[i] = data[i - 1];
    }
}

void ArrayList::shiftEsquerda(size_t index) {
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
}

bool ArrayList::addLast(int value) {
    testeTamanho();
    data[size++] = value;
    return true;
}

bool ArrayList::addFirst(int value) {
    return addIndex(value, 0);
}

bool ArrayList::addIndex(int value, size_t index) {
    if (index > size) {
        throw std::out_of_range("Índice fora do intervalo");
    }
    testeTamanho();
    shiftDireita(index);
    data[index] = value;
    ++size;
    return true;
}

bool ArrayList::rmvLast() {
    if (isEmpty()) return false;
    --size;
    return true;
}

bool ArrayList::rmvFirst() {
    return rmvIndex(0);
}

bool ArrayList::rmvIndex(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Índice fora do intervalo");
    }
    shiftEsquerda(index);
    --size;
    return true;
}

int ArrayList::get(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Índice fora do intervalo");
    }
    return data[index];
}


