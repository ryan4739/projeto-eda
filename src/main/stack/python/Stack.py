class Stack:
    def __init__(self, capacidade):
        if capacidade <= 0:
            raise ValueError("Capacidade deve ser maior que zero")
        self.array = [0] * capacidade
        self.tail = -1
        self.capacidade = capacidade

    def isEmpty(self):
        return self.tail < 0

    def isFull(self):
        return self.tail + 1 == self.capacidade

    def push(self, valor):
        if self.isFull():
            raise OverflowError("A pilha está cheia")
        self.tail += 1
        self.array[self.tail] = valor

    def pop(self):
        if self.isEmpty():
            raise IndexError("A pilha está vazia")
        valor = self.array[self.tail]
        self.tail -= 1
        return valor

    def peek(self):
        if self.isEmpty():
            raise IndexError("A pilha está vazia")
        return self.array[self.tail]

    def peekFirst(self):
        if self.isEmpty():
            raise IndexError("A pilha está vazia")
        return self.array[0]

    def peekIndex(self, index):
        if index < 0 or index > self.tail:
            raise IndexError("Índice inválido")
        return self.array[index]

    def indexOf(self, valor):
        for i in range(self.tail + 1):
            if self.array[i] == valor:
                return i
        return -1

    def direita(self, index):
        """Move elementos para a direita para abrir espaço em `index`."""
        if self.isFull():
            raise OverflowError("A pilha está cheia")
        for i in range(self.tail, index - 1, -1):
            self.array[i + 1] = self.array[i]
        self.tail += 1

    def esquerda(self, index):
        """Move elementos para a esquerda para remover item em `index`."""
        for i in range(index, self.tail):
            self.array[i] = self.array[i + 1]
        self.tail -= 1

    def pushIndex(self, valor, index):
        if index < 0 or index > self.tail + 1:
            raise IndexError("Índice inválido")
        self.direita(index)
        self.array[index] = valor

    def removeIndex(self, index):
        if self.isEmpty() or index < 0 or index > self.tail:
            raise IndexError("Índice inválido")
        self.esquerda(index)

    def pushLast(self, valor):
        self.pushIndex(valor, 0)

    def popLast(self):
        if self.isEmpty():
            raise IndexError("A pilha está vazia")
        valor = self.array[0]
        self.esquerda(0)
        return valor

    def size(self):
        return self.tail + 1

    def toString(self):
        return ", ".join(str(self.array[i]) for i in range(self.tail + 1)) if not self.isEmpty() else "Pilha vazia"
