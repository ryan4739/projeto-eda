#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdexcept>

class ArrayList {
public:
    explicit ArrayList(size_t capacidadeInicial = 20);
    ~ArrayList();

    bool isEmpty() const;
    size_t getSize() const;
    bool contains(int value) const;

    bool addLast(int value);
    bool addFirst(int value);
    bool addIndex(int value, size_t index);

    bool rmvLast();
    bool rmvFirst();
    bool rmvIndex(size_t index);

    int get(size_t index) const;

private:
    int* data;
    size_t capacity;
    size_t size;

    void testeTamanho();
    void shiftDireita(size_t index);
    void shiftEsquerda(size_t index);
};

#endif // ARRAYLIST_H
