#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdexcept>

class ArrayList {
private:
    int* data;
    int capacity;
    int size;

    void resize();
    void shiftDireita(int index);
    void shiftEsquerda(int index);
    void testeTamanho();
    void testeRmv();

public:
    ArrayList(size_t initialCapacity);
    ArrayList();
    ~ArrayList();
    bool addLast(int value);
    bool addFirst(int value);
    bool addIndex(int value, int index);
    bool contains(int value);
    bool rmvLast();
    bool rmvFirst();
    bool rmvIndex(int index);
    bool isEmpty();
    bool isFull();
    int getSize() const;
};

#endif // ARRAYLIST_H
