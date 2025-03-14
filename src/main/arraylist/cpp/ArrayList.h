#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdexcept>

class ArrayList {
private:
    int* data;
    size_t capacity;
    size_t size;

    void resize();
    void shiftDireita(size_t index);
    void shiftEsquerda(size_t index);
    void testeTamanho();
    void testeRmv();

public:
    ArrayList(size_t initialCapacity);
    ArrayList();
    ~ArrayList();
    bool addLast(int value);
    bool addFirst(int value);
    bool addIndex(int value, size_t index);
    bool contains(int value);
    bool rmvLast();
    bool rmvFirst();
    bool rmvIndex(size_t index);
    bool isEmpty();
    bool isFull();
    int getSize() const;
};

#endif // ARRAYLIST_H
